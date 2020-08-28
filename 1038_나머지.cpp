//
//  1038_나머지.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int mod[42]{};
    int answer = 0;
    for(int i=0; i<10; i++){
        cin>> arr[i];
    }
    for(int i=0; i<10; i++){
        int mod_42 = arr[i] % 42;
        mod[mod_42] ++;
    }
    
    for(int i=0; i<42; i++){
        if(mod[i] > 0){
            answer++;
        }
    }
    printf("%d", answer);
    
    
    return 0;
}
