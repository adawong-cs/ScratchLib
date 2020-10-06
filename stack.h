#pragma once

#include "vector.h"

namespace ada
{
	template <typename T>
	class stack
	{
	public: 
		stack()
		{}


		//methods
		void pop()
		{
			v.pop_back();
		}
		T top() const
		{
			return v.back();
		}
		void push(T x)
		{
			v.push_back(x);
		}
		int size() const
		{
			return v.size();
		}
		bool empty()
		{
			return v.size() == 0;
		}

	private:
		ada::vector<T> v;

		
	};


}
