//
//  1062_삼각형출력하기.cpp
//  euler_mac
//
//  Created by Mac on 9/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

char alphabet[3] ;

void print_tri(int N, char* alphabet){
    
    char ch1 = alphabet[0];
    char ch2 = alphabet[1];
    char ch3 = alphabet[2];
    
    printf("%c\n", ch3);
    
    for(int i=0; i<N-2; i++){
        printf("%c", ch1);
        for(int j=0; j<i; j++){
            printf(" ");
        }
        printf("%c\n", ch3);
    }
    printf("%c", ch1);
    for(int i=0; i<N-1; i++){
        printf("%c", ch2);
    }
    
}



int main(){
    
    int N ;
    cin>>N;
    scanf("%s", alphabet);
    print_tri(N, alphabet);
    return 0;
}
