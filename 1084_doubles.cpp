//
//  1084_doubles.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>


using namespace std;

int main(){
    
    vector<int> V;
    int answer = 0;
    int input;
    int is_end = 0;
    
    while(is_end ==0){
        cin>> input;
        if(input == 0){
            is_end = 1;
            break;
        }
        else{
            V.push_back(input);
        }
    }
    
    int len = V.size();
    
    for(int i=0; i<len; i++){
        int num = V[i];
        for(int j = 0; j<len; j++ ){
            if( num *2 == V[j]){
                answer++;
                break;
            }
        }
    }
    printf("%d", answer);
    
    
    return 0;
}
