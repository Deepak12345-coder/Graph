#include"Graph.h"
#include<iostream>
#include<map>
#include<vector>
#include<stdexcept>
using namespace std;

  

// single node 
int main()
{
	Graph  graph;
	graph.print_graph();
	cout << graph.connected_component() << endl;
	graph.minimum_spanning_tree();
	
	return 0;
}