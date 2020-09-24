//
//  4167_간단한계산.cpp
//  euler_mac
//
//  Created by Mac on 9/6/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include<list>
#include<queue>
using namespace std;



stack<int> S;
queue<list<int>> A;
int N;
int numbers[9] = {1,2,3,4,5,6,7,8,9};

list<int> stack2list(stack<int> S){
    
    list<int> ret_list;
    stack<int>rev_S ;
    
    while(!S.empty()){
        
        int top = S.top();
        rev_S.push(top);
        S.pop();
    }
    int i = 0;
    while(!rev_S.empty()){
        ret_list.push_back(rev_S.top());
        rev_S.pop();
        ret_list.push_back(numbers[i]);
        i++;
    }
    
    return ret_list;
}


int list2int(list<int> l){
    int ret = 0;

    list<int> :: iterator it, it_front, it_back;
    
    for(it = l.begin(); it!= l.end(); it++){
        if(*it == -12){
            
            list<int> :: iterator it_front, it_back;
            it --;
            int first = *it;
            it_front = it;
            it++;
            it++;
            int second = *it;
            it_back = it;
            it_back++;
            it = l.erase(it_front, it_back);
            
            int tmp = 10 * first + second;
            it=l.insert(it, tmp);
            
            it--; 
            
            
            /*
            it = l.erase(it);
            int second = (*it); //second: 2
            l.erase(it); // it: -11
            it--; // it: 1
            int first = (*it);
            int result = first* 10 + second;
            
            l.erase(it);
            it++;
            l.insert(it, result);
            it --;
             */
        }
    }
    
    it = l.begin();
    if(*it == -10){
        l.erase(it);
    }
    else if(*it == -11){
        it=l.erase(it);
        int tmp = *it ;
        tmp = (-1) * tmp;
        l.insert(it, tmp);
    }
    
    it = l.begin();
    ret = *it; //12
    while(it != l.end()){
        it++;
        if(*it == -10){
            it++;
            int tmp = *it;
            ret += tmp;
        }
        else if(*it ==-11){
            it++;
            int tmp = *it;
            ret -= tmp;
        }
    }
    //printf("%d\n", ret);
    return ret;
    
}

void print_list(list<int> L){
    list<int>::iterator it;
    it = L.begin();
    while(it != L.end()){
        int tmp = *it;
        if(tmp <0){
            switch(tmp){
                case -10:
                    printf("+");
                    break;
                case -11:
                    printf("-");
                    break;
                case -12:
                    printf("");
                    break;
            }
        }
        else{
            printf("%d", tmp);
        }
        it++;
    }
    printf("\n");
}



void process(int* count_ptr){
    int d[3] = {-11, -10, -12};
    
    if(S.size() == 9){
        list<int> L = stack2list(S);
        int ret =list2int(L);
        if(ret ==N){
            A.push(L);
            //print_list(L);
            (*count_ptr) ++;
        }
        return;
        
    }
    else{
        for(int i=0; i<3; i++){
            S.push(d[i]);
            process(count_ptr);
            if(!S.empty()){
                S.pop();
            }
        }
    }
}



int main(){
    int count = 0;
    //int N;
    cin>>N;
    
    S.push(-11);
    process(&count);

    //S init
    while(!S.empty()){
        S.pop();
    }

    S.push(-10);
    process(&count);
    
    //printf("%d\n", count);
    
    if(count != 0){
        while(!A.empty()){
            list<int> L = A.front();
            A.pop();
            print_list(L);
        }
        
    }
    else{
        printf("0"); 
    }

    
    return 0;
}
