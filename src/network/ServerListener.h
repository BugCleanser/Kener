#include <Kener.h>

class ServerListener
{
protected:
    SOCKET sock;
public:
    ServerListener();
    ~ServerListener();
    void listen(unsigned short port);
    Connection accept();
    void stop();
};
