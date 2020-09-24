//
//  1059_콤마를삽입하라.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
#include<list>

using namespace std;

int get_len_N(char* digit){
    int idx = 0;

    while(digit[idx] != '\0'){
        idx ++;
    }
    return idx;
}

list<int> arr2list(int len, char* arr){
    list<int> ret;
    for(int i=0 ; i<len ; i++){
        int tmp = arr[i] - 48;
        ret.push_back(tmp);
        
    }
    return ret;
}
/*
void insert_comma(list<int> L){
    list<int> :: iterator it;
    
    if(L.size() <= 3){
        for(it = L.begin(); it!= L.end(); it++){
            printf("%d", *it);
        }
    }
    else{
        int q = L.size() / 3;
        int r = L.size() % 3;
        it = L.begin();
        
        for(int i=0; i<r; i++){
            printf("%d", *it);
            it++;
        }
        if(r!= 0){printf(",");}
        for(int i=0; i<q; i++){
            for(int j=0; j<3;j++){
                printf("%d", *it);
                it++;
            }
            if(i != q-1){
                printf(",");            }
            
        }
    }

}
*/
list<int>  insert_comma(list<int> L){
    list<int> :: iterator it;
    
    for(it = L.end(); it!= L.begin(); it--){
        if(it == L.begin()){
            break;
        }
        
        it--;
        if(it==L.begin()){
            break;
        }
        it--;
        if(it== L.begin()){
            break;
        }
        it--;
        if(it ==L.begin()){
            break;
        }
        L.insert(it, -1);
    }
    return L;
}

int main(){
    char digit[101]{};
    
    scanf("%s", digit);
    int len = get_len_N(digit);
    list<int> L = arr2list(len, digit);
    
    
    L = insert_comma(L);
    list<int> :: iterator it;
    for(it = L.begin(); it!= L.end(); it++){
        
        if(*it ==-1){
            printf(",");
        }
        else{
            printf("%d", *it);
        }
    }
    
    return 0;
}
