//
//  1110_체스판자르기.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

int process(int n){
    
    if(n==1){
        return 2;
    }
    
    else{
        
        if( n %2 ==0 ){
            return process(n-1) + ((n+1)/2) + 1;
        }
        else{
            return process(n-1) + ((n+1)/2) ;
        }
        
        
    }
    
}

int main(){
    
    int N;
    scanf("%d", &N);
    
    int ret = process(N);
    printf("%d", ret);
    return 0;
}
