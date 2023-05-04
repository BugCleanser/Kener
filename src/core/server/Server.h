#include <Kener.h>

#include "Player.h"

class Server
{
protected:
    ServerListener listener;
    std::thread thread;
    std::vector<Player*> players;
public:
    Server()
    {
    }
    void listen(unsigned short port)
    {
        listener.listen(port);
        thread=std::thread([&]
        {
            try
            {
                while (true)
                    players.push_back(new Player(listener.accept()));
            }
            catch(...)
            {
                return;
            }
        });
    }
    void close()
    {
        listener.stop();
    }
};
