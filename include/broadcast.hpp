#pragma once

#include "core/broadcast_channel.hpp"
#include "core/mpsc_channnel.hpp"
#include "receiver.hpp"
#include "sender.hpp"

#include <memory>
#include <utility>

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
    std::unique_ptr<channel::ISender<T>> subscribe() override { return channel::Sender<T>::create(this->_channel); }
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
    static std::pair<std::unique_ptr<channel::BroadcastReceiver<T>>, std::unique_ptr<channel::ISender<T>>> create() {
        auto channel = std::make_shared<channel::BroadcastChannel<T>>();
        return {channel::BroadcastReceiver<T>::create(channel), channel::Sender<T>::create(channel)};
    }
};

}  // namespace channel
#endif  // __BROADCAST_HPP__
