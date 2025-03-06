#pragma once

#include "channel/basic_channel.hpp"

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

#ifndef __MPSC_CHANNEL_HPP__
#define __MPSC_CHANNEL_HPP__

namespace channel {

template <typename T>
class MpscChannel : public channel::BasicChannel<T> {
   private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _cond;
    bool _closed = false;

   public:
    bool send(const T value) override {
        auto result = false;
        do {
            std::unique_lock<std::mutex> lock(_mutex);
            if (_closed) {
                break;
            }
            _queue.push(value);
            _cond.notify_one();
            result = true;
        } while (0);
        std::this_thread::yield();
        return result;
    }

    std::optional<T> receive() override {
        std::unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [this] { return !_queue.empty() || _closed; });
        if (_closed || _queue.empty()) {
            return std::nullopt;
        }
        T value = _queue.front();
        _queue.pop();
        return value;
    }

    std::optional<T> try_receive() override {
        std::unique_lock<std::mutex> lock(_mutex);
        if (_queue.empty() || _closed) {
            return std::nullopt;
        }
        T value = _queue.front();
        _queue.pop();
        return value;
    }

    std::optional<T> peek() override {
        std::unique_lock<std::mutex> lock(_mutex);
        if (_queue.empty() || _closed) {
            return std::nullopt;
        }
        T value = _queue.front();
        return value;
    }

    bool is_closed() override {
        std::unique_lock<std::mutex> lock(_mutex);
        return _closed;
    }

    void close() override {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _closed = true;
            _cond.notify_all();
        }
        std::this_thread::yield();
    }
};

}  // namespace channel

#endif  // __MPSC_CHANNEL_HPP__
