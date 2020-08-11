//
//  4076_좋은수열.cpp
//  euler_mac
//
//  Created by Mac on 8/6/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include<iostream>

using namespace std;
int N;
int arr[81];
bool is_end = false;

bool is_good(int level){
    
    int count = 0;
    for(int i=1; i<= N/2; i++){
        count = 0;
        for(int j=0; j<i; j++){
            
            if(level-j-i<1){
                break;
            }
        
            if(arr[level-j] == arr[level-j-i]){
                count++;
            }
        }
        if(count == i){
            return false;
        }
    }
    return true;
}


void process(int level){
    if(level> N){
        for(int i=1; i<=N; i++){
            cout<<arr[i];
        }
        
        is_end = true;
    }
    else{
        for(int i= 1; i<= 3 && is_end == false; i++){
            arr[level] = i;
            if(is_good(level) == true){
                process(level+1);
                
            }
        }
    }
}


int main(){
    cin>> N ; // 1<= N <= 80
    process(1);
    
    return 0;
}
