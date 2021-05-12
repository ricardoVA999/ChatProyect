// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: payload.proto

#ifndef PROTOBUF_INCLUDED_payload_2eproto
#define PROTOBUF_INCLUDED_payload_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_payload_2eproto 

namespace protobuf_payload_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_payload_2eproto
namespace chat {
class Payload;
class PayloadDefaultTypeInternal;
extern PayloadDefaultTypeInternal _Payload_default_instance_;
}  // namespace chat
namespace google {
namespace protobuf {
template<> ::chat::Payload* Arena::CreateMaybeMessage<::chat::Payload>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace chat {

enum Payload_PayloadFlag {
  Payload_PayloadFlag_general_chat = 0,
  Payload_PayloadFlag_private_chat = 1,
  Payload_PayloadFlag_update_status = 2,
  Payload_PayloadFlag_user_info = 3,
  Payload_PayloadFlag_user_list = 4,
  Payload_PayloadFlag_register_ = 5
};
bool Payload_PayloadFlag_IsValid(int value);
const Payload_PayloadFlag Payload_PayloadFlag_PayloadFlag_MIN = Payload_PayloadFlag_general_chat;
const Payload_PayloadFlag Payload_PayloadFlag_PayloadFlag_MAX = Payload_PayloadFlag_register_;
const int Payload_PayloadFlag_PayloadFlag_ARRAYSIZE = Payload_PayloadFlag_PayloadFlag_MAX + 1;

const ::google::protobuf::EnumDescriptor* Payload_PayloadFlag_descriptor();
inline const ::std::string& Payload_PayloadFlag_Name(Payload_PayloadFlag value) {
  return ::google::protobuf::internal::NameOfEnum(
    Payload_PayloadFlag_descriptor(), value);
}
inline bool Payload_PayloadFlag_Parse(
    const ::std::string& name, Payload_PayloadFlag* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Payload_PayloadFlag>(
    Payload_PayloadFlag_descriptor(), name, value);
}
// ===================================================================

class Payload : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chat.Payload) */ {
 public:
  Payload();
  virtual ~Payload();

  Payload(const Payload& from);

