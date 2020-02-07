//
//  main.cpp
//  Homework06
//
//  Created by KW on 3/6/19.
//  Copyright © 2019 Ye Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> array, int col) {
    for (int i = 0; i < (int)array.size(); i++) {
        cout << array[i] << ' ';
        if ((i+1) % col == 0)
            cout << endl;
    }
}

vector<int> nextGen(vector<int> oldarr, int row, int col) {
    vector<int> newarr;
    vector<int> count;
    for (int i = 0; i < row * col; i++) {
        newarr.push_back(oldarr[i]);
        count.push_back(0);
    }
    
    for (int i = 0; i < row * col; i++) {
        if (i > col && i % col != 0 && oldarr[i-1-col] == 1) {
            count[i]++;
        }
        if (i >= col && oldarr[i-col] == 1) {
            count[i]++;
        }
        if (i >= col && i % col != (col-1) && oldarr[i+1-col] == 1) {
            count[i]++;
        }
        if (i % col != 0 && oldarr[i-1] == 1) {
            count[i]++;
        }
        if (i % col != (col-1) && oldarr[i+1] == 1) {
            count[i]++;
        }
        if (i % col != 0 && i < (row * col - 1) && oldarr[i-1+col] == 1) {
            count[i]++;
        }
        if (i < (row * col - 1) && oldarr[i+col] == 1) {
            count[i]++;
        }
        if (i < (row * col - 1) && i % col != (col-1) && oldarr[i+1+col] == 1) {
            count[i]++;
        }
    }
    
    for (int i = 0; i < row * col; i++) {
        if (count[i] < 2 || count[i] > 3) {
            newarr[i] = 0;
        } else if (oldarr[i] == 0 && count[i] == 3) {
            newarr[i] = 1;
        } else {
            newarr[i] = oldarr[i];
        }
    }
    return newarr;
}

int main() {

    vector<int> oldarr{0,0,0,0,0,0,0,
                       0,0,1,0,0,0,0,
                       0,0,0,1,0,0,0,
                       0,1,1,1,0,0,0,
                       0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0};

    int row = 6;
    int col = 7;
    vector<int> newarr = nextGen(oldarr, row, col);
    cout << "generation 0: " << endl;
    print(oldarr, col);
    cout << endl;
    newarr = nextGen(oldarr, row, col);
    cout << "generation 1: " << endl;
    print(newarr, col);
    cout << endl;
    for (int i = 2; i < 10; i++) {
        cout << "generation " << i << ": " << endl;
        newarr = nextGen(newarr, row, col);
        print(newarr, col);
        cout << endl;
    }
    
    return 0;
}
