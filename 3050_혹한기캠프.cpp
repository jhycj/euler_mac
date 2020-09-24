//
//  3050_혹한기캠프.cpp
//  euler_mac
//
//  Created by Mac on 9/23/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#define INF 2500000
#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int E;
int start_id;
int end_id;
int dist[2502];
int weight[2501][2501];
int visit[2502];

void init(){
    
    for(int i=1; i<=N; i++)
    {
        dist[i] = INF;
        visit[i] = 0;
    }
    for(int i=1; i<= N; i++){
        for(int j=1; j<=N; j++){
            weight[i][j] = INF;
        }
    }
}

int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}


void dijsktra(){
    
    for(int i=1; i<= N; i++){
        
        int min_id =-1;
        int min_dist = INF;
        
        for(int j=1; j<= N; j++){
            if(dist[j] < min_dist && visit[j] ==0){
                min_id = j;
                min_dist = dist[j];
            }
        }
        visit[min_id] = 1;
        for(int j=1; j<=N; j++){
            if(weight[min_id][j] + min_dist < dist[j] ){
                dist[j] = weight[min_id][j] + min_dist;
            }
        }
    }
    
}


int main(){
    
    cin>> N>>E>> start_id>> end_id;
    init();
    for(int i=0; i<E; i++){
        int a, b, c;
        cin>> a>>b>>c;
        weight[a][b] = min(weight[a][b], c);
        weight[b][a] = weight[a][b];
        
    }
    dist[start_id] = 0;
    /*
    printf("\n");
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", weight[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     */
    dijsktra();
    printf("%d", dist[end_id]); 
    
    return 0;
}
