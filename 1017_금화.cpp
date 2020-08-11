//
//  1017_금화.cpp
//  euler_mac
//
//  Created by Mac on 8/12/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int N;
    std::vector<int> V;
    V.push_back(0);
    
    V.push_back(1);
    V.push_back(1);
    
    std:: cin>>N;
    int tmp;
    for(int i=3; i<=N; i++){
        if(i%2 ==0){
            tmp = V.at(i/2);
        }
        else{
            tmp = V.at((i-1) /2) + V.at(((i-1)/2) +1);
        }
        V.push_back(tmp);
    }
    
    int answer = 0;
    for(int v : V){
        if(answer < v){
            answer = v;
        }
        //printf("%d", v);
    }
    printf("%d", answer);
    
    return 0;
}