  inline Payload& operator=(const Payload& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Payload(Payload&& from) noexcept
    : Payload() {
    *this = ::std::move(from);
  }

  inline Payload& operator=(Payload&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Payload& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Payload* internal_default_instance() {
    return reinterpret_cast<const Payload*>(
               &_Payload_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Payload* other);
  friend void swap(Payload& a, Payload& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Payload* New() const final {
    return CreateMaybeMessage<Payload>(NULL);
  }

  Payload* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Payload>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Payload& from);
  void MergeFrom(const Payload& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Payload* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Payload_PayloadFlag PayloadFlag;
  static const PayloadFlag general_chat =
    Payload_PayloadFlag_general_chat;
  static const PayloadFlag private_chat =
    Payload_PayloadFlag_private_chat;
  static const PayloadFlag update_status =
    Payload_PayloadFlag_update_status;
  static const PayloadFlag user_info =
    Payload_PayloadFlag_user_info;
  static const PayloadFlag user_list =
    Payload_PayloadFlag_user_list;
  static const PayloadFlag register_ =
    Payload_PayloadFlag_register_;
  static inline bool PayloadFlag_IsValid(int value) {
    return Payload_PayloadFlag_IsValid(value);
  }
  static const PayloadFlag PayloadFlag_MIN =
    Payload_PayloadFlag_PayloadFlag_MIN;
  static const PayloadFlag PayloadFlag_MAX =
    Payload_PayloadFlag_PayloadFlag_MAX;
  static const int PayloadFlag_ARRAYSIZE =
    Payload_PayloadFlag_PayloadFlag_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  PayloadFlag_descriptor() {
    return Payload_PayloadFlag_descriptor();
  }
  static inline const ::std::string& PayloadFlag_Name(PayloadFlag value) {
    return Payload_PayloadFlag_Name(value);
  }
  static inline bool PayloadFlag_Parse(const ::std::string& name,
      PayloadFlag* value) {
    return Payload_PayloadFlag_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string sender = 1;
  bool has_sender() const;
  void clear_sender();
  static const int kSenderFieldNumber = 1;
  const ::std::string& sender() const;
  void set_sender(const ::std::string& value);
  #if LANG_CXX11
  void set_sender(::std::string&& value);
  #endif
  void set_sender(const char* value);
  void set_sender(const char* value, size_t size);
  ::std::string* mutable_sender();
  ::std::string* release_sender();
  void set_allocated_sender(::std::string* sender);

  // optional string ip = 2;
  bool has_ip() const;
  void clear_ip();
  static const int kIpFieldNumber = 2;
  const ::std::string& ip() const;
  void set_ip(const ::std::string& value);
  #if LANG_CXX11
  void set_ip(::std::string&& value);
  #endif
  void set_ip(const char* value);
  void set_ip(const char* value, size_t size);
  ::std::string* mutable_ip();
  ::std::string* release_ip();
  void set_allocated_ip(::std::string* ip);

  // optional string message = 3;
  bool has_message() const;
  void clear_message();
  static const int kMessageFieldNumber = 3;
  const ::std::string& message() const;
  void set_message(const ::std::string& value);
  #if LANG_CXX11
  void set_message(::std::string&& value);
  #endif
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  ::std::string* mutable_message();
  ::std::string* release_message();
  void set_allocated_message(::std::string* message);

  // optional string extra = 5;
  bool has_extra() const;
  void clear_extra();
  static const int kExtraFieldNumber = 5;
  const ::std::string& extra() const;
  void set_extra(const ::std::string& value);
  #if LANG_CXX11
  void set_extra(::std::string&& value);
  #endif
  void set_extra(const char* value);
  void set_extra(const char* value, size_t size);
  ::std::string* mutable_extra();
  ::std::string* release_extra();
  void set_allocated_extra(::std::string* extra);

  // optional .chat.Payload.PayloadFlag flag = 4;
  bool has_flag() const;
  void clear_flag();
  static const int kFlagFieldNumber = 4;
  ::chat::Payload_PayloadFlag flag() const;
  void set_flag(::chat::Payload_PayloadFlag value);

  // optional int32 code = 6;
  bool has_code() const;
  void clear_code();
  static const int kCodeFieldNumber = 6;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:chat.Payload)
 private:
  void set_has_sender();
  void clear_has_sender();
  void set_has_ip();
  void clear_has_ip();
  void set_has_message();
  void clear_has_message();
  void set_has_flag();
  void clear_has_flag();
  void set_has_extra();
  void clear_has_extra();
  void set_has_code();
  void clear_has_code();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr sender_;
  ::google::protobuf::internal::ArenaStringPtr ip_;
  ::google::protobuf::internal::ArenaStringPtr message_;
  ::google::protobuf::internal::ArenaStringPtr extra_;
  int flag_;
  ::google::protobuf::int32 code_;
  friend struct ::protobuf_payload_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Payload

// optional string sender = 1;
inline bool Payload::has_sender() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Payload::set_has_sender() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Payload::clear_has_sender() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Payload::clear_sender() {
  sender_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_sender();
}
inline const ::std::string& Payload::sender() const {
  // @@protoc_insertion_point(field_get:chat.Payload.sender)
  return sender_.GetNoArena();
}
inline void Payload::set_sender(const ::std::string& value) {
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.Payload.sender)
}
#if LANG_CXX11
inline void Payload::set_sender(::std::string&& value) {
  set_has_sender();
  sender_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.Payload.sender)
}
#endif
inline void Payload::set_sender(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.Payload.sender)
}
inline void Payload::set_sender(const char* value, size_t size) {
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.Payload.sender)
}
inline ::std::string* Payload::mutable_sender() {
  set_has_sender();
  // @@protoc_insertion_point(field_mutable:chat.Payload.sender)
  return sender_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Payload::release_sender() {
  // @@protoc_insertion_point(field_release:chat.Payload.sender)
  if (!has_sender()) {
    return NULL;
  }
  clear_has_sender();
  return sender_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Payload::set_allocated_sender(::std::string* sender) {
  if (sender != NULL) {
    set_has_sender();
  } else {
    clear_has_sender();
  }
  sender_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sender);
  // @@protoc_insertion_point(field_set_allocated:chat.Payload.sender)
}

// optional string ip = 2;
inline bool Payload::has_ip() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Payload::set_has_ip() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Payload::clear_has_ip() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Payload::clear_ip() {
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_ip();
}
inline const ::std::string& Payload::ip() const {
  // @@protoc_insertion_point(field_get:chat.Payload.ip)
  return ip_.GetNoArena();
}
inline void Payload::set_ip(const ::std::string& value) {
  set_has_ip();
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.Payload.ip)
}
#if LANG_CXX11
inline void Payload::set_ip(::std::string&& value) {
  set_has_ip();
  ip_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.Payload.ip)
}
#endif
inline void Payload::set_ip(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_ip();
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.Payload.ip)
}
inline void Payload::set_ip(const char* value, size_t size) {
  set_has_ip();
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.Payload.ip)
}
inline ::std::string* Payload::mutable_ip() {
  set_has_ip();
  // @@protoc_insertion_point(field_mutable:chat.Payload.ip)
  return ip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Payload::release_ip() {
  // @@protoc_insertion_point(field_release:chat.Payload.ip)
  if (!has_ip()) {
    return NULL;
  }
  clear_has_ip();
  return ip_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Payload::set_allocated_ip(::std::string* ip) {
  if (ip != NULL) {
    set_has_ip();
  } else {
    clear_has_ip();
  }
  ip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ip);
  // @@protoc_insertion_point(field_set_allocated:chat.Payload.ip)
}

// optional string message = 3;
inline bool Payload::has_message() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Payload::set_has_message() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Payload::clear_has_message() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Payload::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_message();
}
inline const ::std::string& Payload::message() const {
  // @@protoc_insertion_point(field_get:chat.Payload.message)
  return message_.GetNoArena();
}
inline void Payload::set_message(const ::std::string& value) {
  set_has_message();
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.Payload.message)
}
#if LANG_CXX11
inline void Payload::set_message(::std::string&& value) {
  set_has_message();
  message_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.Payload.message)
}
#endif
inline void Payload::set_message(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_message();
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.Payload.message)
}
inline void Payload::set_message(const char* value, size_t size) {
  set_has_message();
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.Payload.message)
}
inline ::std::string* Payload::mutable_message() {
  set_has_message();
  // @@protoc_insertion_point(field_mutable:chat.Payload.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Payload::release_message() {
  // @@protoc_insertion_point(field_release:chat.Payload.message)
  if (!has_message()) {
    return NULL;
  }
  clear_has_message();
  return message_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Payload::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    set_has_message();
  } else {
    clear_has_message();
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:chat.Payload.message)
}

