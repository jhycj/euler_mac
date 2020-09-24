//
//  1072_speedlimit.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int calculate(vector<pair<int, int>> V){
    int ret = 0;
    
    int before_second = 0;
    
    for(int i=0; i<V.size(); i++){
        ret += V[i].first * (V[i].second - before_second);
        before_second = V[i].second;
    }
    
    return ret;
}
 
int main(){
    int N;
    pair<int, int> P;
    vector<pair<int, int>> v;
    
    scanf("%d", &N);
    
    for(int i= 0; i<N; i++){
        int tmp1, tmp2;
        cin>> tmp1>> tmp2;
        P.first = tmp1;
        P.second = tmp2;
        v.push_back(P);
    }
    int ret = calculate(v);
    printf("%d", ret);
    return 0;
}
