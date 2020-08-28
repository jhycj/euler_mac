//
//  4090_등산로찾기2.cpp
//  euler_mac
//
//  Created by Mac on 8/15/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<utility>
#define INF 999999;

using namespace std;

int map[17][17]{};
int force[17][17];
int N;
int ey, ex;
int visit[17][17]{};
stack<pair<int, int>> S;

int return_force_diff(int first_force, int second_force){
    if(second_force> first_force ){
        return (second_force - first_force) * (second_force - first_force);
    }
    else if(second_force == first_force){
        return 0;
    }
    else{
        return (first_force - second_force);
    }
}

void process(){
    
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int top_y = S.top().first;
    int top_x = S.top().second;
    
    if(top_y == 0 || top_y == N+1 || top_x == 0|| top_x == N+1){
        return;
    }

    else{
        
        for(int i=0; i<4; i++){
            
            int ty = top_y + dy[i];
            int tx = top_x + dx[i];
            
            if(ty>=0 && ty<= N+1 && tx>= 0 && tx<= N+1){
               
                if(visit[ty][tx] != 1) {
                    
                    int f = force[top_y][top_x] + return_force_diff(map[ty][tx], map[top_y][top_x]);
                    
                    if(f < force[ty][tx]){
                        force[ty][tx] = f;
                        
                        pair<int, int> P ;
                        P.first = ty;
                        P.second = tx;
                        S.push(P);
                        visit[ty][tx] = 1;
                        process();
                        S.pop();
                        visit[ty][tx] = 0;
                        
                    }
                }
            }
                
        }
    }
}

int main(){
    
    cin>> N;
    cin>> ey >> ex;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            cin >> map[i][j];
            //force[i][j] = INF;
        }
    }
    
    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=N+1; j++){
            force[i][j] = INF;
        }
    }
    
    visit[0][0] = visit[0][N+1] = visit[N+1][0] = visit[N+1][N+1] = 1;
    visit[ey][ex] = 1;
    
    force[ey][ex] = 0;
    pair<int, int> P;
    P.first = ey;
    P.second = ex;
    S.push(P);
    process();
    /*
    for(int i= 0; i<= N+1; i++){
        for(int j=0; j<=N+1; j++){
            printf("%d ", force[i][j]);
        }
        printf("\n");
    }*/
    int min= INF;
    for(int i = 0; i<= N+1; i++){
        for(int j=0; j<=N+1; j++){
            if(i>= 1 && i<=N && j>= 1 && j<= N){
                continue;
            }
            else{
                if(force[i][j] < min){
                    min = force[i][j]; 
                }
            }
        }
    }
    
    printf("%d", min);
    
    return 0;
}
