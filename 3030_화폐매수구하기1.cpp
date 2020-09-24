//
//  3030_화폐매수구하기1.cpp
//  euler_mac
//
//  Created by Mac on 9/16/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int money[8] = {5000, 1000, 500, 100, 50, 10, 5, 1};
int main(){
    
    int M;
    cin>> M;
    int answer = 0;
    for(int i=0; i<8; i++){
        
        int block = money[i];
        int tmp = M / block;
        answer += tmp;
        M = M % block;
        
    }

    printf("%d", answer); 

    
    return 0;
}
