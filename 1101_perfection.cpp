//
//  1101_perfection.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

void calculate(int N){
    int ret =0;

    if(N==1){
        printf("DEFICIENT\n");
    }
    else{
        for(int i=1; i<N; i++){
            if(N % i==0){
                ret += i;
            }
        }
        if(ret == N){
            printf("PERFECT\n");
        }
        else if(ret <N){
            printf("DEFICIENT\n");
        }
        else{
            printf("ABUNDANT\n");
        }
    }
    
}




int main(){
    
    int A, B, C;
    
    scanf("%d %d %d", &A, &B, &C);
    
    calculate(A);
    calculate(B);
    calculate(C);
    
    return 0;
}
