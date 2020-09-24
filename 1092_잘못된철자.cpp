//
//  1092_잘못된철자.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<list>

using namespace std;
int N;
char words[82];

int main(){
    
    cin>> N;
    scanf("%s", words);
    //printf("%c", words[N-1]);
    int len = 0;
    
    char ch = 'a';
    while(words[len] != '\0'){
        ch = words[len];
        len++;
    }
    
    for(int i=0; i<N-1; i++){
        printf("%c", words[i]);
    }
    for(int i=N; i<len; i++){
        printf("%c", words[i]);
    }
    
    if(len ==1 && N==1){
        printf("-1");
    }

    
    return 0;
}
