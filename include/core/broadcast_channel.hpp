#pragma once

#include "cpp_channel_export.hpp"

#include "core/basic_channel.hpp"
#include "core/mpsc_channnel.hpp"

#include <mutex>
#include <optional>
#include <set>
#include <thread>

#ifndef __BROADCAST_CHANNEL_HPP__
#define __BROADCAST_CHANNEL_HPP__

namespace channel {

template <typename T>
class BroadcastChannel : public channel::BasicChannel<T> {
   private:
    std::mutex _mutex;
    bool _closed = false;
    std::set<std::shared_ptr<channel::MpscChannel<T>>> _receivers;

   public:
    bool send(const T value) override {
        std::unique_lock<std::mutex> lock(_mutex);
        for (auto& receiver : _receivers) {
            if (!receiver->send(value)) {
                return false;
            }
        }
        return true;
    }
    std::optional<T> receive() override { return std::nullopt; }

    bool is_closed() override {
        std::unique_lock<std::mutex> lock(_mutex);
        std::this_thread::yield();
        return _closed;
    }

    void close() override {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _closed = true;
            for (auto& receiver : _receivers) {
                receiver->close();
            }
            _receivers.clear();
        }
        std::this_thread::yield();
    }

    void add_receiver(std::shared_ptr<channel::MpscChannel<T>> receiver) {
        std::unique_lock<std::mutex> lock(_mutex);
        _receivers.insert(receiver);
    }

    void delete_receiver(std::shared_ptr<channel::MpscChannel<T>> receiver) {
        std::unique_lock<std::mutex> lock(_mutex);
        _receivers.erase(receiver);
    }
};

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<bool>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<int8_t>>;

}  // namespace channel

#endif  // __BROADCAST_CHANNEL_HPP__
