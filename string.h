#pragma once

#include "vector.h"

namespace ada
{
	class string
	{
	public:
		string();
		string(const char* s);
		
		int size() const;
		char at(int index) const;
		void push_back(char c);
		void erase(int index, int length);
		string operator+(const string& a) const;
		string& operator+=(const string& a);
		string operator*(int n);
		bool operator==(const string& a) const;
		bool operator<(const string& a) const;
		string substr(int index, int length = -1) const;

	private:
		//member variables
		vector<char> v;

	};
}