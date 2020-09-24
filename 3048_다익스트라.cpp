//
//  3048_다익스트라.cpp
//  euler_mac
//
//  Created by Mac on 9/16/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#define INF 500
int V; //1<=N<=100
int E;
int adjoint[101][101]{};
using namespace std;
int dist[101] ;
int visit[101]{};
int from_where[101];
int start_id;
int end_id;
stack<int> S;
bool is_end = false;
void init_process(){
    
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            adjoint[i][j] = INF;
        }
    }
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }
    dist[start_id] = 0;
    //visit[start_id] = 1;
    
}

bool check_is_end(){
    if(visit[end_id] == 1){
        return true;
    }
    else{
        return false;
    }
}


void process(){
    
    for(int k=1; k<=V; k++){
        int min_dist = INF;
        int min_id = -1;
        //방문 안한 정점들 중 , start로부터 최소 거리 갖는 정점 인덱스 찾기
        for(int i=1; i<=V; i++){
            if(visit[i] ==0 && dist[i] < min_dist){
                min_dist = dist[i];
                min_id = i;
            }
        }
        visit[min_id] = 1;
    
        for(int j=1; j<=V; j++){
        
            if(dist[j] > min_dist + adjoint[min_id][j]){
                dist[j] = min_dist + adjoint[min_id][j];
                from_where[j] = min_id;
            }
        }
    }
    
}

void push_stack(int after_id){
    if(after_id == start_id){
        S.push(after_id);
        return;
    }
    else{
        S.push(after_id);
        int next_id = from_where[after_id];
        push_stack(next_id);
    }
}

void print_stack(){
    while(!S.empty()){
        int t = S.top();
        printf("%d ", t);
        S.pop();
    }
}



int main(){
    
    cin>>V >> start_id>> end_id;
    cin>> E;
    init_process();
    for (int i=0; i<E; i++){
        
        int tmp1, tmp2, w;
        cin>>tmp1>>tmp2>>w;
        adjoint[tmp1][tmp2] = w;
        
    }
    
    
    process();
    
    printf("%d\n", dist[end_id]);
    

    
    //S.push(end_id);
    push_stack(end_id);
    
    printf("%d\n", S.size());
    print_stack();
    return 0;
}
