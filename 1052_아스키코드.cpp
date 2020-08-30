//
//  1052_아스키코드.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
    cin>> input;
    
    for(int i=0; i<input.size(); i++){
        int ascii = input[i];
        printf("%c", input[i]);
        printf("->%d\n", ascii );
    }
    
    
    return 0;
}
