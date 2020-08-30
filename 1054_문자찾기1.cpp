//
//  1054_문자찾기1.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

void make_to_lower(char *word, char* alphabet){
    int idx =0 ;
    while(word[idx] != '\0'){
        if(word[idx] <91){ //대문자이면
            word[idx] += 32;
        }
        idx++;
    }
    if(alphabet[0] <91){
        alphabet[0] += 32;
    }
}


int find_index(char *word, char *alphabet){

    int idx = 0;
    int ret = 0;
    while(word[idx] != '\0'){
        if(word[idx] == alphabet[0] ){
            ret = idx+1;
            break;
        }
        idx++;
    }


    return ret;
}

int main(){
    
    
    for(int i=0; i<5; i++){
        char word[21];
        char alphabet[2];
        scanf("%s %s", word, alphabet);
        make_to_lower(word, alphabet);
        printf("%d\n", find_index(word, alphabet));
    }
    
    /*
    printf("%d\n", 'a'); //97
    printf("%d\n", 'z'); //122
    printf("%d\n", 'A'); //65
    printf("%d", 'Z'); // 90
    */
    return 0;
}
