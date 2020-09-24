//
//  1132_햄버거.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    
    int K, N, M;
    
    cin>> K>> N>> M;
    
    if(K*N >M){
        printf("%d", K*N - M);
    }
    
    else{
        printf("0"); 
    }
    
    
    return 0;
}
