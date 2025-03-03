#pragma once

#include "cpp_channel_export.hpp"

#include "core/mpsc_channnel.hpp"
#include "receiver.hpp"
#include "sender.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

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

/// explicit instantiation declaration

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<bool>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<uint8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<uint16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<uint32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<uint64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<int8_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<int16_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<int32_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<int64_t>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<std::string>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<std::wstring>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<bool>>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<uint8_t>>;

extern template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<int8_t>>;

}  // namespace channel

#endif  // __MPSC_HPP__
