//
//  1032_최댓값2.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int arr[9][9];
    int max_num = -1;
    int arg_min_row = 0;
    int arg_min_col = 0;
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++){
            cin>> arr[i][j];
        }
    }
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(max_num < arr[i][j]){
                max_num = arr[i][j];
                arg_min_row = i+1;
                arg_min_col = j+1;
            }
        }
    }
    
    printf("%d\n", max_num);
    printf("%d %d", arg_min_row, arg_min_col);
    
    
    
    return 0;
}
