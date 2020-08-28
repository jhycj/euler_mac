//
//  1031_최댓값1.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int arr[9];
    
    for(int i=0; i<9; i++){
        cin>> arr[i];
    }
    int max_num = 0;
    int arg_max = 0;
    for(int i=0; i<9; i++){
        if (max_num<arr[i]){
            max_num = arr[i];
            arg_max = i;
        }
    }
    
    printf("%d\n", max_num);
    printf("%d", arg_max+1);
    
    
    return 0;
}
