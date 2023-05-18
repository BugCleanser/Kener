#include <Kener.h>

void Packet::send(Connection &connection)
{
    connection.send(&id,sizeof(id));
}
void Packet::recv(Connection &connection)
{
    connection.recv(&id,sizeof(id));
}
