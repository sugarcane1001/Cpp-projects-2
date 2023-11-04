/*
This program calculates all the steps needed to transfer n rings from one tower to another in the Towers of Hanoi problem.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    int from = 0, to = (n%2 == 0 ? 2:1), candidate = 1, move = 0;
   
    for(int i = n + 1; i >= 1; --i) t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
   
    while (t[1].size() < (n+1)) {
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
        
        t[to].push_back(candidate);
        t[from].pop_back();
      
        if (t[(to+1)%3].back() < t[(to+2)%3].back()) from = (to+1)%3;
        else from = (to+2)%3;
      
        candidate = t[from].back();

        if(n%2!=0){
            if (t[(from+1)%3].back() < candidate) to = (from+2)%3;                    
            else to = (from+1)%3;
        } else {
            if (t[(from+2)%3].back() < candidate) to = (from+1)%3;                   
            else to = (from+2)%3;
        }
    }
    return 0;
}
