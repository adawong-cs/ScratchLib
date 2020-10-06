#pragma once

namespace ada
{
	template <typename T>
	class vector
	{
	public:
		vector()
		{
			m_size = 0;
			m_capacity = 5;
			m_arr = new T[m_capacity];
		}

		explicit vector(int n, T val = T())
		{
			m_size = n;
			m_capacity = n;
			m_arr = new T[m_capacity];
			for (int i = 0; i < m_size; i++)
			{
				m_arr[i] = val;
			}

		}
		~vector()
		{
			if (m_arr)
			{
				delete[] m_arr;
				m_arr = nullptr;
			}
		}

		vector(const vector<T>& v)
		{
			m_arr = nullptr;
			*this = v;
		}

		void push_back(T x)
		{
			if (m_size == m_capacity)
			{
				m_capacity *= 2;
				T* original = m_arr;
				m_arr = new T[m_capacity];
				for (int i = 0; i < m_size; i++)
				{
					m_arr[i] = original[i];
				}
				delete[] original;
			}

			m_arr[m_size] = x;
			m_size++;
		}

		int size() const
		{
			return m_size;
		}

		T get(int index) const
		{
			return m_arr[index];
		}

		void set(int index, T x)
		{
			m_arr[index] = x;
		}

		T& operator[](int index)
		{
			return m_arr[index];
		}

		const T& operator[](int index) const
		{
			return m_arr[index];
		}

		int first_index_of(T x, int starting = 0) const
		{
			for (int i = starting; i < size(); i++)
			{
				if (m_arr[i] == x)
				{
					return i;
				}
			}
			return -1;
		}

		void erase(int index)
		{
			for (int i = index; i < m_size - 1; i++)
			{
				m_arr[i] = m_arr[i + 1];
			}
			m_size--;
		}

		T& back()
		{
			return m_arr[m_size - 1];
		}

		const T& back() const
		{
			return m_arr[m_size - 1];
		}

		T& front()
		{
			return m_arr[0];
		}

		const T& front() const
		{
			return m_arr[0];
		}

		void clear()
		{
			m_size = 0;
		}

		void pop_back()
		{
			erase(m_size - 1);
		}

		void pop_front()
		{
			erase(0);
		}

		vector<T>& operator=(const vector<T>& v)
		{
			if (m_arr != nullptr)
			{
				delete[] m_arr;
			}

			m_size = v.m_size;
			m_capacity = v.m_capacity;
			m_arr = new T[m_capacity];
			for (int i = 0; i < m_size; i++)
			{
				m_arr[i] = v.m_arr[i];
			}

			return *this;
		}

	private:
		T* m_arr;
		int m_size;
		int m_capacity;
	};
}
