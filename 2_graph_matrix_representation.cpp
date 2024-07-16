#include <iostream>
using namespace std;

void add_edge(int matrix[][6], int start, int end) {
    matrix[start][end] = 1;
    matrix[end][start] = 1;
}

void print_matrix(int matrix[][6], int v) {
    for (int i = 0; i < v; i++) {
        cout << i << "->";
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    const int v = 6;
    int matrix[v][v] = {0}; 

    add_edge(matrix, 1, 3);
    add_edge(matrix, 2, 3);
    add_edge(matrix, 3, 4);
    add_edge(matrix, 3, 5);
    add_edge(matrix, 0, 4);
    add_edge(matrix, 0, 3);

    print_matrix(matrix, v);

    return 0;
}