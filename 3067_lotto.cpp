//
//  3067_lotto.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> S;
vector<int> V;
int visit[14] {};

void print_stack(stack<int> S){
    
    stack<int> A;
    
    while(!S.empty()){
        int tmp = S.top();
        A.push(tmp);
        S.pop();
    }
    A.pop();
    while(!A.empty()){
        int tmp = A.top();
        printf("%d ", tmp);
        A.pop();
    }
    printf("\n");
}


void process(){
    
    if(S.size() == 7){
        print_stack(S);
        return;
    }
    else{
        
        
        for(int i= 0; i<V.size() ; i++){
            int tmp_num = V[i];
            int tmp_num_idx = i;
            int before_num = S.top();
            
            if(visit[tmp_num_idx] == 0 && tmp_num >before_num){
                S.push(tmp_num);
                visit[tmp_num_idx] = 1;
                process();
                visit[tmp_num_idx] = 0;
                S.pop();
            }
        }
        
    }
    
    
}


int main(){
    int K;
    cin>> K;
    for(int i=0; i<K; i++){
        int tmp;
        cin>> tmp;
        V.push_back(tmp);
    }
    S.push(0);
    process();
    
    
    return 0;
}
