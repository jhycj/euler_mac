//
//  3011_숫자고르기.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[8];
int N, M;
int count = 0;

void process(int level, int* count_p){
    
    if(level> M){
        for(int i=1; i<= M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        (*count_p) ++;
        return;
        
    }
    else{
        for(int i=arr[level-1]; i<= N; i++){
            arr[level] = i;
            process(level+1, count_p);
            
        }
    }
    
    
}
int main(){
    int count =0;
    arr[0] = 1 ;
    cin>> N>>M;
    process(1, &count);
    printf("%d", count);
    return 0;
}
