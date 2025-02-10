#include "Graph.h"
#include "Graph_parser.h"
#include <iostream>
#include <queue>




Graph::Graph() {
    Graph_parser parser;
    set_adjlist(parser.adjlist);
    visited.resize(list.size(), false);
}

void Graph::set_adjlist(unordered_map<char, vector<char>> adjlist) {
    list = adjlist;
}

void Graph::print_graph() {
    cout << list.size() << " vertices" << endl;
    for (auto it : list) {
        cout << it.first << "-->";
        for (auto node : it.second) {
            cout << node << " ";
        }
        cout << endl;
    }
}

void Graph::breath_first_search(char node) {
    queue<char> q;
    q.push(node);
    visited[node - 'a'] = true; 

    while (!q.empty()) {
        char temp = q.front();
        q.pop();
        cout << temp << " ";  
        for (auto node1 : list[temp]) {
            if (!visited[node1 - 'a']) {  
                visited[node1 - 'a'] = true;
                q.push(node1);
            }
        }
    }
    cout << endl;
}

int Graph::connected_component() {
    int count_components = 0;
    for (auto it : list) {
        char node = it.first;
        if (!visited[node - 'a']) {
            count_components++;
            cout << "components:" << count_components;
            breath_first_search(node);
            cout << endl;
        }
    }
    return count_components;
}

void Graph::minimum_spanning_tree() {
    // Prim's Algorithm for Minimum Spanning Tree
    unordered_map<char, bool> inMST;
    unordered_map<char, int> key;
    unordered_map<char, char> parent;

    for (auto it : list) {
        key[it.first] = INT_MAX;
        inMST[it.first] = false;
    }

    // Choose any starting vertex (e.g., first node)
    key[list.begin()->first] = 0;
    parent[list.begin()->first] = '\0';  // No parent for root node

    for (int count = 0; count < list.size(); count++) {
        // Find the vertex with the minimum key value that is not yet in MST
        char u = '\0';
        int min_key = INT_MAX;
        for (auto it : list) {
            if (!inMST[it.first] && key[it.first] < min_key) {
                min_key = key[it.first];
                u = it.first;
            }
        }

        inMST[u] = true;

        // Update key value and parent index of the adjacent vertices
        for (auto v : list[u]) {
            if (!inMST[v] && key[v] > 1) {  // Replace 1 with appropriate weight if given
                key[v] = 1;  // Assign weight to the edge
                parent[v] = u;
            }
        }
    }

    // Print the Minimum Spanning Tree (MST)
    cout << "Minimum Spanning Tree:" << endl;
    for (auto it : parent) {
        if (it.second != '\0') {
            cout << it.second << " - " << it.first << endl;
        }
    }
}