//
//  1055_문자찾기2.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void to_lower(char* word){
    int idx= 0;
    while(word[idx] != '\0'){
        if(word[idx] <= 90){ //upper
            word[idx] += 32;
        }
        idx ++;
    }
}


int main(){
    int N=0;
    char alphabet[2];
    char words[12];
    
    cin>> N;
    scanf("%s", alphabet);
    
    
    to_lower(alphabet);
   
    int count = 0;
    for(int i=0; i<N; i++){
        scanf("%s", words);
        to_lower(words);
        
        if(words[0] == alphabet[0]){
            printf("%s\n",words);
            count++;
        }
    }
    
    if(count ==0){
        printf("NOT FOUND");
    }
    
    
    
    return 0;
}
