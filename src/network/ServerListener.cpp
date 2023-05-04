#include <Kener.h>

ServerListener::ServerListener()
{
    sock=INVALID_SOCKET;
}
ServerListener::~ServerListener()
{
    if(sock!=INVALID_SOCKET)
        closesocket(sock);
}

void ServerListener::listen(unsigned short port)
{
    addrinfo hints,*result=NULL;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    std::string sPort=std::to_string(port);
    if(getaddrinfo(NULL,sPort.c_str(),&hints,&result)!=0)
        throw std::make_pair("Dns port",sPort);
    sock=socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sock==INVALID_SOCKET)
        throw std::make_pair("Newing socket",sPort);
    if(::bind(sock,result->ai_addr,(socklen_t)result->ai_addrlen)==SOCKET_ERROR)
        throw std::make_pair("Binding port",sPort);
    if(::listen(sock,SOMAXCONN)==SOCKET_ERROR)
        throw std::make_pair("Listening port",sPort);
}
Connection ServerListener::accept()
{
    SOCKET c=::accept(sock,NULL,NULL);
    if(c==INVALID_SOCKET)
        throw "Accepting";
    return Connection(c);
}
void ServerListener::stop()
{
    closesocket(sock);
}
