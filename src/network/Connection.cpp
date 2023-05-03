#include <Kener.h>


STATIC(
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);
})

Connection::Connection(std::string host,unsigned short port)
{
    struct addrinfo hints,*result=NULL;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_protocol=IPPROTO_TCP;
    std::string sPort=std::to_string(port);
    if(getaddrinfo(host.c_str(),sPort.c_str(),&hints,&result)!=0)
        throw make_pair("Dns error",host+":"+sPort);
    sock=socket(result->ai_family,result->ai_socktype,result->ai_protocol);
    if(sock==INVALID_SOCKET)
        throw make_pair("Newing socket error",host+":"+sPort);
    if(connect(sock,result->ai_addr,(int)result->ai_addrlen)==SOCKET_ERROR)
        throw make_pair("connecting error",host+":"+sPort);
}

void Connection::send(const void *data,size_t size)
{
    if(::send(sock,(char*)data,size,0)==SOCKET_ERROR)
        throw "Sending error";
}
void Connection::recv(void *data,size_t size)
{
    if(::recv(sock,(char*)data,size,0)==SOCKET_ERROR)
        throw "Recving error";
}
