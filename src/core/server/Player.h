#include <Kener.h>

class LoginPacket
{
protected:
    std::string name;
    LoginPacket(std::string name):name(name)
    {
    }
public:
    LoginPacket():LoginPacket("Unknown")
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
    static LoginPacket recv(Connection &connection)
    {
        std::string name;
        connection >> name;
        return LoginPacket(name);
    }
    void send(Connection &connection)
    {
        connection << std::string("awa");
    }
};

class Player
{
protected:
    Connection connection;
    std::thread thread;
    std::string name;
public:
    Player(Connection connection):connection(connection),name("Unknown")
    {
        thread=std::thread([&]
        {
            PacketListener packetListener(connection);
            packetListener.reg<LoginPacket>([&](LoginPacket a)
            {
                name=a.getName();
            });
        });
    }
};
