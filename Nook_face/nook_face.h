#ifndef NOOK_FACE_H
#define NOOK_FACE_H

#include <Watchy.h>
#include <Fonts/FreeSerifBoldItalic24pt7b.h>
#include "Colour_Me_Purple_2_9pt7b.h"
#include "icons.h"

class WatchyNookFace : public Watchy {
    using Watchy::Watchy;
    public:
        void drawWatchFace();
};

#endif