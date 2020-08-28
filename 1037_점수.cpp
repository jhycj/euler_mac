//
//  1037_점수.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int main(){
    
    int euler[4];
    int euclid[4];
    int euler_sum =0;
    int euclid_sum = 0;
    
    for(int i=0; i<4; i++){
        cin>> euler[i];
        euler_sum+= euler[i];
    }
    
    for(int i=0; i<4; i++){
        cin>>euclid[i];
        euclid_sum += euclid[i];
    }
    
    if(euler_sum < euclid_sum){
        printf("%d", euclid_sum);
    }
    else{
        printf("%d", euler_sum);
    }
    
    
    return 0;
}
