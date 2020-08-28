//
//  1034_대푯값2.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include<iostream>
#include "stdio.h"
using namespace std;

int main(){
    
    int arr[10];
    int sum = 0;
    int avg = 0;
    int count[10]{};
    
    for(int i=0; i<10; i++){
        count[i] = 0;
    }
    for(int i=0; i<10; i++){
        
        cin>> arr[i];
        sum+= arr[i];
    }
    
    avg = sum/ 10;
    
    for(int i=0; i<9; i++){
        for(int j=0; j<10-i-1; j++){
            if(arr[j]< arr[j+1]){
                int tmp = arr[j] ;
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    /*sorted*/
    int k = 0;
    for(int i= 0; i<10; i+=k){
        int chk_num = arr[i];
        int count_num = 0;
        for(int j=i; j<10; j++ ){
            if(chk_num == arr[j]){
                count_num ++;
            }
        }
        for(int j = 0; j<count_num; j++){
            count[i+j] = count_num;
        }
        
        k = count_num;

    }
    
    int max = count[0];
    int arg_max = 0 ;
    
    for(int i=0; i<10; i++){
        if(max <= count[i]){
            max = count[i];
            arg_max = i;
        }
    }
    
    
   
    
    printf("%d\n", avg);
    printf("%d\n", arr[arg_max]);
    return 0;
}


