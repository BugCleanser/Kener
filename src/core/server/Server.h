#include <Kener.h>

class Server {
   protected:
    ServerListener listener;
    std::thread thread;
    std::vector<Connection> connections;
   public:
    Server() {}
    void open(unsigned short port) {
        listener.listen(port);
        thread = std::thread([&] {
            try { while (true) {
                connections.push_back(listener.accept());
            } } catch (...) {
                return;
            }
        });
    }
    void close() {
        
    }
};
