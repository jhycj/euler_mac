//
//  1069_ABC.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    char alphabet[3];
    int abc[3];
    cin>> abc[0] >> abc[1]>>abc[2];
    scanf("%s", alphabet);
    
    /*sort*/
    
    for(int i=0; i<2; i++){
        for(int j = 0; j< 3-i-1; j++){
            if(abc[j] > abc[j+1]){
                int tmp = abc[j];
                abc[j] = abc[j+1];
                abc[j+1] = tmp;
            }
        }
        
    }
    
    for(int i=0; i<3; i++){
        char alpha = alphabet[i];
        
        switch (alpha) {
            case 'A':
                printf("%d ", abc[0]);
                break;
            case 'B':
                printf("%d ", abc[1]);
                break;
            case 'C':
                printf("%d ", abc[2]);
                break;
            default:
                break;
        }
        
        
    }
    
    return 0;
}
