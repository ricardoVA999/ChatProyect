all: server client

server: serverSide.cpp payload.pb.cc
	g++ -o serverSide serverSide.cpp payload.pb.cc -lpthread -lprotobuf

client: clientSide.cpp payload.pb.cc
	g++ -o clientSide clientSide.cpp payload.pb.cc -lpthread -lprotobuf

payload.pb.cc: payload.proto
	protoc -I=. --cpp_out=. payload.proto
