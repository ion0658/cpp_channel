#pragma once

#include "cpp_channel_export.hpp"

#include "core/broadcast_channel.hpp"
#include "core/mpsc_channnel.hpp"
#include "receiver.hpp"
#include "sender.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

#ifndef __BROADCAST_HPP__
#define __BROADCAST_HPP__

namespace channel {

template <typename T>
class BroadcastReceiver : public channel::IReceiver<T> {
   private:
    std::shared_ptr<channel::BroadcastChannel<T>> _channel;
    std::shared_ptr<channel::MpscChannel<T>> _mpsc;
    BroadcastReceiver(std::shared_ptr<channel::BroadcastChannel<T>> channel)
        : _channel(channel), _mpsc(std::make_shared<channel::MpscChannel<T>>()) {
        _channel->add_receiver(_mpsc);
    }

   public:
    static std::unique_ptr<channel::BroadcastReceiver<T>> create(
        std::shared_ptr<channel::BroadcastChannel<T>> channel) {
        struct Impl : BroadcastReceiver<T> {
            Impl(std::shared_ptr<channel::BroadcastChannel<T>> channel) : BroadcastReceiver<T>(channel) {}
        };
        return std::make_unique<Impl>(channel);
    }

    virtual ~BroadcastReceiver() { this->close(); }

    std::optional<T> next() override { return _mpsc->receive(); }
    std::shared_ptr<channel::ISender<T>> subscribe() override { return channel::Sender<T>::create(this->_channel); }
    bool is_closed() override { return _mpsc->is_closed(); }
    void close() override {
        this->_channel->delete_receiver(this->_mpsc);
        this->_mpsc->close();
    }
    std::unique_ptr<BroadcastReceiver<T>> clone() { return BroadcastReceiver::create(this->_channel); }
};

template <typename T>
class Broadcast {
   public:
    static std::pair<std::unique_ptr<channel::BroadcastReceiver<T>>, std::shared_ptr<channel::ISender<T>>> create() {
        auto channel = std::make_shared<channel::BroadcastChannel<T>>();
        auto receiver = channel::BroadcastReceiver<T>::create(channel);
        auto sender = channel::Sender<T>::create(channel);
        return {std::move(receiver), sender};
    }
};

/// explicit instantiation declaration

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<bool>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<int8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<bool>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<int8_t>>;

}  // namespace channel
#endif  // __BROADCAST_HPP__
