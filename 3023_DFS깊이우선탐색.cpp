//
//  3023_DFS깊이우선탐색.cpp
//  euler_mac
//
//  Created by Mac on 9/24/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#include<stack>
#include <stdio.h>
#include<iostream>
using namespace std;
stack<int> S;
stack<int> T;
int N;
int start_id;
int adjoint[21][21];
int visit[21];

void print_stack(stack<int>S){
    stack<int>A;
    while(!S.empty()){
        A.push(S.top());
        S.pop();
    }
    while(!A.empty()){
        printf("%d ", A.top());
        A.pop();
    }
    printf("\n");
}
void process(){
    if(T.size() == N){
        print_stack(T);
        return;
    }
    else{
        int top_n = S.top();
        for(int i=1; i<= N; i++){
            if(visit[i] ==0 && adjoint[top_n][i] == 1){
                T.push(i);
                S.push(i);
                visit[i] =1;
                process();
                S.pop();
                //visit[i] = 0;
            }
        }
        
    }

}


int main(){
    
    cin>> N>>start_id;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>> adjoint[i][j];
        }
    }
    T.push(start_id);
    S.push(start_id);
    visit[start_id] = 1;
    process();
    
    return 0;
}
