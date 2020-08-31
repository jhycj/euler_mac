//
//  1056_문자찾기3.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int to_lower(char* word){
    int idx = 0;
    int len = 0;
    while(word[idx] != '\0'){
        if(word[idx] <= 90){
            word[idx] += 32;
        }
        len++;
        idx++;
    }
    return len;
}

int main(){
    
    int N;
    char match_str[11];
    char word[11];
    
    cin>>N;
    scanf("%s", match_str);
    int len_match_str = to_lower(match_str);
    int answer_count = 0;
    for(int i=0; i<N; i++){
        int count = 0;
        scanf("%s", word);
        
        int tmp = to_lower(word);
        for(int i= 0; i<len_match_str; i++){
            if(word[i] == match_str[i]){
                count++;
            }
        }
        if(count == len_match_str){
            printf("%s\n", word);
            answer_count++;
        }
        
    }
    if(answer_count ==0){
        printf("NOT FOUND");
    }

    return 0;
}
