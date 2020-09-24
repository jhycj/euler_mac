//
//  4062_hexagon.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int tri_info [7][3];
int visit[7];
stack<int> answer;
stack<int> S;
int maximum = -1;

vector<int> find_tri_idx(int n){ //n을 변의 길이로 갖는 삼각형 번호를 벡터에 저장하여 리턴
    vector<int> V;
    
    for(int i=1; i<=6; i++){
        for(int j=0; j<3; j++){
            if(tri_info[i][j] == n ){
                V.push_back(i);
                break;
            }
        }
    }
    return V;
}

vector<int> sp_tri(int tri_idx , int n){//index 삼각형 중에서 특정 변이 n이 맨 앞에 나오도록 재배치 하여 리턴
    vector<int> ret;
    int a = tri_info[tri_idx][0];
    int b = tri_info[tri_idx][1];
    int c = tri_info[tri_idx][2];
    
    while( a != n){
        int tmp = a;
        a = b;
        b = c;
        c = tmp;
    }
    
    ret.push_back(a);
    ret.push_back(b);
    ret.push_back(c);
    
    return ret;
}

int print_sum(stack<int> S){
    
    int sum = 0;
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }
    return sum;
}


void process(){
    
    if(S.size()>=12){
        int tmp_sum = print_sum(answer);
        
        //printf("%d", tmp_sum);
        
        if(maximum < tmp_sum){
            maximum = tmp_sum;
        }
        return;
    }
    
    else{
        
        int top_len = S.top();
        
        vector<int> non_visit_tri_V = find_tri_idx(top_len);
        for(int i= 0; i<non_visit_tri_V.size(); i++){
            
            int tri_idx = non_visit_tri_V[i];
            if(visit[tri_idx] ==0 ){ //아직 방문 안한 삼각형 인덱스 : tri_idx
                vector<int> ret_V = sp_tri(tri_idx, top_len);
                
                int a = ret_V[0];
                int b = ret_V[1];
                int c = ret_V[2];
                
                S.push(a);
                S.push(b);
                //printf("%d ", c);
                answer.push(c);
                visit[tri_idx] = 1;
                process();
                visit[tri_idx] = 0;
                S.pop();
                S.pop();
                answer.pop();
            }
            
        }
    }
}

void init_all(){
    
    while(!S.empty()){
        S.pop();
    }
    for(int i=1; i<=6; i++){
        visit[i] = 0;
    }
    while(!answer.empty()){
        answer.pop();
    }
    
}


int main(){
    
    for(int i=1; i<=6; i++){
        for(int j=0; j<3; j++){
            int input;
            cin>> input;
            tri_info[i][j] = input;
        }
    }
    /*
    S.push(tri_info[1][0]);
    S.push(tri_info[1][1]);
    //sum += tri_info[1][2];
    answer.push(tri_info[1][2]);
    visit[1] = 1;
    process();
    */
    for(int i=0; i<3; i++){
        
        //S , visit, answer : init
        init_all();
        
        int st_a = tri_info[1][i %3];
        int st_b = tri_info[1][(i+1) % 3];
        int st_c = tri_info[1][(i+2) %3];
        
        S.push(st_a);
        S.push(st_b);
        
        answer.push(st_c);
        visit[1] = 1;
        process();
        
    }
    
    if(maximum <0 ){
        printf("0");
    }
    else{
        printf("%d", maximum);
        
    }
    
    
    return 0;
}
