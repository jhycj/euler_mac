//
//  1060_koiioi.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

int main(){
        
    char word[10001]{};
    
    scanf("%s", word);

    int len = 0;
    while(word[len] != '\0'){
        len++;
    }
    
    int answer_koi=0;
    int answer_ioi=0;
    
    char word_koi[4] = {'K', 'O', 'I'};
    char word_ioi[4] = {'I', 'O', 'I'};
    

        
    for(int i=0; i<len-2; i++){
        if(word_koi[0] == word[i] && word_koi[1] == word[i+1] && word_koi[2] == word[i+2]){
            answer_koi ++;
        }
        if(word_ioi[0] == word[i] && word_ioi[1] == word[i+1] && word_ioi[2] == word[i+2]){
            answer_ioi ++;
        }
    }
        
    printf("%d\n", answer_koi);
    printf("%d", answer_ioi);
    
    
    return 0;
}
