/*
Dynamically allocating memory in heap, this project finds the # of solutions where k-bishops can be placed in n*n board with no bishop threatening the others.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
    for (int i = 0; i < c; i++)
        if(q[c]/n-q[i]/n == abs(q[c]%n - q[i]%n)) return false; // if col difference == row difference, bishop c and i are diagonal to each other
        // row # = q[...] % n
        // col # = q[...] / n
    return true;
}

int kBishops(int n, int k) {
    int solutions = 0; 

    int* q = new int[k]; // dynamic allocate an array in heap base on k (num of bishops)

    int c = 0; // place first bishop (c=0) at first (top-left) box (q[c]=0)
    q[c] = 0;
    
    while (c >= 0) {  // Backtracking Algorithm // Bishop-loop (c-loop)
        c++; // NEXT BISHOP
        if (c==k) { // if all the bishop has been put onto the broad
            solutions++; // increment solution count
            c--; // backtrack to look for next solution
        }
        else
            q[c]=q[c-1]; // start from the position of the previous bishop to avoid duplicate solutions
            
        while (c >= 0) { // Position-loop (q[c]-loop)
            q[c]++; // NEXT SQUARE
            if (q[c]==n*n) // If all the squares have been tried (passed the bottomright square) for the bishop
                c--; // backtrack
            else if (ok(q, c, n)) break; // check if it's ok to put the bishop on this sqaure...
        }
    }
    delete [] q; // free up the memory in heap
    return solutions;
}

int main() {
    int n, k; // Declare n and k.
    cout << "Enter value of n: ";  // ask user input for n and k.
    cin >> n; 
    
    if (n <= 0) return 0; // if user input -1 for n, terminate the loop.
    while (n>0){ // otherwise call the kBishop(n, k) function to get the number of solutions.
        cout << "Enter value of k: ";
        cin >> k;
        cout << "number of solutions: " << kBishops(n, k) << "\n\n";
        cout << "Enter value of n: ";
        cin >> n;
    }
    
    return 0;
}
