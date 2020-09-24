//
//  1089_컨테스트시간.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int main(){
    
    int D, H, M = 0;
    cin>> D>> H>>M;
    
    if( (D == 11 && H<11 )|| (D ==11 && H == 11 && M <11)){
        printf("-1");
    }
    else{
        int tmp = 60*11  +11;
        D = (D -11) * 24 *60;
        M = 60 * H + M + D;
        
        M -= tmp;
        printf("%d", M); 
    }
    
}
