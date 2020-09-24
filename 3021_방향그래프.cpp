//
//  3021_방향그래프.cpp
//  euler_mac
//
//  Created by Mac on 9/16/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>

using namespace std;

int adjoint[101][101]{};
int V;
int E;
int main(){
    
    cin>> V>>E;
    
    for(int i=0; i<E; i++){
        int v1, v2;
        int w ;
        cin>>v1>>v2>> w;
        adjoint[v1][v2] = w;
    }
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            printf("%d ", adjoint[i][j]);
        }
        printf("\n"); 
    }
    
    return 0;
}
