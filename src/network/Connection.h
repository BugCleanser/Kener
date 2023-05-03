class Connection
{
protected:
    SOCKET sock;
public:
    Connection(SOCKET sock)
    {
        this->sock=sock;
    }
    Connection(std::string host,unsigned short port);

    void send(void *data,size_t size);
    void recv(void *data,size_t size);
};
