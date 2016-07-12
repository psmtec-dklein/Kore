#pragma once

namespace Kore {
    enum SwapControl {
        SwapControlAdaptiveVsync = -1,
        SwapControlNoVsync = 0
        
        // (DK) -every other value enables vsync with an interval of said value
        //      -to match the monitor rate use 1
    };
}
