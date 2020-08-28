//
//  1035_등수구하기.cpp
//  euler_mac
//
//  Created by Mac on 8/26/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> Grade;
    vector<int> A;
    vector<int> A_count;
    int N;
    cin>> N;
    for(int i=0; i<N; i++){
        int tmp ;
        cin>> tmp;
        Grade.push_back(tmp);
    }
    A = Grade;
    for(int i=0; i<N-1; i++){
        for(int j=0; j< N-i-1; j++){
            if(A.at(j) < A.at(j+1)){
                int tmp = A.at(j);
                A.at(j) = A.at(j+1);
                A.at(j+1) = tmp;
            }
        }
    }
    

    
    vector<int> :: iterator it;
    
    for(int i=0; i<A.size(); i++){
        A_count.push_back(i+1);
    }
    
    
    int k = 0;
    for(int i=0; i<A.size(); i+= k ){
        int count = 1;
        int chk_num = A[i];
        for(int j=i+1; j< A.size(); j++){
            if(A[j] == chk_num ){
                count++;
            }
        }
        k = count;
        
        if(count>1){
            for(int j=0; j<count; j++ ){
                A_count[i+j] = A_count[i];
            }
        }
    }
    
    

    
    for(int i=0; i<Grade.size(); i++){
        int grade = Grade[i];
        
        for(int j=0; j< A.size(); j++){
            if(grade == A[j]){
                printf("%d ", A_count[j]);
                break;
            }
        }
        
    }
    
    return 0;
}
