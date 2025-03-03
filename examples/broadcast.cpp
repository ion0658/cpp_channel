#include <cassert>
#include <cstdio>

#include <channel.hpp>

int main() {
    auto [rx, tx] = channel::Broadcast<int>::create();
    auto rx2 = rx->clone();

    tx->send(1);
    tx->send(2);
    tx->send(3);

    assert(rx->next() == 1);
    assert(rx->next() == 2);
    assert(rx->next() == 3);

    assert(rx2->next() == 1);
    assert(rx2->next() == 2);
    assert(rx2->next() == 3);

    tx->close();
    assert(rx->next() == std::nullopt);
    assert(rx2->next() == std::nullopt);

    return 0;
}
