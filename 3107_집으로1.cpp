//
//  3107_집으로1.cpp
//  euler_mac
//
//  Created by Mac on 9/23/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#define INF 10000000
#include <stdio.h>
#include<iostream>
using namespace std;

int N; int E;
int weight[1001][1001];

int dist[1001];
int visit[1001];

void init(){
    
    for(int i=1; i<=N; i++){
        visit[i] = 0;
        dist[i] = INF;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            weight[i][j] = INF;
        }
    }
    
    
}
int min(int a, int b){
    if(a< b){
        return a;
    }
    else{
        return b;
    }
}


void dijsktra(){
    
    for(int i=1; i<= N; i++){
        
        int min_id = -1;
        int min_dist = INF;
        
        for(int j=1; j<=N; j++){
            if(visit[j] ==0 && min_dist > dist[j] ){
                min_dist = dist[j];
                min_id = j;
            }
        }
        visit[min_id] = 1;
        for(int j=1; j<=N; j++){
            if(dist[j]> weight[min_id][j] + min_dist){
                dist[j] = weight[min_id][j] + min_dist;
            }
        }
        
    }
    
}


int main(){
    
    cin>> N >> E;
    init();
    dist[1] = 0;
    for(int i=0; i<E; i++){
        int a,b,c;
        cin>>a>>b>>c;
        weight[a][b] = min(min(weight[a][b], weight[b][a]), c);
        weight[b][a] = weight[a][b];
        
    }
    /*
    printf("\n");
    for(int i=1; i<=N; i++){
     for(int j=1; j<=t[N; j++){
     printf("%d ", weight[i][j]);
     }
     printf("\n");
     }
     */
    dijsktra();
    printf("%d", dist[N]);
}
