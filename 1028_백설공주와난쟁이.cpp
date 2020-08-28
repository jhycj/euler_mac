//
//  1028_백설공주와난쟁이.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int arr[7];
    
    for(int i=0; i<7; i++){
        int tmp;
        cin>> tmp;
        arr[i] = tmp;
    }
    
    for(int i = 0; i< 6; i++){
        for(int j=0; j<7-i-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    printf("%d\n", arr[6]);
    printf("%d", arr[5]);
    
    
    
    return 0;
}
