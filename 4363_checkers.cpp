//
//  4363_checkers.cpp
//  euler_mac
//
//  Created by Mac on 9/4/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<utility>
#include<string>
#include<queue>
using namespace std;
int total_enemy = 0;
int arr[31][31];
stack<pair<int, int>> S;
queue<pair<int, int>> Q;
int N;
void print_stack(stack<pair<int, int>> S){
    
    stack<int>A;
    
    while(!S.empty()){
        int y = S.top().first;
        int x = S.top().second;
        
        A.push(x);
        A.push(y);
        S.pop();
    }
    while(!A.empty()){
        int y = A.top();
        A.pop();
        int x = A.top();
        A.pop();
        printf("%d %d\n", y, x);
    }
}


void process(int* remain_enemy_ptr, int* is_end_ptr){
    
    int dy[4] = {-1, -1, 1, 1};
    int dx[4] = {-1, 1, -1, 1};
    
    int dy1[4] = {-2, -2, 2, 2};
    int dx1[4] = {-2, 2, -2, 2};
    
    if(*remain_enemy_ptr ==0){
        print_stack(S);
        (*is_end_ptr) = 1;
        return;
    }
    else{ //remain_enemy >0
        

        pair<int, int> P = S.top();
        
        int y = P.first;
        int x = P.second;
    
        for(int i=0; i<4 ; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            
            int ty1 = y + dy1[i];
            int tx1 = x + dx1[i];
            
            if(arr[ty][tx] == 0 && ty>=1 && ty1 >=1 && ty<= N && ty1<= N && tx>=1 && tx1>=1 &&tx<= N && tx1<= N && arr[ty1][tx1] == 1 && (*is_end_ptr) ==0 ){
                pair<int, int> next_P ;
                next_P.first = ty1;
                next_P.second = tx1;
                S.push(next_P);
                (*remain_enemy_ptr) --;

                arr[y][x] = 1; //'K' -> '+'
                arr[ty][tx] = 1; // 'o' -> '+'
                arr[ty1][tx1] = -1; // '+' -> 'K'
                process(remain_enemy_ptr, is_end_ptr);
                arr[y][x] = -1; //' +' -> 'K'
                arr[ty][tx] = 0;
                arr[ty1][tx1] = 1;
                (*remain_enemy_ptr)++ ;
                S.pop();
            }
        }
    }
    
    
}

void stack_init(void){
    
    while (!S.empty()){
        S.pop();
    }
}



int main(){
    
    cin>>N;
    
    for(int i=1; i<= N; i++){
        string input;
        cin>>input;
        for(int j=0; j<N; j++){
            char tmp = input[j];
            if(tmp == '+'){
                arr[i][j+1] = 1;
            }
            else if(tmp== '-'){
                arr[i][j+1] = -1;
            }
            else if(tmp== 'o'){
                arr[i][j+1] = 0;
                total_enemy ++;
            }
            else if(tmp == 'K'){
                arr[i][j+1] = -1;
                pair<int, int> P;
                P.first = i;
                P.second = j+1;
                Q.push(P);
            }
        }
    }
    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    */
    int is_end = 0;
    while(!Q.empty() ){
    
        //int is_end = 0;
        int sy = Q.front().first;
        int sx = Q.front().second;
        int remain_enemy = total_enemy;
        S.push(Q.front()); //(sy, sx)
        arr[sy][sx] = 1; //'+'로 바꿈.
        process(&remain_enemy, &is_end);
        //S init시켜야, 1번 출력하면 종료
        stack_init() ;
        arr[sy][sx] = -1;
        Q.pop();
        if(is_end == 1){
            break;
        }
    }
    
    if(is_end ==0){
        printf("impossible");
    }
    
    return 0;
}
