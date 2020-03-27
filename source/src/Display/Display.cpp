
#include "Display/Display.h"


v2i Display::ToScreen(v2i position) const
{
    position += offset;
    if (bFlippedAxis) // constexpr
    {
        return {position.y, position.x}; // Flip screen
    }
    else
    {
        return position;
    }
}
