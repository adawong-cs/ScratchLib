#pragma once

namespace ada
{
	template <typename T>
	class list
	{
	private:
		struct node
		{
			T value;
			node* next;
			node* prev;

			node()
			{}

			node(T x)
			{
				value = x;
				next = nullptr;
				prev = nullptr;
			}

			// node n;
			// ...
			// n.find(2);
			//    this = &n;
			node* find(T x)
			{
				//if (value == x)
				//{
				//	return this;
				//}
				//return next->find(x);

				node* curr = this;
				while (curr != nullptr && curr->value != x)
				{
					curr = curr->next;
				}

				return curr;
			}

			void delete_self()
			{
				node* n = this;
				if (prev != nullptr)
				{
					prev->next = next;
				}

				if (next != nullptr)
				{
					next->prev = prev;
				}

				delete n;
			}

			void reverse()
			{
				if (next == nullptr)
				{
					return;
				}
				next->reverse();
				next->next = this;
				next = nullptr;

				//node* curr = this;
				//node* before = nullptr;

				//while (curr != nullptr)
				//{
				//	node* temp = curr->next;
				//	curr->next = before;
				//	curr->prev = temp;

				//	before = curr;
				//	curr = temp;

				//}
			}
		};



	public: 
		list()
		{
			head = nullptr;
			end = nullptr;
			m_size = 0;
		}

		int size() const
		{/*
			node* a = head;
			int count = 0;
			while (a != nullptr)
			{
				a = a->next;
				count++;
			}
			return count;*/
			return m_size;
		}

		bool empty() const
		{
			return (head == nullptr);
		}

		void push_back(T x)
		{
			node* n = new node;
			n->value = x;
			n->next = nullptr;
			n->prev = end;

			if (empty())
			{
				head = n;
			}
			else
			{
				end->next = n;
			}
			end = n;
			m_size++;
		}

		void push_front(T x)
		{
			node* temp = new node;
			temp->value = x;
			temp->next = head;
			temp->prev = nullptr;

			if (empty())
			{
				head = temp;
				end = temp;
			}
			else
			{
				head->prev = temp;
				head = temp;
			}

			m_size++;
		}
		
		void remove(T x)
		{
			node* n = head->find(x);
			if (n == nullptr)
			{
				return;
			}

			n->delete_self();
			m_size--;
		}

		int count(T x) const
		{
			int counter = 0;
			node* n = head;
			while (n != nullptr)
			{
				if (n->value == x)
				{
					counter++;
				}
				n = n->next;
			}
			return counter;
		}

		T get(int index) const
		{
			node* n = head;
			for (int i = 0; i < index; i++)
			{
				n = n->next;
			}
			return n->value;
		}
		
		void insert(int index, T x)
		{
			if (index == 0)
			{
				push_front(x);
				return;
			}
			if (index == m_size)
			{
				push_back(x);
				return;
			}

			node* add = new node(x);
			node* n = head;
			for (int i = 0; i < index; i++)
			{
				n = n->next;
			}

			add->prev = n->prev;
			add->prev->next = add;
			add->next = n;
			n->prev = add;
			m_size++;
		}

		void remove_adjacent_dups()
		{
			node* first = head;
			node* second = head->next;
			
			while (second != nullptr)
			{
				if (first->value == second->value)
				{
					bool isHead = (first == head);
					first->delete_self();
					m_size--;

					if (isHead)
					{
						head = second;
					}

				}
				first = second;
				second = second->next;
			}
		}

	private:

		node* head;
		node* end; 
		int m_size;

	};
}

