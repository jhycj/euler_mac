//
//  3120_물공급.cpp
//  euler_mac
//
//  Created by Mac on 9/10/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int adjoint[100000][2]{};
vector<pair<int, pair<int, int>>> adjoint_vector;
queue<int> Q;

int answer[100000]{};

pair<int,int> find_children2(int parent_node){
    int child1 =0;
    int child2 = 0;
    
    child1 = adjoint[parent_node][0];
    child2 = adjoint[parent_node][1];
    
    pair<int, int> P = make_pair(child1, child2);
    return P;
}


pair<int,int> find_childeren(vector<pair<int, pair<int,int>>> adjoint_vector, int parent_node){
    int child1 =0;
    int child2 = 0;
    for(int i=0; i<adjoint_vector.size(); i++){
        if(adjoint_vector[i].first == parent_node){
            child1 = adjoint_vector[i].second.first;
            child2 = adjoint_vector[i].second.second;
            break;
        }
    }
    pair<int, int> P = make_pair(child1, child2);
    return P;
}

void bfs(int start_node){
    
    Q.push(start_node);
    pair<int, int> P = find_children2(start_node);
    int child1 = P.first;
    int child2 = P.second;
    if(child1 != 0 && child2!=0){
        Q.push(child1);
        Q.push(child2);
    }
    
    while(!Q.empty()){
        int parent =  Q.front();
        Q.pop();
        int child1 = Q.front();
        P = find_children2(child1);
        if(P.first != 0 && P.second!=0){
            Q.push(child1);
            Q.push(P.first);
            Q.push(P.second);
        }
        
        answer[child1] = answer[parent] + 1;
        Q.pop();
        int child2 = Q.front();
        P = find_children2(child2);
        if(P.first != 0 && P.second != 0){
            Q.push(child2);
            Q.push(P.first);
            Q.push(P.second);
        }
        answer[child2] = answer[parent] + 1;
        Q.pop();
        
    }
    
}



int main(){
    int N, C;
    cin>>N>>C;
    int S, E1, E2;
    for(int i=0; i<C; i++){
        cin>> S>> E1>>E2;
        //pair<int, pair<int,int>> P = make_pair(S, make_pair(E1, E2));
        //adjoint_vector.push_back(P);
        adjoint[S][0] = E1;
        adjoint[S][1] = E2;
        
    }
    answer[1] = 1;
    bfs(1);
    
    for(int i=1; i<=N; i++){
        printf("%d\n", answer[i]);
    }

    
    return 0;
}
