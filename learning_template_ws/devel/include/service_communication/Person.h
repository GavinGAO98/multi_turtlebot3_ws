// Generated by gencpp from file service_communication/Person.msg
// DO NOT EDIT!


#ifndef SERVICE_COMMUNICATION_MESSAGE_PERSON_H
#define SERVICE_COMMUNICATION_MESSAGE_PERSON_H

#include <ros/service_traits.h>


#include <service_communication/PersonRequest.h>
#include <service_communication/PersonResponse.h>


namespace service_communication
{

struct Person
{

typedef PersonRequest Request;
typedef PersonResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Person
} // namespace service_communication


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::service_communication::Person > {
  static const char* value()
  {
    return "c198113e7dd9cc5c9fd5f271c8479b39";
  }

  static const char* value(const ::service_communication::Person&) { return value(); }
};

template<>
struct DataType< ::service_communication::Person > {
  static const char* value()
  {
    return "service_communication/Person";
  }

  static const char* value(const ::service_communication::Person&) { return value(); }
};


// service_traits::MD5Sum< ::service_communication::PersonRequest> should match
// service_traits::MD5Sum< ::service_communication::Person >
template<>
struct MD5Sum< ::service_communication::PersonRequest>
{
  static const char* value()
  {
    return MD5Sum< ::service_communication::Person >::value();
  }
  static const char* value(const ::service_communication::PersonRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::service_communication::PersonRequest> should match
// service_traits::DataType< ::service_communication::Person >
template<>
struct DataType< ::service_communication::PersonRequest>
{
  static const char* value()
  {
    return DataType< ::service_communication::Person >::value();
  }
  static const char* value(const ::service_communication::PersonRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::service_communication::PersonResponse> should match
// service_traits::MD5Sum< ::service_communication::Person >
template<>
struct MD5Sum< ::service_communication::PersonResponse>
{
  static const char* value()
  {
    return MD5Sum< ::service_communication::Person >::value();
  }
  static const char* value(const ::service_communication::PersonResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::service_communication::PersonResponse> should match
// service_traits::DataType< ::service_communication::Person >
template<>
struct DataType< ::service_communication::PersonResponse>
{
  static const char* value()
  {
    return DataType< ::service_communication::Person >::value();
  }
  static const char* value(const ::service_communication::PersonResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SERVICE_COMMUNICATION_MESSAGE_PERSON_H
