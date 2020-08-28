//
//  4127_최상급갈비.cpp
//  euler_mac
//
//  Created by Mac on 8/15/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
#include<iostream>
#include<stack>

using namespace std;
stack<int> S;
int N;

void print_stack(stack<int> S){
    stack<int> tS = S;
    stack<int> A;
    while(!tS.empty()){
        int top_n= tS.top();
        A.push(top_n);
        tS.pop();
    }
    //printf("tS.size(): %d\n", tS.size() );
    while(!A.empty()){
        printf("%d", A.top());
        A.pop();
            
    }
    printf("\n");
}

bool is_prime(int N){
    
    if(N %2 ==0){
        if(N==2){return true;}
        else {return false;}
    }
    else{
        for(int i=2; i<= (int)sqrt(N); i++){
            if(N % i ==0){
                return false;
            }
        }
        return true;
    }
}

int stack_to_int(stack<int> S){
    stack<int> tS = S;
    int answer = 0;
    long n = tS.size();
    for(int i=0; i< n; i++){
        answer += tS.top() * pow(10, i);
        tS.pop();
    }
    return answer;
}

void process(){
    int prime_1[4] = {2, 3, 5, 7};
    int prime_s[4] = {1, 3, 7, 9};
    
    if(S.size() == N){
        print_stack(S);
        //printf("h\n");
        return;
    }
    else{
        if(S.size() ==0){
            for(int i=0; i<4; i++){
                S.push(prime_1[i]);
                process();
                S.pop();
            }
        }
        else{ // S.size() >= 1 &&  <N
            for(int i=0; i<4; i++){
                S.push(prime_s[i]);
                int tmp_num = stack_to_int(S);
                S.pop();
                if(is_prime(tmp_num)){//
                    S.push(prime_s[i]);
                    process();
                    S.pop();
                    
                }
            }
        }
    }
}

int main(){
    cin>> N;
    process();
    
    return 0;
}
