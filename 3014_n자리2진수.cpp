//
//  3014_n자리2진수.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int arr[16];
int N;

void process(int level, int* count_ptr){
    
    if(level== N){
        for(int i= 0; i <N; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        (*count_ptr) ++;
        return;
    }
    else{
        
        for(int i=0; i<2; i++){
            arr[level] = i;
            process(level+1, count_ptr);
            
        }
    }
}





int main(){
    
    int count = 0;
    cin>>N;
    process(0, &count);
    printf("%d", count);
    return 0;
}
