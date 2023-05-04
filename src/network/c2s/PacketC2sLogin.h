#include <Kener.h>

class PacketC2sLogin
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
    static PacketC2sLogin recv(Connection &connection)
    {
        std::string name;
        connection >> name;
        return PacketC2sLogin(name);
    }
    void send(Connection &connection)
    {
        connection << name;
    }
};
