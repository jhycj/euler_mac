//
//  3007_진법변환.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#include<iostream>
#include <stdio.h>
#include <stack>

using namespace std;
stack<int> S;

char int2char(int n){
    char ret = ' ';
    
    switch (n) {
        case 10:
            ret = 'A';
            break;
        case 11:
            ret = 'B';
            break;
        case 12:
            ret = 'C';
            break;
        case 13:
            ret = 'D';
            break;
        case 14:
            ret = 'E';
            break;
        case 15:
            ret = 'F';
            break; 
        default:
            break;
    }
    return ret;
}

void process(int N, int T){
    
    if(N < T){
        S.push(N);
        
        while(!S.empty()){
            int tmp = S.top();
            if(tmp>=10){
                char c = int2char(tmp);
                printf("%c", c);
            }
            else{
                printf("%d", tmp);
            }
            S.pop();
        }
        
    }
    else{
        int q = N / T;
        int r = N % T;
        
        S.push(r);
        process(q, T);
    }
    
    
}



int main(){
    int N, T;
    
    cin >> N>> T;
    
    process(N, T);
    
    
    return 0;
}
