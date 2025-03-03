#include <cstdio>
#include <memory>
#include <random>
#include <thread>

#include <channel.hpp>

void sender_task(std::shared_ptr<channel::ISender<int>> tx) {
    constexpr int N = 1024;
    std::random_device seed_gen{};
    std::mt19937 engine(seed_gen());
    std::uniform_int_distribution dist(0, N);
    for (int i = 0; i < N; ++i) {
        auto val = dist(engine);
        tx->send(val);
    }
}

void receiver_task(std::unique_ptr<channel::IReceiver<int>> rx) {
    for (;;) {
        auto val = rx->next();
        if (!val.has_value()) {
            std::puts("no value");
            break;
        }
        std::printf("recv val: %d\n", val.value());
    }
}

int main() {
    auto [rx, tx] = channel::Mpsc<int>::create();
    auto task_r = std::thread(receiver_task, std::move(rx));
    sender_task(std::move(tx));
    task_r.join();
    return 0;
}
