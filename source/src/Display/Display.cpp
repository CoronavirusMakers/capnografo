
#include "Display/Display.h"


v2i Display::ToScreen(v2i position) const
{
    position += offset;
    position.y = GetSize().y - position.y;
    if (bFlippedAxis) // constexpr
    {
        return {position.y, position.x}; // Flip screen
    }
    else
    {
        return position;
    }
}
