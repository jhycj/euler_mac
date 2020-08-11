//
//  3008_피보나치수열.cpp
//  euler_mac
//
//  Created by Mac on 8/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

//#include "3008_피보나치수열.hpp"
#include<iostream>

using namespace std;
//int arr[51];

void init_Fibo(int* arr){
    arr[0] = 0;
    arr[1] = 1;
    
}

void make_arr(int n, int* arr){
    if(n>=2){
        arr[n] = arr[n-1] + arr[n-2];
    }
}



int main(){
    int N;
    cin>> N;
    int arr[51];
    init_Fibo(arr);

    for(int i=2; i<=N; i++){
        make_arr(i, arr);
    }
    printf("%d", arr[N]);
        
    
    return 0;
}
