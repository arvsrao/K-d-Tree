#define _USE_MATH_DEFINES
/*
*   main.cpp
*  
*   k-d Tree Project
*	author: Arvind Rao
*   license: GNU 
*
*/  
#include <iostream>
#include "kdtree.h"
#include <random>
#include <cmath>
#include <vector>
#include <list>
#include <array>
#include <memory>

typedef float numType;
const int _numpts = 10;
const int _dim = 3;

numType testpoints[_numpts][_dim] =
	{
		{8.40924, 4.11543, 8.10499}, 
		{6.50689, 1.3663, 3.43026}, 
		{9.7614, 9.8382, 0.672512}, 
		{0.113181, 2.22785, 3.46726}, 
		{5.23381, 4.69416, 4.74723}, 
		{9.74655, 0.191659, 1.20641}, 
		{2.8546, 7.32662, 8.51895}, 
		{6.21829, 0.779546, 1.82988}, 
		{8.83612, 8.70544, 2.40537}, 
		{6.50697, 2.70078, 1.93852} 
	};


void print(std::vector<numType> pt)
{
	for( auto i = 0; i < pt.size(); i++)
	{
	    std::cout<< pt[i] << ", ";
	}
	std::cout<<"\n";
}

int main(int argc, char ** argv)
{
	typedef std::vector<numType> vecType;
    int n; // dimension of the point space    
    if( argc < 2)
    {
        std::cerr<< "Must include a number!!\n";
        return 0;
    }
    n = std::atoi( argv[1] );
	
	//make a list of vectors out of the testpoints array
	std::list<vecType> point_list;
	for(auto i = 0; i < _numpts; i++ )
	{
		vecType pt; 
		for( auto j = 0; j < _dim; j++) pt.push_back( testpoints[i][j] );
		point_list.push_back(pt);
	}
	
	point_list.sort( [&](Kdtree::vecType& a, Kdtree::vecType& b){ return a[1] > b[1];} );
	for ( auto& x : point_list )
	{
		print(x);
	}
	
	Kdtree kd;
	Node* head = new Node(3);
	kd.makeTree(head, point_list,0);
	
	/*Node head(3, point_list.front());	
	std::unique_ptr<Node> a = std::unique_ptr<Node>( new Node(3) );
	std::unique_ptr<Node> b;
	a -> data = head.data;
	print(a->data);
	*/
}