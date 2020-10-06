#pragma once

#include "directional_graph.h"

template <typename T>
class bidirectional_graph : public directional_graph<T>
{
public:
	virtual void add_edge(T x, T y) override;
	virtual void remove_edge(T x, T y) override;
};

template <typename T>
void bidirectional_graph<T>::add_edge(T x, T y)
{
	directional_graph<T>::add_edge(x, y);
	directional_graph<T>::add_edge(y, x);
}

template <typename T>
void bidirectional_graph<T>::remove_edge(T x, T y)
{
	directional_graph<T>::remove_edge(x, y);
	directional_graph<T>::remove_edge(y, x);
}



