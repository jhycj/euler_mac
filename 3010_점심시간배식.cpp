//
//  3010_점심시간배식.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[8];
int visit[8]{};
int N, M;

void process(int level, int* count){
    
    if(level > M){
        for(int i=1; i<=M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        (*count)++;
    }
    else{
        for(int i=1; i<= N; i++){
            if(visit[i] != 1){
                visit[i] = 1; 
                arr[level] = i;
                process(level+1, count);
                visit[i] = 0 ;
                
            }
        }
        
    }

}


int main(){
    cin>> N>> M;  // 1<= N<= 7
    int count_ = 0;
    process(1, &count_);
    
    printf("%d", count_);
  
    return 0;
}
