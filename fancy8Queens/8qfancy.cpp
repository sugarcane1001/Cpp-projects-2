/*
A fancy version of the classic 8queens problem where the output displays as a chess board showing where the queen chess pieces should go.
*/

#include <iostream>
using namespace std;

bool ok(int q[], int c){
    for(int i=0; i<c; i++)
        if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
    return true;
}

void print (int q[]){
    static int sol_num=0;
    int i,j,k,l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];

    for(i=0; i<5; i++)
        for(j=0; j<7; j++){
            bb[i][j]=char(219);
            wb[i][j]=' ';
        }
    
    static box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' ',char(219),' ',char(219),' ',char(219)},
                     {char(219),' ',' ',' ',' ',' ',char(219)},
                     {char(219),' ',' ',' ',' ',' ',char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
    static box wq = {{' ',' ',' ',' ',' ',' ',' '},
                     {' ',char(219),' ',char(219),' ',char(219),' '},
                     {' ',char(219),char(219),char(219),char(219),char(219),' '},
                     {' ',char(219),char(219),char(219),char(219),char(219),' '},
                     {' ',' ',' ',' ',' ',' ',' '}};

    for(i=0; i<8; i++)
        for(j=0; j<8; j++){
            if((i+j)%2==0) board[i][j]=&bb;
            else board[i][j]=&wb;
        }

    for(int i=0; i<8; i++){
        if((i+q[i])%2==0) board[q[i]][i]=&bq;
        else board[q[i]][i]=&wq;
    }
    
    cout << "Solution #" << ++sol_num << ":\n";

    cout << ' ';
    for(i=0; i<7*8; i++)
        cout << '_';
    cout << endl;

    for(i=0; i<8; i++)
        for(k=0; k<5; k++){
            cout << '|';
            for(j=0; j<8; j++)
                for(l=0; l<7; l++)
                    cout << (*board[i][j])[k][l];
            cout << "|\n";
        }
    cout << ' ';
    for(i=0; i<7*8; i++)
        cout << '_';
    cout << "\n\n";
}

int main(){
    int q[8]={}, c=0;
    q[0]=0;
    while (c>=0){
        c++;
        if(c==8){
            print(q);
            c--;
        } else q[c]=-1;
        while (c>=0){
            q[c]++;
            if(q[c]==8) c--;
            else if (ok(q,c)) break;
        }
    }
    return 0;
}
