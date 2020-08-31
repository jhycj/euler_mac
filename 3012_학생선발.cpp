//
//  3012_학생선발.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[8];
int visit[8];
int N, M;

void process(int level, int* count_ptr){
    if(level>M){
        for(int i=1; i<= M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        (* count_ptr) ++;
        return;
    }
    else{
        int before_num = arr[level-1];
        
        for(int i=before_num+1; i<= N; i++){
            if(visit[i] != 1){
                arr[level] = i;
                visit[level] =1;
                process(level+1, count_ptr) ;
                visit[level] = 0;
            }
            
        }
    }
}


int main(){

    int count = 0;
    cin>> N >> M;
    arr[0] = 0;
    process(1, &count);
    printf("%d", count);
    return 0;
}
