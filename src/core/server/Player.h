#include <Kener.h>

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
            packetListener.reg<PacketC2sAlive>([&](auto packet)
            {
            });
            packetListener.reg<PacketC2sLogin>([&](auto packet)
            {
                name=packet.getName();
            });
        });
    }
};
