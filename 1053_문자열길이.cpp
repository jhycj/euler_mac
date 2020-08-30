//
//  1053_문자열길이.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main(){
    
    int N;
    cin>>N;
    int even = 0;
    for(int i=0; i<N; i++){
        string word;
        cin>> word;
        if(word.size() %2 ==0){
            even++;
        }
    }
    printf("%d\n", even);
    printf("%d", N -even);
    return 0;
}
