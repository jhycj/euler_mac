//
//  4254_디저트.cpp
//  euler_mac
//
//  Created by Mac on 9/7/20.
//  Copyright © 2020 Mac. All rights reserved.
//
#include<vector>
#include <stdio.h>
#include<iostream>
#include<stack>
#include<list>
#include<cmath>

using namespace std;
int N;
vector<int> Nums;
stack<int> S;
list<int> array2list(vector<int> Nums, stack<int> S){
    
    list<int> retL{};
    stack<int>revS{};
    
    while(!S.empty()){
        int tmp = S.top();
        revS.push(tmp);
        S.pop();
    }
    int i = 0;
    while(!revS.empty()){
        retL.push_back(Nums[i]);
        i++;
        retL.push_back(revS.top());
        revS.pop();
    }
    retL.push_back(Nums[i]);
    return retL;
    
}

int get_len(unsigned int N){
    int q = 1;
    if(N<10){
        return 1;
    }
    
    else{
        int idx = 1;
        while(q!=0){
            idx++;
            q = N / pow(10, idx);
        }
        return idx;
    }
}

int list2int(list<int> L){
    
    // '.' : -102 처리하기
    list<int> :: iterator it, it_first, it_second;
    
    for(it = L.begin(); it!= L.end(); it++){
        if(*it == -102){
            it--;
            it_first = it;
            int first = *it_first;
            it++;
            it++;
            it_second = it;
            int second = *it_second;
            int insert_num = pow(10, get_len(second)) * first + second;
            it_second++;
            it++;
            L.erase(it_first, it_second);
            L.insert(it, insert_num);
            it--;
        }
    }
    
    
    int tmp = -1;
    for(it = L.begin(); it!= L.end(); it++){
        if(*it < 0){
            list<int> ::iterator it_front, it_second;
            it--;
            it_front = it;
            int first = *it_front;
            it++;
            if(*it == -100){
                it++;
                it_second = it;
                int second = *it_second;
                tmp = first + second;
                it_second++;
                it++;
                L.erase(it_front, it_second);
                L.insert(it, tmp);
                it--;
                
            }
            else if(*it == -101){
                it++;
                it_second = it;
                int second = *it_second;
                tmp = first - second;
                it_second++;
                it++;
                L.erase(it_front, it_second);
                L.insert(it, tmp);
                it--;            }

        }
        
    }
    
    return tmp;
    
}

void print_list(list<int> L){
    list<int> :: iterator it;
    
    for( it= L.begin(); it!= L.end(); it++){
        if(*it == -100){
            printf("+ ");
        }
        else if(*it == -101){
            printf("- ");
        }
        else if(*it == -102){
            printf(". ");
        }
        else{
            printf("%d ", *it);
        }
    }
    printf("\n");
    
    
}


void process(int* count_ptr){
    
    if(S.size() == N-1){
        list<int> L = array2list(Nums, S);
        int ret = list2int(L);
        if(ret == 0){
            (*count_ptr)++;
            
            if(*count_ptr <= 20){
                //printf("%d ", *count_ptr);
                print_list(L);
            }
            return;
        }
    }
    else{
        for(int i=-100; i>-103; i--){
            S.push(i);
            process(count_ptr);
            S.pop();
        }
    }
    
    
}



int main(){
    
    cin>> N;
   
    int count  = 0;
    
    for(int i=1; i<=N; i++){
        Nums.push_back(i);
    }

    process(&count);
    printf("%d ", count);
    return 0;
}
