//
//  1066_숙제를안해온사람은누구.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
int arr[31];
int answer[2];

int main(){
    int input;
    for(int i=0; i<28; i++){
        cin >> input;
        arr[input] = 1;
    }
    
    int idx = 0;
    
    for(int i=1; i<=30; i++){
        if(arr[i] ==0){
            answer[idx] = i;
            idx++;
        }
        if(idx ==2){
            break;
        }
    }
    

    printf("%d\n", answer[0]);
    printf("%d", answer[1]);
    
    
    
    return 0;
}
