//
//  4380_Letters.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<char> visit_alphabet;
stack<pair<int,int>> S;
int R, C;
char map[20][20];
int visit[20][20];


bool is_alphabet_available(char A){
    for(int i=0; i<visit_alphabet.size(); i++){
        if(visit_alphabet[i] == A){
            return false;
        }
    }
    return true;
}


bool is_end(pair<int, int> P){
    
    int y = P.first;
    int x = P.second;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    
    for(int i=0; i<4; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];
        char alphabet= map[ty][tx];
        if(ty>=0 && ty<R && tx>=0 && tx<C && visit[ty][tx] ==0 && is_alphabet_available(alphabet) == true ){
            return false; //keep going
        }
    }
    return true;
}




void process(int* answer_ptr){
    pair<int, int> P = S.top();

    if(is_end(P) == true){
        int tmp_answer = S.size();
        if(*answer_ptr< tmp_answer){
            *answer_ptr = tmp_answer;
        }
        return ;
    }
    else{
        int y = P.first;
        int x = P.second;
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};
        
        for(int i=0; i<4; i++){
            int ty = y+dy[i];
            int tx = x+dx[i];
            char alphabet =map[ty][tx];
            if(ty>=0 && ty<R && tx>=0 && tx<C && visit[ty][tx] ==0 && is_alphabet_available(alphabet)==true){
                visit[ty][tx] = 1;
                visit_alphabet.push_back(alphabet);
                S.push(make_pair(ty, tx));
                process(answer_ptr);
                S.pop();
                visit[ty][tx] = 0;
                visit_alphabet.pop_back();
            }
        }
    }

}


int main(){
    cin>> R>>C;
  
    char tmp[21];
    int answer = 0;
    for(int i=0; i<R; i++){
        scanf("%s", tmp);
        for(int j=0; j<C; j++){
            map[i][j] = tmp[j];
        }
    }
    int sy = 0;
    int sx = 0;
    S.push(make_pair(sy, sx));
    visit_alphabet.push_back(map[sy][sx]);
    visit[sy][sx] = 1;
    process(&answer);
    printf("%d", answer); 
    /*
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
