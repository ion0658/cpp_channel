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

void receiver_task(int idx, std::unique_ptr<channel::IReceiver<int>> rx) {
    for (;;) {
        auto val = rx->next();
        if (!val.has_value()) {
            std::puts("no value");
            break;
        }
        std::printf("recv[%d] val: %d\n", idx, val.value());
    }
}

int main() {
    constexpr auto receiver_count = 10;
    auto [rx, tx] = channel::Broadcast<int>::create();
    auto tasks = std::vector<std::thread>();
    for (auto i = 0; i < receiver_count; ++i) {
        auto r = rx->clone();
        auto task = std::thread(receiver_task, i, std::move(r));
        tasks.push_back(std::move(task));
    }

    sender_task(std::move(tx));
    for (auto& task : tasks) {
        task.join();
    }
    return 0;
}
