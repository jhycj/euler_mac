//
//  3068_지그재그숫자.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[11]; // 1<=N<=10
int visit[11];
int N;

void process(int level, int* count_ptr){
    
    if(level > N){
        for(int i=1; i<=N; i++){
            if(arr[i] == 10){
                printf("A");
            }
            else{
                printf("%d", arr[i]);
                
            }
            
        }
        printf("\n");
        (*count_ptr)++;
        return;
    }
    else{
        int before_num = arr[level-1];
        
        if(level%2 ==0){ //앞보다 큰 거
            for(int i=before_num + 1; i<= N; i++){
                
                if(visit[i] != 1){
                    arr[level] = i;
                    visit[i] = 1;
                    process(level+1, count_ptr);
                    visit[i] = 0;
                }
                
            }
        }
        else{ // 앞보다 작은 거
            for(int i=1; i<before_num; i++){
                if(visit[i] != 1){
                    arr[level] = i;
                    visit[i] = 1;
                    process(level+1, count_ptr);
                    visit[i] = 0;
                }
            }
        }
        
    }
}



int main(){
    int count = 0;
    cin>> N;
    arr[0] = N+1;
    process(1, &count);
    printf("%d", count);
    return 0;
}
