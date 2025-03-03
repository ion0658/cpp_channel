#pragma once

#include <optional>

#ifndef __BASIC_CHANNEL_HPP__
#define __BASIC_CHANNEL_HPP__

namespace channel {

template <typename T>
struct BasicChannel {
    virtual bool send(const T value) = 0;
    virtual std::optional<T> receive() = 0;
    virtual bool is_closed() = 0;
    virtual void close() = 0;
};

}  // namespace channel

#endif  // __BASIC_CHANNEL_HPP__
