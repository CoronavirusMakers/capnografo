// Copyright 2020 Miguel Fernandez Arce - All rights reserved
// Based on https://github.com/muit/RiftEngine

#include "Math/v2.h"
#include "Math/v2i.h"

v2::v2(v2i other)
{
	x = float(other.x);
	y = float(other.y);
}
