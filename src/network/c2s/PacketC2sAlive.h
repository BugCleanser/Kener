#include <Kener.h>

class PacketC2sAlive
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
    static PacketC2sAlive recv(Connection &connection)
    {
        return PacketC2sAlive();
    }
    void send(Connection &connection)
    {
    }
};
