//
//  1050_윷놀이.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    for(int i=0; i<3; i++){
        int count = 0;
        for(int j=0; j<4; j++){
            int input;
            cin>>input;
            if(input == 1){
                count++;
            }
        }
        char answer = ' ';
        switch(count){
            case 1:
                answer = 'C';
                break;
            case 2:
                answer = 'B';
                break;
            case 3:
                answer = 'A';
                break;
            case 4:
                answer = 'E';
                break;
            case 0:
                answer = 'D';
                break;
            default:
                break;
        }
        printf("%c\n", answer);
    }
    
    return 0;
}
