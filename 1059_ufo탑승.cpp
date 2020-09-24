//
//  1059_ufo탑승.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>

int name2int(char* word){
    int idx = 0;
    int answer = 1;
    while(word[idx] != '\0'){
        answer *= (word[idx] - 64);
        idx++;
    }
    return answer;
}


int main(){
    
    char name1[7];
    char name2[7];
    
    scanf("%s", name1);
    scanf("%s", name2);
    //printf("%d", 'A');//65
    int num1 = name2int(name1);
    int num2 = name2int(name2);
    
    if(num1 % 47 == num2 % 47){
        printf("GO");
    }
    else{
        printf("STAY");
    }

    return 0;
}
