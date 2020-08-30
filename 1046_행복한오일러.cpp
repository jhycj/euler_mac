//
//  1046_행복한오일러.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){
    int count_happy = 0;
    int happy_min = 12;
    int answer = 0;
    int ball1, ball2;
    ball1 =1;
    ball2 = 1 ;
    vector<pair<int, int>> V;
    int is_end = 0;
    
    while(is_end ==0){
        cin>> ball1 >> ball2;
        
        if(ball1 ==0 && ball2 ==0){
            is_end = 1;
            break;
        }
        else{
            pair<int, int> P;
            P.first = ball1;
            P.second = ball2;
            V.push_back(P);
        }
        
        
    }
    
    for(int i=0; i<V.size(); i++){
        pair<int, int> P = V[i];
        int ball_num = P.first + P.second;
        if(ball_num > 8){
            count_happy++;
            answer = i+1;
            break;
        }
    }
    
    if(count_happy ==0){
        printf("%d", count_happy);
    }
    else{
        printf("%d", answer);
    }
    return 0;
}


