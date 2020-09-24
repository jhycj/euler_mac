//
//  1078_서로다른구슬.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int input;
    int N;
    int before = 0;
    int answer = 0;
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>> input;
        
        if(i ==0){
            before = input ;
        }
        
        if(before != input){
            answer++;
        }
        before = input;
    
    }
    printf("%d", answer); 
    return 0;
}
