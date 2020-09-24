//
//  1112_수박.cpp
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
    cin>> N;

    if(N%2 ==0 && N>2){
        printf("YES");
    }
    else{
        printf("NO");
    }


    return 0;
}
