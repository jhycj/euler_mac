//
//  1150_2의거듭제곱계산하기.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int N;
    cin>> N;
    int answer = 1;
    
    for(int i=0; i<N; i++){
        answer *= 2;
    }
    
    printf("%d", answer);
    
    return 0;
}
