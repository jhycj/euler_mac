//
//  4203_스도쿠.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

stack<pair<int,int>> S;

int arr[9][9]{};
int zero_count = 0;
using namespace std;

int count_zero(){
    int ret = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] == 0){
                ret ++;
            }
        }
    }
    return ret;
}

pair<int,int> find_next_zero(){
    pair<int,int> retP;
    int is_end = 0;
    for(int i = 0; i<9; i++){
        for(int j=0; j<9;j++ ){
            if(arr[i][j] ==0 && is_end ==0){
                retP = make_pair(i, j);
                is_end = 1;
            }
        }
    }
    return retP;
}

vector<int> which_num_input(int y, int x){
    vector<int> ret;
    int visit[10]{};
    //row
    for(int i=0; i<9; i++){
        int num = arr[y][i];
        visit[num] = 1;
    }
    //col
    
    for(int i=0; i<9; i++){
        int num = arr[i][x];
        visit[num] = 1;
    }
    //round
    int q_y = y/3;
    int q_x = x/3;
    int c_y = q_y*3 +1;
    int c_x = q_x*3 + 1;
    int dy[9]={-1,-1,-1,0,0,0,1,1,1};
    int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
    
    for(int i=0; i<9; i++){
        int ty = c_y+dy[i];
        int tx = c_x+dx[i];
        int num = arr[ty][tx];
        visit[num] = 1;
    }
    //non visit ==1
    for(int i= 1; i<=9; i++){
        if(visit[i]==0){
            ret.push_back(i);
        }
    }
    return ret;
}

void process(int* is_end){
    
    if(count_zero() ==0){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
        *is_end = 1;
        return ;
    }
    else{
        pair<int,int> P = S.top();
        int y = P.first;
        int x = P.second;
        
        vector<int> num_v = which_num_input(y, x);
        for(int i=0; i<num_v.size() && (*is_end) == 0; i++){
            int input_num = num_v[i];
            arr[y][x] = input_num;
            
            pair<int,int> next_pair = find_next_zero();
            S.push(next_pair);
            process(is_end);
            S.pop();
            arr[y][x] = 0;
        }
        
    }
}





int main(){
    int sy, sx;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int tmp;
            cin>> tmp;
            arr[i][j] = tmp;
            if(tmp==0){
                zero_count++;
                if(zero_count==1){
                    sy = i;
                    sx = j;
                }
            }
        }
    }
    S.push(make_pair(sy, sx));
    int is_end = 0;
    process(&is_end);
    
    return 0;
}
