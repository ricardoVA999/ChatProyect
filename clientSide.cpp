/*
    Amado Garcia        181469
    Ricardo Valenzuela  18762
    Sara Zavala         18893
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ifaddrs.h>
#include "payload.pb.h"
#include <queue>

int connected, waitingForServerResponse, waitingForInput;
std::queue<std::string> msgQueue;
std::string statusArray[3] = {"ACTIVO", "OCUPADO", "INACTIVO"};


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in *)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

void *listenToMessages(void *args)
{
	while (1)
	{
		char bufferMsg[8192];
		int *sockmsg = (int *)args;
		chat::Payload serverMsg;

		// recibir response de servidor
		int bytesReceived = recv(*sockmsg, bufferMsg, 8192, 0);

		// Parsear mensaje de servidor
		serverMsg.ParseFromString(bufferMsg);

		if (serverMsg.code() == 500)
		{
			printf("________________________________________________________\n");
			std::cout << "Error: "
			  << serverMsg.message()
			  << std::endl;
		}
		else if (serverMsg.code() == 200)
		{
			printf("________________________________________________________\n");
			std::cout << "Respuesta del servidor: \n"
			  << serverMsg.message()
			  << std::endl;
		}
		else
		{
			// error: respuesta no reconocida
			printf("El servidor no esta disponible, intentelo mas tarde\n");
			break;
		}

		while (!waitingForInput && !msgQueue.empty())
		{
			printf("%s\n", msgQueue.front().c_str());
			msgQueue.pop();
		}

		// notificar a main thread que ya puede seguir
		waitingForServerResponse = 0;

		if (connected == 0)
		{
			pthread_exit(0);
		}
	}
}

void print_menu(char *usrname)
{
	printf("________________________________________________________ \n");
	printf("Bienvenido al lobby, %s. \n", usrname);
	printf("1. Obtener lista de usuarios conectados. \n");
	printf("2. Desplegar informacion de un usuario. \n");
	printf("3. Cambiar status. \n");
	printf("4. Enviar un mensaje a todos los usuarios. \n");
	printf("5. Enviar mensaje directo. \n");
	printf("6. Ayuda. \n");
	printf("7. Salir. \n");
	printf("________________________________________________________ \n");
}

void help_menu() {
	printf("________________________________________________________ \n");
	printf("AYUDA \n");
	printf("Obtener lista de usuarios conectados: Imprime todos los usuarios conectados actualmente a la sesion y su respectiva informacion\n");
	printf("Desplegar informacion de un usuario.: Imprime los datos del usuario especificado. \n");
	printf("Cambiar status: Permite cambiar el estado del usuario, los estados disponibles son activo, inactivo y ocupado. \n");
	printf("Enviar un mensaje a todos los usuarios: Se envia un mensaje a todos los usuarios conectados en la sesion. \n");
	printf("Enviar mensaje directo: Envia un mensaje por privado a un usuario conectado actualmente a la sesion. \n");
	printf("Ayuda: Se le despliega al usuario un menu de ayuda. \n");
	printf("Salir: Permite que el usuario salga del sistema y cerrar conexion con el servidor. \n");
	printf("________________________________________________________ \n");
}

int get_client_option()
{
	// Client options
	int client_opt;
	std::cin >> client_opt;

	while (std::cin.fail())
	{
		std::cout << "Por favor, ingrese una opcion valida: " << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> client_opt;
	}

	return client_opt;
}

int main(int argc, char *argv[])
{
	int sockfd, numbytes;
	char buf[8192];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	char *usrname;

	if (argc != 4)
	{
		fprintf(stderr, "usage: client <username> <server_ip> <server_port>\n");
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[2], argv[3], &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for (p = servinfo; p != NULL; p = p->ai_next)
	{
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
							 p->ai_protocol)) == -1)
		{
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
		{
			perror("client: connect");
			close(sockfd);
			continue;
		}

		break;
	}

	if (p == NULL)
	{
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			  s, sizeof s);
	printf("Cliente: conectado con %s\n", s);
	freeaddrinfo(servinfo); // all done with this structure

	// escribir mensaje
	char buffer[8192];
	std::string message_serialized;

	chat::Payload *firstMessage = new chat::Payload;

	firstMessage->set_sender(argv[1]);
	firstMessage->set_flag(chat::Payload_PayloadFlag_register_);
	firstMessage->set_ip("nose");

	firstMessage->SerializeToString(&message_serialized);

	strcpy(buffer, message_serialized.c_str());
	send(sockfd, buffer, message_serialized.size() + 1, 0);

	// recibir response de servidor
	recv(sockfd, buffer, 8192, 0);

	chat::Payload serverMessage;
	serverMessage.ParseFromString(buffer);

	if(serverMessage.code() == 500){
			std::cout << "Error: "
			  << serverMessage.message()
			  << std::endl;
			return 0;
	}

	std::cout << "El servidor dice: "
			  << serverMessage.message()
			  << std::endl;	

	connected = 1;
	usrname = argv[1];

	// despachar thread que escucha mensajes del server
	pthread_t thread_id;
	pthread_attr_t attrs;
	pthread_attr_init(&attrs);
	pthread_create(&thread_id, &attrs, listenToMessages, (void *)&sockfd);

	print_menu(usrname);
	int client_opt;

	while (true)
	{
		while (waitingForServerResponse == 1){}

		printf("\nEscoja una opcion a realizar (AYUDA = 6):\n");
		client_opt = get_client_option();

		std::string msgSerialized;
		int bytesReceived, bytesSent;

		// List
		if (client_opt == 1)
		{
			/* ENVIAR SOLICITUD A SERVIDOR */
			chat::Payload *userList = new chat::Payload();
			userList->set_sender(argv[1]);
			userList->set_ip("nose");
			userList->set_flag(chat::Payload_PayloadFlag_user_list);

			userList->SerializeToString(&msgSerialized);

			// enviar por socket
			strcpy(buffer, msgSerialized.c_str());
			bytesSent = send(sockfd, buffer, msgSerialized.size() + 1, 0);
			waitingForServerResponse = 1;
		}
		// User info
		else if (client_opt == 2)
		{
			/* ENVIAR SOLICITUD A SERVIDOR */
			std::string user_name;
			printf("Ingrese el nombre del usuario que quiere consultar: \n");
			std::cin >> user_name;

			chat::Payload *userInf = new chat::Payload();
			userInf->set_sender(argv[1]);
			userInf->set_flag(chat::Payload_PayloadFlag_user_info);
			userInf->set_extra(user_name);
			userInf->set_ip("nose");

			userInf->SerializeToString(&msgSerialized);

			// enviar por socket
			strcpy(buffer, msgSerialized.c_str());
			bytesSent = send(sockfd, buffer, msgSerialized.size() + 1, 0);
			waitingForServerResponse = 1;
		}
		// Change status
		else if(client_opt == 3){
			// Preguntar por nuevo status
			printf("Ingrese su nuevo estado: \n");
			printf("1. ACTIVO\n");
			printf("2. OCUPADO\n");
			printf("3. INACTIVO\n");
			int option;
			std::cin >> option;
			std::string newStatus;
			if (option < 4){
				newStatus = statusArray[option-1];
			}
			else
			{
				printf("Estado invalido.\n");
				continue;
			}
			chat::Payload *userInf = new chat::Payload();
			userInf->set_sender(argv[1]);
			userInf->set_flag(chat::Payload_PayloadFlag_update_status);
			userInf->set_extra(newStatus);
			userInf->set_ip("nose");

			userInf->SerializeToString(&msgSerialized);
			// enviar por socket
			strcpy(buffer, msgSerialized.c_str());
			bytesSent = send(sockfd, buffer, msgSerialized.size() + 1, 0);
			waitingForServerResponse = 1;
		}
		else if (client_opt == 4)
		{
			waitingForInput = 1;
			printf("Ingrese un mensaje a enviar: \n");
			std::cin.ignore();
			std::string msg;
			std::getline(std::cin, msg);

			/* ENVIAR SOLICITUD A SERVIDOR */
			chat::Payload *clientMsg= new chat::Payload();
			// Se envia opcion 4: BroadcastRequest
			clientMsg->set_sender(argv[1]);
			clientMsg->set_message(msg);
			clientMsg->set_flag(chat::Payload_PayloadFlag_general_chat);
			clientMsg->set_ip("nose");
			clientMsg->SerializeToString(&msgSerialized);

			// enviar por socket
			strcpy(buffer, msgSerialized.c_str());
			bytesSent = send(sockfd, buffer, msgSerialized.size() + 1, 0);
			waitingForServerResponse = 1;
			waitingForInput = 0;
		}
		else if (client_opt == 5)
		{
			printf("Ingrese el nombre de usuario al que quiere enviarle un mensaje: \n");
			std::cin.ignore();
			std::string user_name;
			std::getline(std::cin, user_name);

			printf("Ingrese un mensaje a enviar: \n");
			std::string msg;
			std::getline(std::cin, msg);

			/* ENVIAR SOLICITUD A SERVIDOR */
			chat::Payload *clientMsg= new chat::Payload();

			clientMsg->set_sender(argv[1]);
			clientMsg->set_message(msg);
			clientMsg->set_flag(chat::Payload_PayloadFlag_private_chat);
			clientMsg->set_extra(user_name);
			clientMsg->set_ip("nose");
			clientMsg->SerializeToString(&msgSerialized);

			// enviar por socket
			strcpy(buffer, msgSerialized.c_str());
			bytesSent = send(sockfd, buffer, msgSerialized.size() + 1, 0);
			waitingForServerResponse = 1;
		}
		else if (client_opt == 6)
		{
			help_menu();
		}
		
		else if (client_opt == 7)
		{
			int option;
			printf("Cerrar sesion? \n");
			printf("1. Si \n");
			printf("2. No \n");

			std::cin >> option;

			if (option == 1)
			{
				printf("Hasta la proxima!\n");
				break;
			}
		}
		else
		{
			std::cout << "Esa no es una opcion valida" << std::endl;
		}
		
		
	}

	// cerrar conexion
	pthread_cancel(thread_id);
	connected = 0;
	close(sockfd);

	return 0;
}