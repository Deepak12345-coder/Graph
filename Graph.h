#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Graph_parser; 

class Graph {
public:
    Graph(); 
    void print_graph();
    int connected_component();  
    void minimum_spanning_tree();  

    unordered_map<char, vector<char>> list;
    vector<bool> visited;
    void breath_first_search( char node);
    void set_adjlist(unordered_map<char, vector<char>> adjlist);
};
