#ifndef WATCHY_COMMODOREMAZE_H
#define WATCHY_COMMODOREMAZE_H

#include <Watchy.h>
#include "C64_Pro_STYLE9pt7b.h"

class WatchyCommodoreMaze : public Watchy {
    using Watchy::Watchy;
    public:
        void drawWatchFace();
};

#endif