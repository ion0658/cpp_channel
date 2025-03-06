#include <cassert>

#include <channel.hpp>

int main() {
    auto [rx, tx] = channel::Broadcast<int>::create();
    // clone receiver
    auto rx2 = rx->clone();
    // create same channel sender from receiver
    auto tx2 = rx->subscribe();
    auto tx3 = rx2->subscribe();

    tx->send(1);
    assert(rx->peek() == 1);
    assert(rx->next() == 1);
    assert(rx->peek() == std::nullopt);
    assert(rx2->try_next() == 1);
    assert(rx2->try_next() == std::nullopt);

    tx->send(2);
    tx2->send(3);
    tx3->send(4);
    assert(rx->next() == 2);
    assert(rx->next() == 3);
    assert(rx->next() == 4);
    assert(rx->try_next() == std::nullopt);
    assert(rx2->next() == 2);
    assert(rx2->next() == 3);
    assert(rx2->next() == 4);
    assert(rx2->try_next() == std::nullopt);

    // after close, no more messages can be sent and received
    tx->close();
    assert(tx2->send(5) == false);
    assert(tx3->send(6) == false);
    assert(rx->next() == std::nullopt);
    assert(rx2->next() == std::nullopt);

    return 0;
}
