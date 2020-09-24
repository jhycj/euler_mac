//
//  4006_정수의덧셈분해.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>

using namespace std;
stack<int> S;
int idx = 0;

void print_stack(stack<int> S){
    stack<int> A;
    while(!S.empty()){
        int t = S.top();
        A.push(t);
        S.pop();
    }
    int n = A.size();
    for(int i=0; i<n-1; i++){
        int t = A.top();
        printf("%d+", t);
        A.pop();
    }
    printf("%d", A.top());
    printf("\n");
    A.pop();
    

}


void process(int N, int K){
    
    if(N<0){
        return;
    }

    else if( N==0){
        idx++;
        printf("%d : ", idx);
        print_stack(S);
        return;
    }
    
    else if(K==1){
        for(int i=0; i<N; i++){
            S.push(1);
        }
        idx++;
        printf("%d : ", idx);
        print_stack(S);
        for(int i=0; i<N; i++){
            S.pop();
        }
        return;
    }
    
    
    else{
        
        //S.push(K);
        for(int i=1; i<=K; i++){
            S.push(i);
            process(N-i, i);  // (2,1) , (1,2)
            S.pop();
        }
    }
}


int main(){
    
    int N;
    cin>>N;

    
    for(int i=1; i<=N; i++){
        S.push(i);
        process(N-i, i);
        while(!S.empty()){
            S.pop();
        }
    }
    
    printf("partitions = %d\n",idx);
    return 0;
}
