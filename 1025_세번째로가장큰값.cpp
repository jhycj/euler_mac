//
//  1025_세번째로가장큰값.cpp
//  euler_mac
//
//  Created by Mac on 8/12/20.
//  Copyright © 2020 Mac. All rights reserved.
//


#include<array>
#include<iostream>
using namespace std;

int main(){

    array<int, 10> arr;

    for(int i=0; i<10; i++){
        cin>> arr[i];
    }

    for(int i=1; i<10; i++){
        for(int j=0; j<10-i ; j++){
           
            if(arr[j] < arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    printf("%d", arr[2]);



    return 0;
}

