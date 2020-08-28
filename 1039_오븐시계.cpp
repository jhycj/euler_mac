//
//  1039_오븐시계.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<utility>
using namespace std;


pair<int, int> min2hour(int minute){
    pair<int, int> P ;
    int ret_h = 0;
    int ret_m = 0;
    
    ret_h = minute /60;
    ret_m = minute % 60;
    
    P.first = ret_h;
    P.second = ret_m;
    
    return P;
}


int main(){
    
    int H; // 0<=H<=23
    int M; // 0<=B<=59
    int C; // 0<= C<=1000
    
    cin>> H>> M>>C;
    
    pair<int, int> P =min2hour(C);
    int C_h = P.first;
    int C_m = P.second;
    
    H += C_h;

    
    M += C_m;
    
    pair<int, int> P1 = min2hour(M);
    
    
    if(P1.first != 0){
        H+= P1.first;
        M = P1.second;
        H %= 24;
        M %= 60;
    }
    else{
        H %= 24;
    }
    
    printf("%d %d", H, M); 
    
    return 0;
}
