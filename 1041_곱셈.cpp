//
//  1041_곱셈.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int input1;
    int input2;
    
    cin>>input1>> input2;
    
    int input2_0, input2_1, input2_2;
    //input2 = 365;
    input2_2 = input2 / 100 ;   //3
    input2_1 = (input2 % 100) / 10; // 65 /10 == 6
    input2_0 = (input2 % 100) % 10 ;
    
    int answer1 = input1 * input2_0;
    int answer2 = input1 * input2_1;
    int answer3 = input1 * input2_2;
    int answer4 = input1 * input2;
    
    printf("%d\n%d\n%d\n%d", answer1, answer2, answer3, answer4);
    
    return 0;
}
