//
//  3013_대회결과예상하기1.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[8];
int visit[8]{};

int N, M;

void process(int level, int* count_ptr){
    if(level>M){
        (*count_ptr)++;
        return;
    }
    
    else{
        for(int i=1; i<= N; i++){
            if(visit[i] != 1){
                arr[level] = i;
                visit[i] = 1;
                process(level+1, count_ptr);
                visit[i] = 0;
            }
        }
    }
}


int main(){
    cin>> N>> M;
    int answer= 0;
    
    process(1, &answer);
    
    printf("%d", answer);
    
    return 0;
}
