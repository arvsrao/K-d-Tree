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
#include <queue>

class Node
{
 public:
	 typedef float numType;
	 Node* left = nullptr;// = std::unique_ptr<Node>( new Node(3) );
	 Node* right = nullptr; //( new Node(3));
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
	
	/* 
	*   Return the tree root node
	*/
	Node* getRoot();
	/*
	* support function for printTree
	*/
	void print_data(std::vector<numType> pt);
		
	/*  prints the tree
	*   and really works best for small trees 
	*   as a test of tree construction.
	*/  
	void printTree( Node* head );
	
	//function for finding the median of a list of points
	vecType findMedian(int axis, std::list<vecType> &plist, std::list<vecType> &left, 
								std::list<vecType> &right );
	//function for making the tree
	void makeTree( std::list<vecType> &plist );
	
	
 private:
	//helper for makeTree 
	void _makeTree( Node* head, std::list<vecType> &plist, int depth );
	
	Node* root;
};

#include "kdtree.cpp"
#endif