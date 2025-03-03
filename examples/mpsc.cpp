#include <cstdio>
#include <memory>
#include <thread>

#include <channel.hpp>

int main() {
    auto [rx, tx] = channel::Mpsc<int>::create();
    auto t1 = std::thread(
        [](std::shared_ptr<channel::ISender<int>> tx) {
            for (auto i = 0; i < 5; i++) {
                std::printf("send val: %d\n", i);
                tx->send(i);
                std::this_thread::yield();
            }
            tx->close();
        },
        tx);
    for (;;) {
        auto val = rx->next();
        if (!val.has_value()) {
            std::puts("no value");
            break;
        }
        std::printf("recv val: %d\n", val.value());
    }

    t1.join();
    return 0;
}
