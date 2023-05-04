class Connection;
class Packet
{
public:
    virtual void send(Connection &connection)=0;
    virtual void recv(Connection &connection)=0;
};
