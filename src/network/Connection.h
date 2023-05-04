class Connection
{
protected:
    SOCKET sock;
public:
    Connection(SOCKET sock);
    Connection(std::string host,unsigned short port);
    ~Connection();

    void send(const void *data,size_t size);
    void recv(void *data,size_t size);

    template<class Packet> Connection &operator<<(Packet &&data)
    {
        std::string id=Packet::getId();
        unsigned char idSize=(unsigned char)id.size();
        send(&idSize,sizeof(idSize));
        send(id.c_str(),id.size());
        data.send(*this);
        return *this;
    }
    template<class Packet> Connection &operator>>(Packet &packet)
    {
        packet=Packet::recv(*this);
        return *this;
    }
};
template<> Connection &Connection::operator<<(std::string &&str);
template<> Connection &Connection::operator>>(std::string &str);
