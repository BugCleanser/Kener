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

    template<class Packet> void send(Packet data)
    {
        vector<char> s=data.serialize();
        send(s.data(),s.size());
    }
    template<class Packet> Packet recv()
    {
        return Packet::recv(*this);
    }
};
