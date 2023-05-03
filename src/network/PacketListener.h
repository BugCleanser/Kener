class PacketListener
{
protected:
    Connection connection;
    std::unordered_map<std::string,std::function<void()>> processors;
public:
    PacketListener(Connection connection):connection(connection)
    {
    }
    template<class Packet> void reg(std::function<void(Packet)> processor)
    {
        processors[Packet::getId()]=[this,processor]
        {
            processor(Packet::recv(connection));
        };
    }
    void join()
    {
        while(true)
        {
            unsigned char idSize;
            connection.recv(&idSize,sizeof(idSize));
            char id[idSize+1];
            connection.recv(id,idSize);
            id[idSize]='\0';
            auto p=processors.find(std::string(id));
            if(p==processors.end())
                throw std::make_pair("Unknown packet",std::string(id));
            p->second();
        }
    }
};
