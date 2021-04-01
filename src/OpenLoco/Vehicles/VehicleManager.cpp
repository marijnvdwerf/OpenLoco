#include "VehicleManager.h"
#include "../Company.h"
#include "../Interop/Interop.hpp"
#include "../OpenLoco.h"

using namespace OpenLoco::Interop;

namespace OpenLoco::VehicleManager
{
    // 0x004C3A0C
    void determineAvailableVehicles(company& company)
    {
        registers regs;
        regs.esi = (loco_ptr)&company;
        call(0x004C3A0C, regs);
    }
}
