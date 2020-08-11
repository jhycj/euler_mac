//
//  4049_N-Queens.cpp
//  euler_mac
//
//  Created by Mac on 8/6/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include "4049_N-Queens.hpp"
#include<iostream>
using namespace std;
int N;
int arr[17];
bool is_end = false;


bool is_okay(int row_num){
    int col_num = arr[row_num];
    
    for(int i=1; i< row_num; i++){
        if(arr[i] == col_num || i+arr[i] == row_num + col_num|| i-arr[i] == row_num - col_num){
            return false;
        }
    }
    return true;
}




void process(int row_num){
    if(row_num > N){
        is_end = true;
        for(int i=1; i<=N; i++){
            cout<< arr[i] <<' ';
        }
        return;
    }
    else{ //row_num<=N
        for(int i=N; i>=1; i--){
            if(is_end == true){
                break;
            }
            else{ //is_end == false
                arr[row_num] = i;
                if(is_okay(row_num)){ // arr[row_num] = i 넣어도 괜찮을 때만
                    process(row_num+1);
                }
            }
        }
    }
}



int main(){
    
    cin>> N;
    process(1);
    /*
    make_visit(3, 2);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    recover_visit(3, 2);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //process(1);
    */
    return 0;
}
