//
//  main.cpp
//  HDU-1848-SG
//
//  Created by ManGo on 16/3/2.
//  Copyright © 2016年 ManGo. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX_N 1005
#define MAX 1005
using namespace std;

int fibo[MAX];
int gs[MAX];

void showData(int *arr, int start, int end) {
    cout<<"showData: ";
    for(int i = start; i<=end; i++){
        cout<<arr[i]<<", ";
        
        if((i + 1) % 36 == 0) cout<<endl;
    }
    cout<<endl;
}

void genFibo() {
    fibo[1] = 1;fibo[2] = 2;
    for(int i = 3; ;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if(fibo[i] > MAX_N) return;
    }
}

struct Cmp { bool operator()(const int& v1, const int& v2){ return v2 < v1;} };

void genGs() {
    gs[0] = 0;
    for(int i = 1; i < MAX; i++) {
        priority_queue<int, vector<int>, Cmp> pq;
        for(int idx = 1;fibo[idx] <= i;idx ++) {
            pq.push(gs[i - fibo[idx]]);
        }
        
        int mex = 0;
        for(;!pq.empty();pq.pop()) {
            if(mex == pq.top()) mex++;
            else if(mex < pq.top()) break;
            else /* mex > pq.top() */ continue;
        }
        gs[i] = mex;
    }
}

int main(int argc, const char * argv[]) {
    int m, n, p;
    genFibo();
    genGs();
    
    queue<int> q;
    for(;;) {
        cin >> m>>n>>p;
        if(m == 0 && n == 0 && p == 0) break;
        q.push((gs[m] ^ gs[n] ^ gs[p]));
    }
    
    for(;!q.empty(); q.pop()) {
        if(q.front()) {
            cout<<"Fibo"<<endl;
        } else cout <<"Nacci"<<endl;
    }
    
    return 0;
}







