//
//  1015_소수.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<cmath>

using namespace std;

bool is_prime(int N){
    if(N%2 ==0){
        if(N==2){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(N==1){
            return false;
        }
        else{
            for(int i=2; i<= (int)sqrt(N); i++){
                if(N % i == 0){
                    return false;
                }

            }
            return true;
        }
    }
}


int main(){
    int M, N;
    cin>>M>>N;
    
    int sum_p {};
    int min_p = 9999999;
    int count{};
    
    for(int i=M; i<=N; i++){
        if(is_prime(i) == true){
            sum_p += i;
            count++;
            if(min_p > i){
                min_p = i;
            }
        }
    }
    
    if(count==0){
        printf("-1");
        
    }
    else{
        printf("%d\n", sum_p);
        printf("%d", min_p);
    }
    
    
    return 0;
}
