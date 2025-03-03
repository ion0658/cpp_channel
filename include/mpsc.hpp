#pragma once

#include "core/mpsc_channnel.hpp"
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
    static std::pair<std::unique_ptr<channel::IReceiver<T>>, std::shared_ptr<channel::ISender<T>>> create() {
        auto channel = std::make_shared<channel::MpscChannel<T>>();
        auto receiver = channel::Receiver<T>::create(channel);
        auto sender = channel::Sender<T>::create(channel);
        return {std::move(receiver), sender};
    }
};

}  // namespace channel
// namespace channel

#endif  // __MPSC_HPP__
