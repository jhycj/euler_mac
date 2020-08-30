//
//  1045_유행.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    vector<int> V;
    int max_count = 0;
    int max = 0;
    
    cin>> N;
    for(int i=0; i<N; i++){
        int tmp ;
        cin>>tmp;
        V.push_back(tmp);
    }
    
    int chk_count = 0;
    for(int i=0; i<V.size(); i+= chk_count){
        int chk_num = V[i];
        chk_count = 0;
        for(int j=i; j<V.size(); j++){
            if(V[j] == chk_num){
                chk_count++;
            }
            else{
                break;
            }
        }
        if(chk_count>max_count){
            max_count = chk_count;
            max = chk_num;
        }
    }
    printf("%d", max);
    return 0;
}
