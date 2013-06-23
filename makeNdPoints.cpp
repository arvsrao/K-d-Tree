/*
*  main.cpp
*  
*   k-d Tree Project
*	Created by Arvind Rao on 6/20/13.
*
*/  
#include <iostream>
#include "kdtree.h"
#include <random>
#include <cmath>
#include <vector>
#include <array>

typedef float numType;

std::vector<numType> CreateRandomPoint(const int N)
{
	    numType x;
		std::vector<numType> point;
    
	    //uniformly generate points
	    std::random_device rd;
	    std::default_random_engine generator( rd() );
	    std::uniform_real_distribution< numType > uniform_distribution(0, 10);
    	
		for( auto i=0; i < N; i++)
		{
	        x = uniform_distribution( generator );
	        point.push_back( x );
	    }
		
		return point;
}


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
	
    int n; // dimension of the point space
	const int M = 10; //number of points to generate
    
    if( argc < 2)
    {
        std::cerr<< "Must include a number!!\n";
        return 0;
    }
    n = std::atoi( argv[1] );
	
	//create list of M random points
	std::vector<numType> pt;
	for(auto i=0; i < M ; i++)
	{
		pt = CreateRandomPoint(n);
		print( pt );	
	}
}
