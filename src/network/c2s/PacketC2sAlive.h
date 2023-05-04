#include <Kener.h>

class PacketC2sAlive:public Packet
{
protected:
public:
    PacketC2sAlive()
    {
    }
    static std::string getId()
    {
        return "alive";
    }
    void recv(Connection &connection) override
    {
    }
    void send(Connection &connection) override
    {
    }
};
