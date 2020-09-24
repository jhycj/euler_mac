//
//  5000_뒤집기.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
using namespace std;

stack<int> S;
int map[10][10];
int min_size = 10;
int is_end = 0;
stack<int> A;

void change_color(int y, int x){
    
    if(map[y][x] == 0){
        map[y][x] = 1;
    }
    else if(map[y][x] ==1){
        map[y][x] = 0;
    }
}


void push_button(int N){
    int y, x;
    int dy[9] = {-1,-1,-1,0,0,0,1,1,1};
    int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
    
    if(N%3 ==0){
        y = N/3;
        x = 3;
    }
    else{
        y = (N/3) +1;
        x = (N%3) ;
    }

    for(int i=0; i<9; i++){
        int ty = y+dy[i];
        int tx = x + dx[i];
        
        if(ty>=1 && ty<= 3 && tx>=1 && tx<= 3){
            change_color(ty, tx);
        }
    }
}

bool is_all_white(){
    int count = 0;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(map[i][j] ==1){
                count++;
            }
        }
    }
    if(count == 9){
        return true;
    }
    else{
        return false;
    }
}

void print_stack(stack<int> S){
    
    stack<int> rev_S;
    while(!S.empty()){
        int tmp = S.top();
        rev_S.push(tmp);
        S.pop();
    }
    while(!rev_S.empty()){
        int tmp = rev_S.top();
        printf("%d", tmp);
        rev_S.pop();
    }
}

void process(){
    
    if(is_all_white() == true){
        int tmp_size = S.size();
        if(tmp_size < min_size){
            A = S;
        }
        //print_stack(S);
        return ;
    }
    else{
        int N;
        
        
        N = S.top();
        
        for(int i=N+1; i<=9  ; i++){
            S.push(i);
            push_button(i);
            process();
            push_button(i);
            S.pop();
        }
    }
}

int main(){
    
    char input[10];
    
    scanf("%s", input);
    
    for(int i=1; i<=9; i++){
        int y, x;
        char tmp = input[i-1];
        if(i%3 ==0){
            y = i/3;
            x = 3;
        }
        else{
            y = (i/3) +1;
            x = (i%3) ;
        }
        if(tmp=='b'){
            map[y][x] = 0;
        }
        else if(tmp=='w'){
            map[y][x] = 1;
        }
    }
    
    for(int i=1; i<=9; i++){
        S.push(i);
        push_button(i);
        process();
        push_button(i);
        S.pop();
    }
    print_stack(A); 
    
    return 0;
}
