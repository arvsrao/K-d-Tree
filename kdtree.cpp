/**
*
* k-d tree implementation file
*	
* author: Arvind Rao	
* license: GNU
* 
*
*/


// implementation of Node Class

Node::Node(int _n) : N(_n){ this->data.resize(N); }
Node::Node(int _n, std::vector<Node::numType> _data) : N(_n), data(_data){}

Node::~Node(){}

Node::numType& Node::operator[]( int index)
{
	return this->data[index];
}

// implementation of kdtree

Kdtree::Kdtree(){}
Kdtree::~Kdtree(){}

/*
*
*
*/
Kdtree::vecType Kdtree::findMedian(int axis, std::list<Kdtree::vecType> &plist, std::list<Kdtree::vecType> &left, 
							std::list<Kdtree::vecType> &right )
{
	Kdtree::vecType median;
	int size = plist.size();
	int med = ceil( float(size) / float(2) );
	int count = 0;
	
	if ( size == 1)
		return plist.front();
	
	// Using lambda function here, to define comparison function--parametrized by 'axis'
	plist.sort( [&](Kdtree::vecType& a, Kdtree::vecType& b){return a[axis] < b[axis];});
	
	for ( auto& x : plist )
	{
		if (count <= med)
			left.push_back(x);
		else
			right.push_back(x);
		count++;
	}
	median = left.back();
	left.pop_back();
	return median;
}

/*
*  algorithm is based on http://en.wikipedia.org/wiki/Kd_tree
*/
void Kdtree::makeTree( Node* head, std::list<Kdtree::vecType>& plist, int depth )
{	
	if( !plist.empty() ) 
	{
		int k = plist.front().size();
		int axis = depth % k;
		
		std::list<Kdtree::vecType> left_list;
		std::list<Kdtree::vecType> right_list;
		Kdtree::vecType median = Kdtree::findMedian(axis, plist, left_list, right_list); 
		head->data = median;
		
		Node* left_node = new Node(k);
		Node* right_node = new Node(k);
		
		std::cout<< "in makeTree " << plist.empty() <<"\n";
		Kdtree::makeTree( left_node, left_list, depth+1);
		head->left = left_node;
		
		Kdtree::makeTree( right_node, right_list, depth+1);
		head->right = right_node;
	}
} 