#pragma once
#include "shape.h"
#include "point.h"

namespace geom
{
	class rectangle : public shape
	{
	public:
		rectangle()
		{
		}

		rectangle(float x, float y)
		{
			size.x = x;
			size.y = y;
			
		}

		virtual float perimeter() const override
		{
			return size.x + size.x + size.y + size.y;
		}

		virtual float area() const override
		{
			return size.x * size.y;
		}
		
		pointf size;
		pointf pos;
	};
}