//
//  1098_약수.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<limits>

using namespace std;

int func(int N){
    
    int ret =0;
    if(N == 1){
        return ret;
    }
    else{
        
        for(int i=1; i<N; i++){
            if(N% i ==0){
                ret+= i;
            }
        }
        return ret;
    }
    
}


int main(){
    int N;
    cin>>N;
    
    //cout<< numeric_limits<int> :: max();
    cout<< func(N);
    
    
    
    
    
    return 0;
}
