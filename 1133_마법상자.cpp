//
//  1133_마법상자.cpp
//  euler_mac
//
//  Created by Mac on 9/3/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int A, B, C;
    
    int arr[3]{};
    
    
    cin>> arr[0]>> arr[1]>> arr[2];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3-i-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    A = arr[0];
    B = arr[1];
    C = arr[2];
    
    int answer = 0;
    if(A == B && B== C){
        answer = 10000 + (A*1000);
        
    }
    
    else if(A == B && B != C){
        answer = 1000 + (A*100);
    }
    
    else if(A!= B && B==C){
        answer = 1000 +(B*100);
    }
    else{
        answer = C * 100;
    }
    printf("%d", answer); 
    
    
    return 0;
}
