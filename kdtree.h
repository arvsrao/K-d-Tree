/*
*
* k-d tree declaration file
*	
* author: Arvind Rao	
* license: GNU
* 
*
*/

#ifndef KDTREE_
#define KDTREE_
#define _USE_MATH_DEFINES

#include <memory>
#include <vector>
#include <list>
#include <cmath>

class Node
{
 public:
	 typedef float numType;
	 std::unique_ptr<Node> left;
	 std::unique_ptr<Node> right;
	 std::vector<numType> data; 
	 
     //default constructor
	 Node(int _n);
	 
	 //copy constructor
	 Node(int _n, std::vector<numType> _data);
	 
	 //default deconstructor
	 ~Node();
	 
	 //returns reference; returned type can be assigned to.
	 numType& operator[](int index);
	     
 private:
	 const int N;
};

class Kdtree
{

 public:
	typedef float                numType;
	typedef std::vector<numType> vecType;
		
	//default constructor
	Kdtree();

	//default deconstructor
	~Kdtree();
	
	//function for finding the median of a list of points
	vecType findMedian(int axis, std::list<vecType> &plist, std::list<vecType> &left, 
								std::list<vecType> &right );
	//function for making the tree
	void makeTree( Node& head, std::list<vecType> &plist, int depth );
};

#include "kdtree.cpp"
#endif