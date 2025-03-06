#pragma once

#include "channel/mpsc_channnel.hpp"
#include "receiver.hpp"
#include "sender.hpp"

#include <memory>
#include <utility>

#ifndef __MPSC_HPP__
#define __MPSC_HPP__

namespace channel {

template <typename T>
class Mpsc {
   public:
    static std::pair<std::unique_ptr<channel::IReceiver<T>>, std::unique_ptr<channel::ISender<T>>> create() {
        auto channel = std::make_shared<channel::MpscChannel<T>>();
        return {channel::Receiver<T>::create(channel), channel::Sender<T>::create(channel)};
    }
};

}  // namespace channel

#endif  // __MPSC_HPP__