// optional .chat.Payload.PayloadFlag flag = 4;
inline bool Payload::has_flag() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Payload::set_has_flag() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Payload::clear_has_flag() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Payload::clear_flag() {
  flag_ = 0;
  clear_has_flag();
}
inline ::chat::Payload_PayloadFlag Payload::flag() const {
  // @@protoc_insertion_point(field_get:chat.Payload.flag)
  return static_cast< ::chat::Payload_PayloadFlag >(flag_);
}
inline void Payload::set_flag(::chat::Payload_PayloadFlag value) {
  assert(::chat::Payload_PayloadFlag_IsValid(value));
  set_has_flag();
  flag_ = value;
  // @@protoc_insertion_point(field_set:chat.Payload.flag)
}

// optional string extra = 5;
inline bool Payload::has_extra() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Payload::set_has_extra() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Payload::clear_has_extra() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Payload::clear_extra() {
  extra_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_extra();
}
inline const ::std::string& Payload::extra() const {
  // @@protoc_insertion_point(field_get:chat.Payload.extra)
  return extra_.GetNoArena();
}
inline void Payload::set_extra(const ::std::string& value) {
  set_has_extra();
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.Payload.extra)
}
#if LANG_CXX11
inline void Payload::set_extra(::std::string&& value) {
  set_has_extra();
  extra_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.Payload.extra)
}
#endif
inline void Payload::set_extra(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_extra();
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.Payload.extra)
}
inline void Payload::set_extra(const char* value, size_t size) {
  set_has_extra();
  extra_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.Payload.extra)
}
inline ::std::string* Payload::mutable_extra() {
  set_has_extra();
  // @@protoc_insertion_point(field_mutable:chat.Payload.extra)
  return extra_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Payload::release_extra() {
  // @@protoc_insertion_point(field_release:chat.Payload.extra)
  if (!has_extra()) {
    return NULL;
  }
  clear_has_extra();
  return extra_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Payload::set_allocated_extra(::std::string* extra) {
  if (extra != NULL) {
    set_has_extra();
  } else {
    clear_has_extra();
  }
  extra_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), extra);
  // @@protoc_insertion_point(field_set_allocated:chat.Payload.extra)
}

// optional int32 code = 6;
inline bool Payload::has_code() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Payload::set_has_code() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Payload::clear_has_code() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Payload::clear_code() {
  code_ = 0;
  clear_has_code();
}
inline ::google::protobuf::int32 Payload::code() const {
  // @@protoc_insertion_point(field_get:chat.Payload.code)
  return code_;
}
inline void Payload::set_code(::google::protobuf::int32 value) {
  set_has_code();
  code_ = value;
  // @@protoc_insertion_point(field_set:chat.Payload.code)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace chat

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::chat::Payload_PayloadFlag> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chat::Payload_PayloadFlag>() {
  return ::chat::Payload_PayloadFlag_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_payload_2eproto