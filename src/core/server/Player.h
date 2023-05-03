#include <Kener.h>

class LoginPacket
{
protected:
    std::string name;
    LoginPacket(std::string name):name(name)
    {
    }
public:
    static std::string getId()
    {
        return "login";
    }
    static LoginPacket recv(Connection &connection)
    {
        return LoginPacket(connection.recv<std::string>());
    }
};

class Player {
   private:
    Connection connection;
    std::thread thread;
    std::string name;
   public:
    Player(Connection connection) : connection(connection), name("Unknown+114514") {
        thread = std::thread([&]() {
            PacketListener packetListener(connection);
            packetListener.reg<LoginPacket>([&](LoginPacket a)
            {
                
            });
            // bu guan
        });
    }
};