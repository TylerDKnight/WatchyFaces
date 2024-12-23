#ifndef WATCHY_CELLULARAUTOMATA_H
#define WATCHY_CELLULARAUTOMATA_H

#include <Watchy.h>
#include "Px437_IBM_BIOS5pt7b.h"
#include "abduction200230pt7b_DATETIME.h"
#include "icons.h"

class WatchyCellularAutomata : public Watchy {
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        // void showBuzz();
        void showCAinfo();
};

#endif