//
//  1071_용감한전사.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<limits>
#include<iostream>
using namespace std;

int main(){
    
    unsigned long long A, B;
    
    //cout<< numeric_limits<unsigned long long>:: max();
    
    cin>> A>>B;
    
    if(A>B){
        unsigned long long tmp;
        tmp = A;
        A = B;
        B = tmp;
    }
    printf("%llu", B-A);
    
    return 0;
}
