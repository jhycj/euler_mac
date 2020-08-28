//
//  1027_우박수.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int max_n = N;
    
    while(N!= 1){
        if(N%2 ==0){
            N /= 2;
        }
        else{
            N = 3*N + 1;
        }
        
        if(max_n <N){
            max_n = N;
        }
    }
    
    printf("%d", max_n);
    
    
    return 0;
}
