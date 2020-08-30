//
//  1044_꽃축제.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int S, N; //슬롯 수, 꽃 종류
    int flower_info[100][2];
    int map[10001]{};
    
    cin>> S>> N;
    for(int i=0; i<N; i++){
        cin>> flower_info[i][0]>> flower_info[i][1] ;
    }
    
    for(int i=0; i<N; i++){
        int start = flower_info[i][0];
        int tab = flower_info[i][1];
    
        int tmp = start;
        
        while(tmp <=S){
            map[tmp] = 1;
            tmp  += tab;
        }
    }
    int answer = 0 ;
    for(int i=1; i<=S; i++){
        if(map[i] ==0){
            answer++;
        }
    }
    
    printf("%d", answer);

    
    return 0;
}
