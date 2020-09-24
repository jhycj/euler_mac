//
//  1075_삼각형.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int over_10(int n){
    int ret;
    ret = n % 9;
    
    if(ret == 0){
        ret = 9;
    }
    return ret;
}


void print_line(int n, int S, int tab){
    int sum = S;
    for(int i=0; i<n; i++){
        printf("%d ", sum);
        sum = over_10(sum+i + tab);
    }
    printf("\n");
}


int main(){
    
    int N, S;
    cin>> N>> S;
    
    int sum = S;
    sum = over_10(sum);
    for(int i=0; i<N; i++){
        
        for(int j=0; j<i; j++){
            printf(" ");
        }
        print_line(N-i, sum, i+1);
        //printf("%d ", sum);
        sum = sum+ (i+2);
        sum = over_10(sum);
        
    }
    
    return 0;
}
