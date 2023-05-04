#include <Kener.h>

class PacketC2sLogin:public Packet
{
protected:
    std::string name;
    PacketC2sLogin(std::string name):name(name)
    {
    }
public:
    PacketC2sLogin():PacketC2sLogin("Unknown")
    {
    }
    static std::string getId()
    {
        return "login";
    }
    std::string getName()
    {
        return name;
    }
    void recv(Connection &connection) override
    {
        connection >> name;
    }
    void send(Connection &connection) override
    {
        connection << name;
    }
};
