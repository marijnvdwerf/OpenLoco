#include "Intro.h"
#include "Gui.h"
#include "Interop/Interop.hpp"
#include "Station.h"
#include "Title.h"

using namespace OpenLoco::Interop;

namespace OpenLoco::Intro
{
    loco_global<uint8_t, 0x0050C195> _state;

    bool isActive()
    {
        return state() != intro_state::none;
    }

    intro_state state()
    {
        return (intro_state)*_state;
    }

    void state(intro_state state)
    {
        _state = (uint8_t)state;
    }

    static bool _50C196 = false;
    static int _50C190 = 0;

    // 0x0046AE0C
    void update()
    {
        addr<0x0005252E0, int32_t>() = 1;

        switch (state())
        {
            case intro_state::none:
            case intro_state::begin:
            case intro_state::state_8:
            case intro_state::state_9:
                // TODO: implement
                break;

            case intro_state::end:
                Gfx::clear(Gfx::screenDpi(), 0xA0B0C0D0);
                if(_50C196) {
                    _50C196 = false;
                }
                state(intro_state::done);
                _50C190 = 0;
                break;

            case intro_state::done:
                state(intro_state::none);
                call(0x004523F4);
                addr<0x0005252E0, int32_t>() = 0;
                Gfx::invalidateScreen();
                initialiseViewports();
                Gui::init();
                Title::reset();
                break;
        }


        OpenLoco::sub_431695(0);
        return;

        return;
        switch (state())
        {

            case intro_state::none: break;
            case intro_state::begin: break;
            case intro_state::state_8: break;
            case intro_state::state_9: break;
            case intro_state::end: break;
        }
        //        call(0x0046AE0C);
    }
}
