//
//  1048_수의덧셈.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int reversed_N(int N){
    int ret = 0;
    int digit[6] ;
    int r = N;
    int digit_N = -1; //N의 숫자 자리 수
    int digit_rev_N = -1;
    for(int i=5; i>=0; i--){
        int _10_n = pow(10,i);
        int q = r / _10_n;
        digit[i] = q;
        r = r % _10_n;
    }
    
   
    
    
    for(int i=5; i>=0; i--){
        if(digit[i] != 0 ){
            digit_N = i;
            break;
        }
    }
    
    for(int i=0; i<= digit_N; i++){
        if(digit[i] != 0){
            digit_rev_N = i;
            break;
        }
    }
    int tmp_n = 1;
    int tmp_digit = digit_N - digit_rev_N;
    
    for(int i= tmp_digit ; i>=0 ; i--){
        tmp_n = pow(10, i);
        ret += tmp_n * digit[digit_rev_N];
        digit_rev_N ++;
    }
    
    return ret;
}


int main(){
    
    int N;
    cin>>N;
    int ret = reversed_N(N);
    printf("%d", ret + N);
    return 0;
}
