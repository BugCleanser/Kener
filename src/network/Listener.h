class Listener
{
protected:
    Connection connection;
    std::unordered_map<std::string,std::function<void()>> processors;
public:
    Listener(Connection connection):connection(connection)
    {
    }
    template<class Packet> void reg(std::function<void(Packet)> processor)
    {
        processors[Packet::getId()]=[this,processor]
        {
            processor(Packet::recv(*this));
        };
    }
};
