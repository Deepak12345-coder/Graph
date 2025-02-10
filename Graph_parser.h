#pragma once

#pragma once

#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


class Graph_parser {
public:
    Graph_parser();  
    void parse_graph_file();  
    unordered_map<char, std::vector<char>> adjlist; 

private:
    fstream file;  
};

