#pragma once

namespace geom
{
	class shape
	{
	public: 
		virtual float perimeter() const = 0;
		virtual float area() const = 0;
	};
}
