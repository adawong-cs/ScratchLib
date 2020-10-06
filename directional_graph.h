#pragma once

#include <vector>
#include <set>
#include <map>

template <typename T>
class directional_graph
{
public:
	directional_graph();

	void add(T x);
	virtual void remove(T x);
	virtual void add_edge(T x, T y);
	virtual void remove_edge(T x, T y);

	bool has_node(T x) const;
	bool has_edge(T x, T y) const;
	std::set<T> get_edges(T x) const;

	std::set<T> get_nodes() const;
	std::set<std::pair<T, T>> get_edges() const;

	int num_nodes() const;
	int num_edges() const;

private:

	std::map<T, std::set<T>> edges;
};

template <typename T>
directional_graph<T>::directional_graph()
{
}

template <typename T>
void directional_graph<T>::add(T x)
{
	edges[x];
}

template <typename T>
void directional_graph<T>::remove(T x)
{
	for (auto& p : edges)
	{
		remove_edge(p.first, x);
	}
	edges.erase(x);
}

template <typename T>
void directional_graph<T>::add_edge(T x, T y)
{
	add(x);
	add(y);

	edges.at(x).insert(y);
}

template <typename T>
void directional_graph<T>::remove_edge(T x, T y)
{
	edges[x].erase(y);
}

template <typename T>
bool directional_graph<T>::has_node(T x) const
{
	return edges.count(x);
}

template <typename T>
bool directional_graph<T>::has_edge(T x, T y) const
{
	if (has_node(x))
	{
		return edges.at(x).count(y);
	}
	return false;
}

template <typename T>
std::set<T> directional_graph<T>::get_edges(T x) const
{
	if (has_node(x))
	{
		return edges.at(x);
	}
	return std::set<T>();
}

template <typename T>
std::set<T> directional_graph<T>::get_nodes() const
{
	std::set<T> s;
	for (auto& a : edges)
	{
		s.insert(a.first);
	}
	return s;
}

template<typename T>
std::set<std::pair<T, T>> directional_graph<T>::get_edges() const
{
	std::set<std::pair<T, T>> match;

	for (auto& a : edges)
	{
		for (T b : a.second)
		{
			match.insert({ a.first, b });
		}
	}
	return match;
}

template <typename T>
int directional_graph<T>::num_nodes() const
{
	return edges.size();
}

template <typename T>
int directional_graph<T>::num_edges() const
{
	int total = 0;
	for (auto& a : edges)
	{
		total += a.second.size();
	}
	return total;
}
