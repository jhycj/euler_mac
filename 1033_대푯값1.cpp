//
//  1033_대푯값1.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
#define N 5
int main(){
    int arr[N];
    int sum{};
    int avg{};
    int median{};
    
    for(int i=0; i<5; i++){
        cin>> arr[i];
        sum += arr[i];
    }
    avg = (int)(sum / 5);
    
    for(int i=0; i<N; i++){
        for(int j=0; j< N-i-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    median = arr[2];
    printf("%d\n", avg);
    printf("%d", median);
    
    
    return 0;
}
