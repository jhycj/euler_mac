//
//  1049_사칙연산.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int arr[3];
    int sign[2];
    
    for(int i=1; i<= 5; i++){
        if(i%2 ==1){//홀수이면 숫자
            int tmp;
            cin>> tmp;
            arr[(i-1)/2] = tmp;
        }
        else{
            char s;
            cin>>s;
            sign[(i /2)-1] = s;
            
        }
        
    }
    
    int answer = arr[0];
    char s = sign[0];
    switch (s) {
        case '+':
            answer += arr[1];
            break;
        case '-':
            answer -= arr[1];
            break;
        case '*':
            answer *= arr[1];
            break;
        case '/':
            answer /= arr[1];
            break;
            
        default:
            break;
    }
    
    s = sign[1];
    
    switch (s) {
        case '+':
            answer += arr[2];
            break;
        case '-':
            answer -= arr[2];
            break;
        case '*':
            answer *= arr[2];
            break;
        case '/':
            answer /= arr[2];
            break;
            
        default:
            break;
    }
    
    printf("%d", answer);
    
    
    return 0;
}
