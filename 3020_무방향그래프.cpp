//
//  3020_무방향그래프.cpp
//  euler_mac
//
//  Created by Mac on 9/16/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#include<iostream>
#include <stdio.h>
int V;
int E;
int adjoint[101][101]{};

using namespace std;

int main(){
    
    cin >>V>>E;
    
    for(int i=0; i<E; i++){
        
        int v1, v2;
        
        cin>> v1>>v2;
        adjoint[v1][v2] = adjoint[v2][v1] = 1;
        
    }
    
    for(int i=1; i<= V; i++){
        for(int j=1; j<= V; j++){
            printf("%d ", adjoint[i][j]);
        }
        printf("\n"); 
    }
    
    
    
    return 0;
}

