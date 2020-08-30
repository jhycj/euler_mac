//
//  1043_숫자뒤집기.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int ret_reversed(int N){
    int ret ;
    int a_0 = (N%100) %10 ;// 첫번째 자리 수
    int a_1 = (N%100) / 10; // 두번째 자리 수
    int a_2 = N /100 ;  //세번쨰 자리수
    
    ret = 100 * a_0 + 10 * a_1 + a_2;
    return ret;
    
}


int main(){
    int A;
    int B;
    cin >> A>> B;
    
    int rev_A = ret_reversed(A);
    int rev_B = ret_reversed(B);
    
    if(rev_A > rev_B){
        printf("%d", rev_A);
    }
    else{
        printf("%d", rev_B);
    }
    
    
    return 0;
}
