#pragma once

#include "cpp_channel_export.hpp"

#include "core/basic_channel.hpp"

#include <memory>
#include <string>
#include <vector>

#ifndef __SENDER_HPP__
#define __SENDER_HPP__

namespace channel {

template <typename T>
struct ISender {
    virtual ~ISender() {};
    virtual bool send(const T value) = 0;
    virtual void close() = 0;
    virtual std::shared_ptr<channel::ISender<T>> clone() = 0;
};

template <typename T>
class Sender : public channel::ISender<T> {
   private:
    std::shared_ptr<channel::BasicChannel<T>> _channel;
    Sender(std::shared_ptr<channel::BasicChannel<T>> channel) : _channel(channel) {}

   public:
    /// This is a factory method to create a new Receiver instance.
    /// This class should be used with unique_ptr.
    static std::shared_ptr<channel::ISender<T>> create(std::shared_ptr<channel::BasicChannel<T>> channel) {
        struct Impl : Sender<T> {
            Impl(std::shared_ptr<channel::BasicChannel<T>> channel) : Sender<T>(channel) {}
        };

        return std::make_shared<Impl>(channel);
    }

    virtual ~Sender() { this->close(); }

    // ISender<T> implementation

    bool send(const T value) override { return _channel->send(value); }
    void close() override { _channel->close(); }
    std::shared_ptr<channel::ISender<T>> clone() override { return Sender<T>::create(_channel); }
};

/// explicit instantiation declaration

extern template class CPP_CHANNEL_EXPORT channel::Sender<bool>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<int8_t>>;

}  // namespace channel

#endif  // __SENDER_HPP__
