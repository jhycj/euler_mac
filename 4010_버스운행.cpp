//
//  4010_버스운행.cpp
//  euler_mac
//
//  Created by Mac on 8/12/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
stack<int> S;

int adjoint[7][7] {};
int visit[7]{};
int count = 0;
int answer[26][7];



void print_answer(int* count_ptr){
    vector<int> V;
    for(int i=1; i<= *count_ptr; i++){
        V.push_back(answer[i][0]);
    }
    sort(V.begin(), V.end());
    int before_v = 0;
    
    for (int v : V){
        if(v == before_v){
            continue;
        }
        before_v = v;
        
        for(int i=1; i<= *count_ptr; i++){
            if(answer[i][0] ==v){
                for(int j=1; j<=v; j++){
                    //printf("%d ", answer[i][j]);
                    char tmp;
                    switch (answer[i][j]) {
                        case 1:
                            tmp = 'a';
                            break;
                        case 2 :
                            tmp = 'b';
                            break;
                        case 3 :
                            tmp = 'c';
                            break;
                        case 4 :
                            tmp = 'd';
                            break;
                        case 5 :
                            tmp = 'e';
                            break;
                        case 6:
                            tmp = 'f';
                            break;
                        default:
                            break;
                            
                    }
                    printf("%c", tmp);
                }
                printf("\n");
            }
            
        }
    }
}


void print_stack(stack<int> S, int* count_ptr){
    stack<int> tS = S;
    int front= 0;
    stack<int> A;
    char tmp;
    
    while(!tS.empty()){
        A.push(tS.top());
        tS.pop();
    }
    answer[*count_ptr][front] = A.size();
    front++;
    while(!A.empty()){
        
        answer[*count_ptr][front] = A.top();
        front++;
        
        //printf("%c ", tmp);
        A.pop();
    }
    //cout<< answer<< endl;
}


void process(int* count_ptr){
    if(S.top() == 6){
        *count_ptr += 1;
        print_stack(S, count_ptr);
        //printf("\n");
        return;
    }
    
    
    else{
        int tmp_top = S.top();
        
        for(int i=1; i<= 6 ; i++){
            if(visit[i] != 1 && adjoint[tmp_top][i] == 1 && adjoint[i][tmp_top]==1){
                S.push(i);
                visit[i] = 1;
                process(count_ptr);
                visit[i] = 0;
                S.pop();
            }
        }
    }
}



int main(){
    
    int N;
    int count = 0;
    int alpha1, alpha2 = 0;
    //init
    adjoint[1][2] = adjoint[2][1] = 1;
    adjoint[1][3] = adjoint[3][1] = 1;
    
    adjoint[2][3] = adjoint[3][2] = 1;
    adjoint[2][4] = adjoint[4][2] = 1;
    adjoint[2][5] = adjoint[5][2] = 1;
    
    adjoint[3][4] = adjoint[4][3] = 1;
    adjoint[3][5] = adjoint[5][3] = 1;

    adjoint[4][5] = adjoint[5][4] = 1;
    adjoint[4][6] = adjoint[6][4] = 1;
    
    adjoint[5][6] = adjoint[6][5] = 1;
    
    
    
    
    std:: cin>> N;
    
    for(int i=0; i<N; i++){
        
        for(int j=0; j<2; j++){
            char tmp;
            int alpha = 0;
            
            
            cin >> tmp;
            
            switch (tmp) {
                case 'a':
                    alpha = 1;
                    break;
                case 'b' :
                    alpha = 2;
                    break;
                case 'c' :
                    alpha = 3;
                    break;
                case 'd' :
                    alpha = 4;
                    break;
                case 'e' :
                    alpha =5;
                    break;
                case 'f':
                    alpha = 6;
                    break;
                default:
                    break;
            }
            if(j==0){
                alpha1 = alpha;
            }
            else if(j==1){
                alpha2 = alpha;
            }
        }
        
        adjoint[alpha1][alpha2] = adjoint[alpha2][alpha1] = 0;
        alpha1 = 0;
        alpha2 = 0;
    }
    /*
    for(int i=1; i<=6 ; i++){
        for(int j=1; j<=6; j++){
            printf("%d ", adjoint[i][j]);
        }
        printf("\n");
    }*/
    
    S.push(1);
    visit[1] = 1;
    process(&count);
    
    if(count == 0){
        printf("-1");
    }
    /*
    for(int i=0; i<= count; i++){
        for(int j=0; j<7; j++){
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    */
    print_answer(&count);
    
    return 0;
}
