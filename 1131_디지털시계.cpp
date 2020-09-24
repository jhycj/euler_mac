//
//  1131_디지털시계.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>

int main(){
    
    int A, B, C;
    
    scanf("%d %d\n %d", &A, &B, &C);
    
    int tmp_m = B + C;
    
    int tmp_h = tmp_m / 60;
    tmp_m = tmp_m % 60;
    
    int H = (A + tmp_h) % 24;
    int M = tmp_m;
    
    printf("%d %d", H, M); 
    
    return 0;
}
