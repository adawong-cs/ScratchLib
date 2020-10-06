#pragma once

#include "shape.h"
#include "point.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace geom
{
	class circle : public shape
	{
	public:
		circle()
		{
			radius = 0.0f;
		}

		circle(float r)
		{
			radius = r;
		}

		virtual float perimeter() const override
		{
			return 2.f * radius * M_PI;
		}

		virtual float area() const override
		{
			return radius * radius * M_PI;
		}




		float radius;
		pointf pos;
	};
}
