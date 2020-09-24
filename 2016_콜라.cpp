//
//  2016_콜라.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>

using namespace std;



void process(unsigned long N, unsigned long K){
    unsigned long count = 0;
    
    unsigned long remain = N;
    
    while(remain >= K){
        
        unsigned long q = remain / K;
        unsigned long r = remain % K;
        
        count += q * K; 
        remain = q + r;
        
    }
    
    
    unsigned long answer = count + remain;
    printf("%lu", answer);
    
}


int main(){
    
    
    int N, K;
    cin>> N>>K;
    process(N,K); 
}
