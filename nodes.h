#pragma once

template <typename T>
struct single_node
{
	T data;
	single_node* next;
};

template <typename T>
struct double_node
{
	T data;
	double_node* next;
	double_node* prev;

};

template <typename T>
struct binary_node
{
	T data;
	binary_node* left;
	binary_node* right;
};

template <typename T>
struct node
{
	T data;
	std::vector<node*> children;
};
