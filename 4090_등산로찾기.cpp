//
//  4090_등산로찾기.cpp
//  euler_mac
//
//  Created by Mac on 8/6/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include "4090_등산로찾기.hpp"
#include<iostream>
#include<stack>
#include<utility>
#define INF 999990;
using namespace std;

int N;
int ey, ex;
int map[16][16];
int visit[16][16] ={0,};
int force[16][16];
//int answer[16][16];
stack <pair<int, int>> S;

// pair<int, int> P;



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


void process(pair<int, int> P){
    
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    
    if(P.first == ey && P.second == ex){
        S.push(P);
        
     
        //printf("%d\n", force[ey][ex]);
        /*
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                printf("%d \t", force[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        return;
    }
    
    else{
        
        S.push(P);
        
        int y = P.first;
        int x = P.second;
        //visit[y][x] = 1;
        for(int i=0; i<4; i++){
        
        
            int ty = y+dy[i];
            int tx = x+dx[i];
                
            if(ty>=1 && ty<= N && tx>=1 && tx<=N && visit[ty][tx] != 1){ //방문 아직 안하고 범위에 맞는 격자 들 중에서
                int tmp_force = force[y][x] + return_force_diff(map[y][x], map[ty][tx]);
                
                if(tmp_force > force[ty][tx] || tmp_force >= force[ey][ex] ){ // 기존 저장된 값보다 크면
                    return;
                }
                else{// tmp_force <= force[ty][tx] : 탐색된 지점이므로 스택에 넣는다, 다음 프로세스 진행
                    force[ty][tx] = tmp_force;
                    visit[ty][tx] = 1;
                    pair<int, int> new_P;
                    new_P.first = ty;
                    new_P.second = tx;
                    process(new_P);
                    S.pop();
                    visit[ty][tx] = 0;
                }
            }
        }
    
    }
}

void init_all(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            force[i][j] = INF;
            visit[i][j] = 0;
        }
    }
    while(!S.empty()){
        S.pop();
    }
}



int main(){
    int sy;
    int sx;
    int answer = INF;
    cin>> N;
    cin>>ey>>ex;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i= 1; i<= N; i++){
        for(int j=1; j<=N; j++){
            force[i][j] = INF;
        }
    }
    pair<int, int> P;
    //P.first = 1;
    //P.second = 1;
    //force[1][1] = map[1][1] ;
    //process(P);
    //printf("%d\n", force[ey][ex]);
    
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i!= 1 && i!= N){
                if(j!=1 && j!= N){
                    continue;
                }
                else{
                    sy = i;
                    sx = j;
                }
            }
            else{
                sy =i;
                sx = j;
            }
            
            P.first = sy;
            P.second = sx;
            force[sy][sx] = map[sy][sx] * map[sy][sx];
            visit[sy][sx] = 1; 
            process(P);
            
            if(force[ey][ex] < answer){
                answer = force[ey][ex];
            }
       
            init_all();
        }
        
    }
    printf("%d", answer);
    
    return 0;
}
