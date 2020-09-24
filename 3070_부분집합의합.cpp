//
//  3070_부분집합의합.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

stack<int> S;
int N, sum;
vector<int> SET;

void print_stack(stack<int> S){
    
    stack<int>rev_S;
    while(!S.empty()){
        int top = S.top();
        rev_S.push(top);
        S.pop();
    }
    while(!rev_S.empty()){
        int top = rev_S.top();
        if(top !=0){
            printf("%d ",top);
            
        }
        rev_S.pop();
    
    }
    printf("\n");

}
int sum_stack(stack<int> S){
    int ret = 0;
    while(!S.empty()){
        ret += S.top();
        S.pop();
    }
    return ret;
}

void process(int* sum_ptr){
    if(S.size() == N ){
        if(*sum_ptr == sum){
            print_stack(S);
        
        }
        return;
    }
    else{
        int idx = S.size();
        for(int i=1; i>=0; i--){
            
            if(i==1){
                S.push(SET[idx]);
                *sum_ptr += SET[idx];
            }
            else{
                S.push(0);
            }
            process(sum_ptr);
            //S.pop();
            *sum_ptr -= S.top();
            S.pop();
        
        }
    }
    
}



int main(){
  
    cin>> N>>sum ;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        SET.push_back(tmp);
    }
    
    sort(SET.begin(), SET.end());
    int tmp_sum = 0;
    process(&tmp_sum);
    
    
    return 0;
}
