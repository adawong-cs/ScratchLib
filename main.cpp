#include <iostream>

#include "vector.h"
#include "stack.h"
#include "list.h"
#include "string.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "bidirectional_graph.h"
#include "nodes.h"
#include "graph_funcs.h"

#include <time.h>
#include <assert.h>


void TestVector()
{




	ada::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	ada::vector<ada::vector<char>> nested(7, ada::vector<char>(5, 'x'));
	(nested[3])[1] = 'z';

	for (int i = 0; i < nested.size(); i++)
	{
		for (int j = 0; j < nested[i].size(); j++)
		{
			std::cout << nested[i][j] << " ";
		}
		std::cout << std::endl;
	}

	ada::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	
	//v.set(3, 100);
	v[3] = 100;
	v.erase(2);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

	std::cout << v.first_index_of(4,2) << std::endl;

	ada::vector<std::string> v2(5, "ada");
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}	
}

void TestStack()
{
	ada::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	std::cout << s.size() << std::endl;

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	if (s.empty())
	{
		std::cout << "empty" << std::endl;
	}


}

void TestList()
{
	ada::list<int> l;
	l.push_back(5);
	l.push_back(3);
	l.push_front(2);
	l.push_front(3);
	assert(l.count(3) == 2);
	assert(l.count(2) == 1);
	assert(l.count(10) == 0);

	assert(l.get(0) == 3);
	assert(l.get(1) == 2);
	assert(l.get(2) == 5);
	assert(l.get(3) == 3);

	l.insert(0, 1);
	assert(l.get(0) == 1);
	l.insert(2, 10);
	assert(l.get(2) == 10);
	l.insert(l.size(), 12);
	assert(l.get(l.size() - 1) == 12);

	ada::list<std::string> sortedlist;
	sortedlist.push_back("ant");
	sortedlist.push_back("ant");
	sortedlist.push_back("ant");
	sortedlist.push_back("ant");
	sortedlist.push_back("back");
	sortedlist.push_back("back");
	sortedlist.push_back("back");
	sortedlist.push_back("came");
	sortedlist.push_back("came");
	sortedlist.push_back("den");
	sortedlist.push_back("den");
	sortedlist.push_back("elephant");
	sortedlist.push_back("elephant");
	sortedlist.remove_adjacent_dups();
	assert(sortedlist.size() == 5);
	assert(sortedlist.get(0) == "ant");
	assert(sortedlist.get(4) == "elephant");




	





}

void TestString()
{
	ada::string s;
	s.push_back('a');
	s.push_back('d');
	s.push_back('m');
	assert(s.size() == 3);
	assert(s.at(0) == 'a');
	assert(s.at(1) == 'd');
	assert(s.at(2) == 'm');
	s.erase(0, 2);
	assert(s.size() == 1);
	assert(s.at(0) == 'm');
	s = "ada";

	ada::string m = "jaime";
	assert(m.size() == 5);
	assert(m.at(0) == 'j');
	assert(m.at(1) == 'a');
	assert(m.at(2) == 'i');
	assert(m.at(3) == 'm');
	assert(m.at(4) == 'e');
	
	ada::string t = s + m;
	std::string a = "adajaime";
	assert(t.size() == a.size());
	for (int i = 0; i < t.size(); i++)
	{
		assert(t.at(i) == a.at(i));
	}

	ada::string x = ada::string("123") * 3;
	assert(x == "123123123");

	assert(s < m);
	assert(t.substr(3) == "jaime");
	assert(t.substr(1, 4) == "daja");

}

void TestPoint()
{
	geom::point<int> pA(3, 4);
	geom::point<int> pB = {2, 1};

	pA += pB;
	assert(pA.x == 5);
	assert(pA.y == 5);
	geom::pointi pC = pA + pB;
	assert(pC.x == 7);
	assert(pC.y == 6);

	geom::pointf pf = { 2.0f, 3.0f };
}

void printShapeInfo(const geom::shape& s)
{
	using namespace std;

	cout << s.area() << " " << s.perimeter() << endl;
}

void TestShape()
{
	geom::rectangle r(3.0f, 4.0f);
	assert(r.perimeter() == 14.0f);
	assert(r.area() == 12.0f);

	geom::circle c(5.0f);
	//assert(c.perimeter() == 2.f * 5.f * M_PI);
	//assert(c.area() == 5.f * 5.f * M_PI);

	geom::square sq(10.f);

	ada::vector<geom::shape*> shapes;
	shapes.push_back(&r);
	shapes.push_back(&c);
	shapes.push_back(&sq);

	for (int i = 0; i < shapes.size(); ++i)
	{
		printShapeInfo(*shapes[i]);
	}

}

template <typename T>
using bd_graph = bidirectional_graph<T>;
template <typename T>
using d_graph = directional_graph<T>;

void TestGraph()
{
	bd_graph<std::string> bg;
	bg.add_edge("ada", "jaime");
	assert(bg.num_edges() == 2);
	assert(bg.num_nodes() == 2);
	assert(bg.has_edge("ada", "jaime"));
	assert(bg.has_edge("jaime", "ada"));

	d_graph<int> d;
	d.add_edge(5, 3);
	d.add_edge(3, 1);
	d.add_edge(3, 8);
	d.add_edge(3, 2);
	d.add_edge(2, 9);
	d.add_edge(7, 6);

	assert(IsConnected(d, 5, 9, true) == true);
	assert(IsConnected(d, 7, 6, true) == true);
	assert(IsConnected(d, 3, 9, true) == true);
	assert(IsConnected(d, 5, 6, true) == false);

	assert(IsConnected(d, 5, 9) == true);
	assert(IsConnected(d, 7, 6) == true);
	assert(IsConnected(d, 3, 9) == true);
	assert(IsConnected(d, 5, 6) == false);

	std::vector<int> path = { 5, 3, 2, 9 };
	assert(FindPathBFS(d, 5, 9) == path);
	std::vector<int> patha = { 5, 3, 8};
	assert(FindPathBFS(d, 5, 8) == patha);	
}

void TestTrees()
{
	binary_node<int> a;
	a.data = 2;
	binary_node<int> b;
	b.data = 4;
	binary_node<int> c;
	c.data = 5;
	binary_node<int> d;
	d.data = 8;
	binary_node<int> e;
	e.data = 9;
	binary_node<int> f;
	f.data = 10;

	a.left = &b;
	a.right = &c;

	b.left = &d;
	b.right = &e;
	
	c.left = &f;
	c.right = nullptr;

	d.left = nullptr;
	d.right = nullptr;

	e.left = nullptr;
	e.right = nullptr;

	f.left = nullptr;
	f.right = nullptr;

	assert(BinaryTreeSize(&a) == 6);
	assert(BinaryTreeSum(&a) == 38);
	assert(BinaryTreeMaxPath(&a) == 17);
	assert(AreBinaryTreesEqual(&a, &a) == true);
	assert(AreBinaryTreesEqual(&a, &b) == false);
	PrintBinaryTree(&a);
	BinaryTreeFlip(&a);
	PrintBinaryTree(&a);



}

int main(int argc, char* argv[])
{
	srand(time(0));
	//TestList();
	//TestStack();
	//TestVector();
	//TestString();
	//TestPoint();
	//TestShape();
	//TestGraph();
	TestTrees();

	std::cout << "All of your tests passed!" << std::endl;

	std::vector<std::string> messages = {
		"You rock!",
		"Great job!",
		"Nice!!",
		"Awesome!"
	};

	std::cout << messages[rand() % messages.size()] << std::endl;
}