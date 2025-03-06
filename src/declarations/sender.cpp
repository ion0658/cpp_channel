#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "sender.hpp"

template class CPP_CHANNEL_EXPORT channel::Sender<bool>;

template class CPP_CHANNEL_EXPORT channel::Sender<uint8_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<uint16_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<uint32_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<int8_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<int16_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<int32_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<int64_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<size_t>;

template class CPP_CHANNEL_EXPORT channel::Sender<std::string>;

template class CPP_CHANNEL_EXPORT channel::Sender<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<bool>>;

template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<uint8_t>>;

template class CPP_CHANNEL_EXPORT channel::Sender<std::vector<int8_t>>;
