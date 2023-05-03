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

    template<class Packet> void send(Packet data)
    {
        std::string id=Packet::getId();
        unsigned char idSize=(unsigned char)id.size();
        send(&idSize,sizeof(idSize));
        send(id.c_str(),id.size());
        std::vector<char> s=data.serialize();
        send(s.data(),s.size());
    }
    template<class Packet> Packet recv()
    {
        return Packet::recv(*this);
    }
};
template<> std::string Connection::recv<std::string>();
