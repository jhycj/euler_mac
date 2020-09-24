//
//  1081_동전교환.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

#include<iostream>
using namespace std;

int arr[6] = {500, 100, 50, 10, 5, 1};



int main(){
    
    int money ;
    cin>> money;
    
    int count = 0;
    
    money = 1000 - money;
    
    for(int i=0; i<6; i++){
        count += money / arr[i] ;
        money = money % arr[i];
    }
    printf("%d", count); 
    
    
    return 0;
}
