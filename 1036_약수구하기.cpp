//
//  1036_약수구하기.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int main(){
    int N, K;
    cin>> N>>K;
    stack<int> V;
    for(int i=1; i<=N; i++){
        if(N % i ==0){
            V.push(i);
        }
        if(V.size() == K){
            printf("%d", V.top());
            break;
        }
    }
    if(V.size() <K){
        printf("0");
    }
    
    
    return 0;
}

