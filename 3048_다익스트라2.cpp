//
//  3048_다익스트라2.cpp
//  euler_mac
//
//  Created by Mac on 9/23/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#define INF 1000
#include <stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int weight[101][101]{};
int dist[101];
int visit[101];
int from_where[101];
stack<int> S;
int N;
int start;
int finish;
int E;


void init(){
    for(int i=1; i<= N; i++){
  
        dist[i] = INF;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            weight[i][j] = INF;
        }
    }
}

void dijsktra(){
    
    for(int j = 1; j<= N; j++){
        int min_dist= INF;
        int now_v = 0;
        for(int i=1; i<=N; i++){ //dist가 최소인 점 찾기.
            if(min_dist > dist[i] && visit[i] ==0){
                now_v = i;
                min_dist = dist[i];
    
            }
        }
        
        visit[now_v] = 1;
        for(int i=1; i<= N; i++){
            if(dist[i] > weight[now_v][i] + min_dist){
                dist[i] = weight[now_v][i] + min_dist ;
                from_where[i] = now_v;
            }
        }
    }
    

}

void print_path(){
    int top_n = S.top();
    while(S.top() != start){
        //printf("%d ",top_n);
        int n = from_where[S.top()];
        S.push(n);
    }
    printf("%d\n", S.size());
}


int main(){
    cin>> N>> start>> finish;
    cin>>E;
    init();
    for(int i=0; i<E; i++){
        int a, b, c;
        cin>> a>>b>>c;
        weight[a][b] = c;
    }
    dist[start] = 0;
    
    dijsktra();
    printf("%d\n", dist[finish]);
    S.push(finish);
    print_path();
    
    while(!S.empty()){
        printf("%d ", S.top());
        S.pop();
    }
    
    
    return 0;
}
