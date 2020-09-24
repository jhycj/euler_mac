//
//  1107_성냥.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

void print_answer(int n, int max_len){
    if(n> max_len){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}





int main(){
    int N, W, H;
    vector<int> V;
    
    scanf("%d %d %d\n", &N, &W, &H);
    int max_len = (int) sqrt(pow(W,2) + pow(H,2));
    //printf("%d", max_len);
    
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        V.push_back(tmp);
    }
    for(int i=0; i<V.size(); i++){
        print_answer(V[i], max_len);
    }
    
    
    return 0;
}
