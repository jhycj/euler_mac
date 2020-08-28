//
//  1030_graphing.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N;
    vector<int> V;
    cin>>N;
    for (int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        V.push_back(tmp);
        
    }
    
    vector<int> :: iterator it;
    
    for(it= V.begin(); it!= V.end(); it++){
        int n = *it;
        printf("%d ",n);
        for(int i=0; i<n; i++){
            printf("*");
        }
        printf("\n");
    }
    
    
    
    return 0;
}
