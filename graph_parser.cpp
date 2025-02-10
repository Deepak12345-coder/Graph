#include "Graph_parser.h"
#include <iostream>

using namespace std;

Graph_parser::Graph_parser() {
    file.open("notation.txt");  
    if (!file.is_open()) {
       throw runtime_error("File is not opening");
    }
    Graph_parser::parse_graph_file();
}

void Graph_parser::parse_graph_file() 
{
    string line;
    while (getline(file, line)) {
        if (line.length() >= 5) {
            char vertex1 = line[1];
            char vertex2 = line[3];
            adjlist[vertex1].push_back(vertex2);
            adjlist[vertex2].push_back(vertex1);
        }
    }
    file.close();
}