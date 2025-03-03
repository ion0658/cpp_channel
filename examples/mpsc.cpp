#include <cassert>
#include <cstdio>

#include <channel.hpp>

int main() {
    auto [rx, tx] = channel::Mpsc<int>::create();
    auto tx2 = tx->clone();

    tx->send(1);
    tx2->send(2);
    tx->send(3);

    assert(rx->next() == 1);
    assert(rx->next() == 2);
    assert(rx->next() == 3);

    /*tx->close();*/
    tx2->close();
    assert(rx->next() == std::nullopt);
    return 0;
}
