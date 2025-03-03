#pragma once

#include "core/basic_channel.hpp"

#include <memory>

#ifndef __SENDER_HPP__
#define __SENDER_HPP__

namespace channel {

template <typename T>
struct ISender {
    virtual ~ISender<T>(){};
    virtual bool send(const T value) = 0;
    virtual void close() = 0;
};

template <typename T>
class Sender : public channel::ISender<T> {
   private:
    std::shared_ptr<channel::BasicChannel<T>> _channel;
    Sender<T>(std::shared_ptr<channel::BasicChannel<T>> channel) : _channel(channel) {}

   public:
    /// This is a factory method to create a new Receiver instance.
    /// This class should be used with unique_ptr.
    static std::shared_ptr<channel::ISender<T>> create(std::shared_ptr<channel::BasicChannel<T>> channel) {
        struct Impl : Sender<T> {
            Impl(std::shared_ptr<channel::BasicChannel<T>> channel) : Sender<T>(channel) {}
        };

        return std::make_shared<Impl>(channel);
    }

    virtual ~Sender<T>() { this->close(); }

    // ISender<T> implementation

    bool send(const T value) override { return _channel->send(value); }
    void close() override { _channel->close(); }
};

}  // namespace channel

#endif  // __SENDER_HPP__
