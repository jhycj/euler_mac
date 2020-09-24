//
//  1095_10부제.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int count = 0;
    int N; 
    cin>> N;
    for(int i=0; i<5; i++){
        int tmp;
        cin>>tmp;
        if(tmp ==N){
            count++;
        }
    }
    printf("%d", count); 
    return 0;
}
