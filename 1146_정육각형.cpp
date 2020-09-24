//
//  1146_정육각형.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;


int main(){
    int N;
    int answer = 0;
    cin>> N;

    for(int i=1; i<=N; i++){
        answer += (i-1) * 6;
    }

    printf("%d", answer+1);
    return 0;
}
