#pragma once

#include "rectangle.h"
#include "point.h"

namespace geom
{
	class square : public rectangle
	{
	public:
		square(float s)
		{
			size.x = s;
			size.y = s;
		}

	};
}