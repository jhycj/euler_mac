//
//  1057_문자열소트.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int N;
int word_int[100][11]{};

int idx_until_not_same(int* arr1, int* arr2){
    int idx = 0;
    while(arr1[idx] == arr2[idx]){
        idx++;
    }
    return idx;
}


void sort_int_arr(){
    for(int i=0; i<N; i++){
        for(int j=0; j< N-i-1; j++){
            if(word_int[j][0] > word_int[j+1][0]){
                
                swap(word_int[j], word_int[j+1]);
                /*
                int tmp[11]  = word_int[j];
                word_int[j][0] = word_int[j+1][0];
                word_int[j+1][0] = tmp;
                 */
            }
            else if(word_int[j][0] == word_int[j+1][0]){
                int tmp_idx = idx_until_not_same(word_int[j], word_int[j+1]);
                if(word_int[j][tmp_idx] > word_int[j+1][tmp_idx]){
                    swap(word_int[j], word_int[j+1]);
                }
            }
        }
    }
}


int make_to_lower(char* word){
    int idx = 0;
    
    while(word[idx] != '\0'){
        if(word[idx] <=90){
            word[idx] += 32;
        }
        idx++;
    }
    return idx;
}


int main(){
    char word[100][11]{};
    
    cin>> N;
    for(int i=0 ; i<N; i++){
        scanf("%s", word[i]);
        int len_word = make_to_lower(word[i]);
        for (int j=0; j<len_word; j++){
            word_int[i][j] = int(word[i][j]);
        }
        
    }    
    sort_int_arr();

    
    for(int i=0; i<N; i++){
        int j =0;
        while(word_int[i][j] != 0){
            char output_ch = word_int[i][j];
            cout<<output_ch;
            j++;
        }
        printf("\n");
    }
    
    
    return 0;
}
