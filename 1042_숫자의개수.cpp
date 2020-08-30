//
//  1042_숫자의개수.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

void func(int a, int number, int* arr){
    
    if(a <0){
        return;
    }
    
    else{
        int tmp = pow(10, a);
        arr[a] = number / tmp;
        int next_number = number % tmp;
        func(a-1, next_number, arr);
    }
    
}

int get_len(int* arr){
    int len = 0;
    for(int i=8; i>=0; i--){
        if(arr[i] !=0){
            len = i;
            break;
        }
    }
    return len;
}

int main(){
    int arr[9]{};
    int answer[10]{};
    int A;
    int B;
    int C;
    cin>> A>>B>>C;
    
    int P = A * B * C;
    
    func(8, P, arr);
   
 
    
    int len =get_len(arr);
   
    for(int i=len; i>=0; i--){
        int num = arr[i];
        answer[num] ++;
    }
    
    for(int i=0; i< 10; i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}



