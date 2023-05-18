#include <Kener.h>

class Connection;
class Packet
{
protected:
    int id;
public:
    virtual void send(Connection &connection);
    virtual void recv(Connection &connection);
};
