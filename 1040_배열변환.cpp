//
//  1040_배열변환.cpp
//  euler_mac
//
//  Created by Mac on 8/28/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[100][100];
int answer[100][100];




int main(){
    int N, M;
    cin>> N>> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            
            answer[j][i] = arr[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
