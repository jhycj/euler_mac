//
//  3023_깊이우선탐색.cpp
//  euler_mac
//
//  Created by Mac on 8/29/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int adjoint[21][21];
int visit[21]{};
int answer[21];
int N;


void dfs(int level, int* is_end_ptr){
        
    if(level>N){
        for(int i=1; i<=N; i++){
            printf("%d ", answer[i]);
        }
    
        *is_end_ptr = 1;
        return;
    }
    else{
        for(int i=1; i<=N; i++){
            int before_idx = answer[level-1];
            if(visit[i] ==0 && adjoint[i][before_idx] ==1 && *is_end_ptr !=1 ){
                visit[i] = 1;
                answer[level]  = i;
                dfs(level+1, is_end_ptr);
                visit[i] = 0;
            }
        }
    }
}


int main(){
    int start_id;
    int is_end = 0;
    cin>> N >> start_id;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N ;j++){
            cin>> adjoint[i][j];
        }
    }
    
    answer[1] = start_id;
    visit[start_id] = 1;
    dfs(2, &is_end);
    return 0;
}
