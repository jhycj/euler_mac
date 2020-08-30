//
//  4146_zerosum.cpp
//  euler_mac
//
//  Created by Mac on 8/29/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include <list>

using namespace std;
int number[10]{};
int sign[9];
int N;


list<int> formula2list(){
    
    list<int> L;
    list<int>:: iterator it;
    
    L.push_back(1);
    for(int i=1; i<= N-1; i++){
        L.push_back(sign[i]) ;
        L.push_back(number[i+1]);
    }
    
    return L;
}


int list2int(list<int> L){
    list<int> :: iterator it;
    for( it = L.begin(); it!= L.end(); it++){
        if(*it == -100){
            
            list<int> ::iterator i_front, i_back;
            it--;
            int left_int = *(it);
            i_front = it;
            
            it++;
            it++;
            int right_int = *(it);
            it++;
            //printf("%d ", *it);
            i_back = it;
            int new_num = 10 * left_int + right_int;
            L.insert(i_back, new_num);
            i_back --;
            L.erase(i_front, i_back);
            //printf("%d ", *it);
            it = i_back;
            //printf("%d ", *it);
 
        }
    }
    

    
    int left = *L.begin();
    
    for(it = L.begin(); it!= L.end(); it++){
        if(*it == -101 || *it == -102){
            if(*it == -101){//plus
                it++;
                int right = (*it);
                left += right;
            }
           
            else{//minus
                it++;
                int right = (*it);
                left -= right;
            }
        
        }
    }
    return left;
}

void print_list(list<int> L){
    list<int> :: iterator it;
    for(it = L.begin(); it!= L.end(); it++){
        if(*it == -100){
            printf(" ");
        }
        else if(*it == -101){
            printf("+");
        }
        
        else if(*it == -102){
            printf("-");
        }
        else{
            printf("%d", *it);
        }
    }
    printf("\n");
}

void process(int level){
    
    
    if(level>= N){
        list<int> L = formula2list();
        int ret = list2int(L);
        if(ret ==0){
            print_list(L);
            return;
        }
    }
    else{
        for(int i= -100; i> -103; i--){
            sign[level] = i;
            process(level+1);
            
        }
    }
}

int main(){

    
    for(int i=1; i<=9; i++){
        number[i] = i;

    }
    
    cin >> N;

    /*
    sign[1] = -100;
    sign[2] = -100;
    sign[3] = -101;
    sign[4] = -101;
    sign[5] = -100;
    sign[6] = -102;
    sign[7] = -102;
    sign[8] = -102;

    */
    process(1);
    return 0;
}
