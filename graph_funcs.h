#pragma once

#include "directional_graph.h"
#include "bidirectional_graph.h"
#include "nodes.h"
#include <set>
#include <queue>

namespace
{
	template <typename T>
	bool IsConnectedR(
		const directional_graph<T>& graph,
		const T& x,
		const T& y,
		std::set<T>& visited)
	{

		if (x == y)
		{
			return true;
		}

		if (visited.count(x))
		{
			return false;
		}
		visited.insert(x);

		for (const T& t : graph.get_edges(x))
		{
			if (IsConnectedR(graph, t, y, visited))
			{
				return true;
			}
		}
		return false;
	}

	template <typename T>
	std::vector<T> FindPathBFS(
		const directional_graph<T>& graph,
		const T& x,
		const T& y)
	{
		std::queue<T> q;
		q.push(x);
		std::set<T> visited;
		visited.insert(x);

		/*while (!q.empty())
		{
			const T& value = q.front();

			if (value == y)
			{
				return true;
			}

			for (const T& z : graph.get_edges(value))
			{
				if (!visited.count(z))
				{
					q.push(z);
					visited.insert(z);
				}
			}

			q.pop();
		}*/

		std::map<T, T> back;

		while (!q.empty())
		{
			const T& value = q.front();
			
			if (value == y)
			{
				T a = y;
				std::vector<T> path;
				while (a != x)
				{
					path.push_back(a);
					a = back[a];
				}
				path.push_back(x);
				std::reverse(path.begin(), path.end());

				return path;
			}

			for (const T& z : graph.get_edges(value))
			{
				if (!visited.count(z))
				{
					visited.insert(z);
					q.push(z);
					back[z] = value;
				}
			}
			q.pop();

		}

		return std::vector<T>();
	}
}

template <typename T>
int BinaryTreeSize(const binary_node<T>* tree)
{
	if (tree == nullptr)
	{
		return 0;
	}

	return BinaryTreeSize(tree->right) + BinaryTreeSize(tree->left) + 1;
}

template <typename T>
T BinaryTreeSum(const binary_node<T>* root)
{
	if (root == nullptr)
	{
		return T();
	}

	return BinaryTreeSum(root->right) + root->data + BinaryTreeSum(root->left);
}

template <typename T>
T BinaryTreeMaxPath(const binary_node<T>* root)
{
	if (root == nullptr)
	{
		return T();
	}

	T l = BinaryTreeMaxPath(root->left);
	T r = BinaryTreeMaxPath(root->right);
	return std::max(l, r) + root->data;

}

template <typename T>
void BinaryTreeFlip(binary_node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	BinaryTreeFlip(root->left);
	BinaryTreeFlip(root->right);

	std::swap(root->left, root->right);
}

template <typename T>
bool AreBinaryTreesEqual(const binary_node<T>* a, const binary_node<T>* b)
{
	if (a == nullptr && b == nullptr)
	{
		return true;
	}
	if (a == nullptr || b == nullptr)
	{
		return false;
	}

	//return a->data == b->data &&
	//	AreBinaryTreesEqual(a->left, b->left) &&
	//	AreBinaryTreesEqual(a->right, b->right);

	if (AreBinaryTreesEqual(a->right, b->right))
	{
		if (AreBinaryTreesEqual(a->left, b->left))
		{
			if (a->data == b->data)
			{
				return true;
			}
		}
	}
	return false;
}

template <typename T>
void AssignBuckets(
	const binary_node<T>* root,
	int level,
	std::vector<std::vector<const binary_node<T>*>>& buckets)
{
	if (root == nullptr)
	{
		return;
	}

	if (buckets.size() <= level)
	{
		buckets.resize(level + 1);
	}

	buckets[level].push_back(root);
	AssignBuckets(root->left, level + 1, buckets);
	AssignBuckets(root->right, level + 1, buckets);
}

template <typename T>
void PrintBinaryTree(const binary_node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	// How to do it recursively + iteratively
	//
	//std::vector<std::vector<const binary_node<T>*>> buckets;
	//AssignBuckets(root, 0, buckets);
	//
	//for (auto& bucket : buckets)
	//{
	//	for (auto& node : bucket)
	//	{
	//		std::cout << node->data << ' ';
	//	}
	//	std::cout << std::endl;
	//}

	std::queue<const binary_node<T>*> q;
	q.push(root);

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			const binary_node<T>* value = q.front();
			std::cout << value->data << " ";
			if (value->left != nullptr)
			{
				q.push(value->left);
			}
			if (value->right != nullptr)
			{
				q.push(value->right);
			}
			q.pop();
		}
		std::cout << std::endl;
	}

}

template <typename T>
bool IsConnected(
	const directional_graph<T>& graph,
	const T& x,
	const T& y,
	bool useRecursion = false)
{
	if (useRecursion)
	{
		std::set<T> visited;
		return IsConnectedR(graph, x, y, visited);
	}


	return (!FindPathBFS(graph, x, y).empty());
}
