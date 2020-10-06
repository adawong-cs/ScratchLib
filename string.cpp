#include "string.h"
#include <iostream>
#include <algorithm>

ada::string::string()
{}

ada::string::string(const char* s)
{
	while (*s != 0)
	{
		v.push_back(*s);
		s++;
	}
}


int ada::string::size() const
{
	return v.size();
}

char ada::string::at(int index) const
{
	return v.get(index);
}

void ada::string::push_back(char c)
{
	v.push_back(c);
	
}

void ada::string::erase(int index, int length)
{
	for (int i = 0; i < length; i++)
	{
		v.erase(index);
	}
}

ada::string ada::string::operator+(const string& a) const
{
	string together;
	together += *this;
	together += a;
	return together;
}

ada::string& ada::string::operator+=(const string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		push_back(a.at(i));
	}
	return *this;
}

ada::string ada::string::operator*(int n)
{
	string multiplied;
	for (int i = 0; i < n; i++)
	{
		multiplied += *this;
	}
	return multiplied;
}

bool ada::string::operator==(const string& a) const
{
	if (size() != a.size())
	{
		return false;
	}

	for (int i = 0; i < size(); i++)
	{
		if (a.at(i) != at(i))
		{
			return false;
		}
	}
	return true;
}

bool ada::string::operator<(const string& a) const
{
	for (int i = 0; i < std::min(size(), a.size()); i++)
	{
		if (at(i) != a.at(i))
		{
			if (at(i) < a.at(i))
			{
				return true;
			}
			return false;
		}
	}

	return (size() < a.size());
}

ada::string ada::string::substr(int index, int length) const
{
	const int endIndex = (length < 0) ?
		size() :
		std::min(index + length, size());

	string sub;

	for (int i = index; i < endIndex; i++)
	{
		sub.push_back(at(i));
	}
	return sub;
}



