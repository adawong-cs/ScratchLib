#pragma once

namespace geom
{
	template <typename T>
	class point
	{
	public:
		point()
		{
			x = T();
			y = T();
		}

		point(T a, T b)
		{
			x = a;
			y = b;
		}


		void operator+=(const point<T>& p)
		{
			x = x + p.x;
			y = y + p.y;
		}
		
		point<T> operator+(const point<T>& p) const
		{
			point<T> pC = *this;
			pC += p;
			return pC;
		}

		T x;
		T y;
	};

	using pointi = point<int>;
	using pointf = point<float>;
	using pointd = point<double>;

}