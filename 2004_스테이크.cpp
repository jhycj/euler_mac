//
//  2004_스테이크.cpp
//  euler_mac
//
//  Created by Mac on 9/4/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int N, K;
    
    scanf("%d %d", &N, &K);
    
    
    if(N < K){
        printf("2");
    }
    else if(2*N % K ==0){
        printf("%d", 2*N / K);
    }
    else{
        printf("%d", (2*N / K)+1);
    }
    
    
    return 0;
}
