/*
Given an weighted path, this program calculates the cost and the route of the shortest path from one corner to the other.
*/

#include<iostream>
#include <string> 
using namespace std;

const int rows = 5;
const int cols = 6;
string path[rows][cols]; //declare a path matrix, it is a string matrix

int cost(int i, int j) {
    // i is the row, j is the column  
    static int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };

    static int memo[rows][cols] = { 0 }; // declare the static memo matrix
    // If the cost has already been calculated
    if(memo[i][j] != 0)
        return memo[i][j]; //return it.
    
    // base case (leftmost column)
    if (j == 0) {
        // update the base case path matrix
        path[i][0] = to_string(i);
        return weight[i][0];
    }

    // recursive call - cost(i, j) = weight[i][j] + min_cost(left/up/down-row_index j-1)

    int left = cost(i, j - 1); 
    int up = cost((i + rows - 1) % rows, j - 1); 
    int down = cost((i + 1) % rows, j - 1); 

    // find the value of the shortest path through cell (i,j)
    int minCost = left;
    if (up < minCost) minCost = up;
    if (down < minCost) minCost = down;

    // update the path matrix
    if(minCost==left) path[i][j] = path[i][j-1] + to_string(i);
    else if(minCost==up) path[i][j] = path[(i + rows - 1) % rows][j-1] + to_string(i);
    else path[i][j] = path[(i + 1) % rows][j-1] + to_string(i);


    // cost(i, j) = weight[i][j] + min_cost(left/up/down-row_index, j-1)
    memo[i][j] = weight[i][j] + minCost;
    minCost = memo[i][j];

    return minCost;
}

int main() {
    int ex[rows];
    int rowIndex = 0; // initial the rowIndex

    // get the shortest path out of each cell on the right
    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i, cols - 1); // call recursive function to get the shortest path for each exit
        rowIndex = i; // store the row index
    }

    // now find the smallest of them
    int minCost = ex[0];
    for (int i = 1; i < rows; i++) {
        if(ex[i] < minCost)
            minCost = ex[i];
    }
    cout << "The shortest path is of length " << minCost << endl;
    cout << "The rows of the path from left to right are " << path[rowIndex][cols-1] << endl;
    
    return 0;
}
