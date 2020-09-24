//
//  3049_최단경로.cpp
//  euler_mac
//
//  Created by Mac on 9/23/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#define INF 50000

using namespace std;
int weight[51][51];
int V;
int E;
int start_id;
int end_id;
int dist[51];
int visit[51];
int from_where[51];
stack<int>S;
void init(){
    for(int i=1; i<=V; i++){
        dist[i] = INF;
        visit[i] = 0;
    }
    dist[start_id] = 0;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            weight[i][j] = INF;
        }
    }
}

void dijsktra(){
    for(int i=1; i<=V; i++){
        
        int min_id = -1;
        int min_dist = INF;
        
        for(int j=1; j<=V; j++){
            if(visit[j] ==0 && (dist[j] < min_dist) ){
                min_dist = dist[j];
                min_id = j;
            }
        }
        visit[min_id] = 1;
        
        for(int j=1; j<=V; j++){
            if(weight[min_id][j] != INF){
                if(min_dist + weight[min_id][j] < dist[j]){
                    dist[j] = min_dist + weight[min_id][j] ;
                    from_where[j] = min_id;
                }
                
            }
            
        }
    }
}
/*
void print_path(){
    while(S.top() != start_id){
        int top_n = S.top();
        int n = from_where[top_n] ;
        S.push(n);
    }
    printf("%d\n", S.size());
    while(!S.empty()){
        printf("%d ", S.top());
        S.pop();
    }
}
*/
void print_path(){
    int answer[100];
    int push_n = end_id;
    int count = 0;
    while(push_n!= start_id){
        answer[count] = push_n;
        count++;
        push_n = from_where[push_n];
    }
    answer[count] = start_id;
    printf("%d\n", count+1);
    for(int i=count; i>=0; i--){
        printf("%d ", answer[i]);
    }
}

int main(){
    cin >> V>> start_id >> end_id;
    cin>>E;
    init();
    for(int i=0; i<E; i++){
        int a, b,c;
        cin>> a>>b>>c;
        weight[a][b] = c;
        weight[b][a] = c;
    }
 
    dijsktra();
    printf("%d\n", dist[end_id]);
    S.push(end_id);
    print_path();
    return 0;
}
