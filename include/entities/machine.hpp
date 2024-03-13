#pragma once

#include <map>

#include "types.hpp"

namespace scheduling {
class Machine
{
protected:
    MachineID                         machine_id_;
    bool                              is_batch_;
    int                               min_batch_size_;
    int                               max_batch_size_;
    TimeDuration                      setup_time_;
    std::map<MachineID, TransferTime> transfer_time_map_;
};

}   // namespace scheduling