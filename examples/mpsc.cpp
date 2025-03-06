#include <cassert>

#include <channel.hpp>

int main() {
    auto [rx, tx] = channel::Mpsc<int>::create();
    auto tx2 = tx->clone();      // same channel sender
    auto tx3 = rx->subscribe();  // same channel sender from receiver

    // basic send and receive and peek
    tx->send(1);
    tx->send(2);
    assert(rx->peek() == 1);
    assert(rx->next() == 1);
    assert(rx->try_next() == 2);
    assert(rx->peek() == std::nullopt);      // peek will return std::nullopt when channel is empty
    assert(rx->try_next() == std::nullopt);  // try_next will return std::nullopt when channel is empty

    // send from multiple senders
    tx->send(3);
    tx2->send(4);
    tx3->send(5);
    assert(rx->next() == 3);
    assert(rx->next() == 4);
    assert(rx->next() == 5);
    assert(rx->try_next() == std::nullopt);

    tx->send(6);
    tx2->close();
    assert(tx->send(7) == false);        // send will return false when channel is closed
    assert(rx->next() == std::nullopt);  // next will return std::nullopt when channel is closed
    return 0;
}
