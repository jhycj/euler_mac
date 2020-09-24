//
//  4367_backtothehome.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<stack>
#include<utility>
using namespace std;

int R, C, K;
int map[5][5];
int sy, sx;
int ey, ex;
int answer = 0;
stack<pair<int,int>> S;

void process(int* answer_ptr){
    if(S.size() <= K && S.top().first == ey && S.top().second == ex){
        (*answer_ptr) ++;
        return; 
    }
    else{
        int dy[4] ={0, 1, 0, -1};
        int dx[4] ={1, 0, -1, 0};
        
        int y= S.top().first;
        int x = S.top().second;
        
        for(int i=0; i<4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            
            if(map[ty][tx] != -1 && ty>=0 && ty<R && tx>=0 && tx<C){ //visit처리 map에서 한번에!
                S.push(make_pair(ty, tx));
                map[ty][tx] = -1;
                process(answer_ptr);
                S.pop();
                map[ty][tx] = 0;
                
                
            }
        }
    }
    
}



int main(){
    cin>> R>>C>>K;
    sy = R-1;
    sx = 0;
    ey = 0;
    ex = C-1;
    char tmp[6];
    for(int i=0; i<R; i++){
        scanf("%s",tmp );
        for(int j=0; j<C; j++){
            if(tmp[j] == 'T'){
                map[i][j] = -1;
            }
            else{
                map[i][j] = 0;
            }
        }
    }
    
    S.push(make_pair(sy, sx));
    map[sy][sx] = -1;
    process(&answer);
    
    printf("%d", answer);
    
    
    
    return 0;
}
