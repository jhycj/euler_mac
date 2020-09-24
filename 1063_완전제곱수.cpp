//
//  1063_완전제곱수.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>

using namespace std;



int main(){
    int M, N;
    int sum = 0;
    int min = 100001;
    int count = 0;
    cin>> M>> N;
    
    int sq_M = sqrt(M);
    int sq_N = sqrt(N);
    
    for(int i=sq_M; i<= sq_N+1; i++){
        if(i*i >= M && i*i <=N){
            count++;
            sum += i*i;
            
            if(count==1){
                min = i*i;
            }
            
        }
    }
    if(count >0){
        printf("%d\n", sum);
        printf("%d", min);
    }
    else{
        printf("-1");
    }
    
    
    return 0;
}
