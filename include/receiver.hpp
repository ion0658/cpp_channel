#pragma once

#include "cpp_channel_export.hpp"

#include "core/basic_channel.hpp"
#include "sender.hpp"

#include <memory>
#include <optional>

#ifndef __RECEIVER_HPP__
#define __RECEIVER_HPP__

namespace channel {

template <typename T>
struct IReceiver {
    virtual ~IReceiver() {}
    virtual std::optional<T> next() = 0;
    virtual std::shared_ptr<channel::ISender<T>> subscribe() = 0;
    virtual bool is_closed() = 0;
    virtual void close() = 0;
};

template <typename T>
class Receiver : public channel::IReceiver<T> {
   private:
    std::shared_ptr<channel::BasicChannel<T>> _channel;
    Receiver(std::shared_ptr<channel::BasicChannel<T>> channel) : _channel(channel) {}

   public:
    /// This is a factory method to create a new Receiver instance.
    /// This class should be used with unique_ptr.
    static std::unique_ptr<channel::IReceiver<T>> create(std::shared_ptr<channel::BasicChannel<T>> channel) {
        struct Impl : Receiver<T> {
            Impl(std::shared_ptr<channel::BasicChannel<T>> channel) : Receiver<T>(channel) {}
        };
        return std::make_unique<Impl>(channel);
    }

    virtual ~Receiver() { this->close(); }

    /// IReceiver<T> implementation

    std::optional<T> next() override { return _channel->receive(); }
    std::shared_ptr<channel::ISender<T>> subscribe() override { return channel::Sender<T>::create(this->_channel); }
    bool is_closed() override { return _channel->is_closed(); }
    void close() override { _channel->close(); }
};

/// explicit instantiation declaration

extern template class CPP_CHANNEL_EXPORT channel::Receiver<bool>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<int8_t>>;

}  // namespace channel

#endif  // __RECEIVER_HPP__
