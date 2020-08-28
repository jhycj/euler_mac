//
//  1029_반올림과버림.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include <vector>

using namespace std;


void compute(int N){
    
    int answer_1;
    int answer_2;
    
    int q = N/100;//몫
    int r = N %100; //두자리 나머지
    
    int num = r/10 ; //십의 자리
    
    answer_1 = q *100;
    if(num >= 5){
        answer_2 = answer_1 + 100;
    }
    else{
        answer_2 = answer_1;
    }
    printf("%d %d\n", answer_2, answer_1);
    
}

int main(){
    
    vector<int>V;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int tmp;
        cin>> tmp;
        V.push_back(tmp);
    }
    
    vector<int>::iterator it;
    
    for(it= V.begin(); it!= V.end(); it++){
        int n = * (it);
        
        compute(n);
    }
    
    
    
    return 0;
}

