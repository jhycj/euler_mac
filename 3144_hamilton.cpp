//
//  3144_hamilton.cpp
//  euler_mac
//
//  Created by Mac on 7/30/20.
//  Copyright © 2020 Mac. All rights reserved.
//

//#include "3144_hamilton.hpp"
#include<iostream>
#include<stack>

using namespace std;

int N; //정점의 개수
int adjoint[10][10];
int start_vertex ;
int visit[10] = {0,};
stack<int> S;
int count_answer = 0;

void print_path(stack<int> tS){
    stack<int> S = tS;
    stack<int> A;
    while(!S.empty()){
        int tmp = S.top();
        A.push(tmp);
        S.pop();
    }
    while(!A.empty()){
        cout<<A.top()<<' ';
        A.pop();
    }
    cout<<start_vertex<<endl;
}


void process(int n){
    if(S.size() == N-1 && adjoint[n][start_vertex] == 1 ){
        S.push(n); //S.size == N 이 될 것
        visit[n] = 1;
        //S.push(start_vertex); // S.size == N+1 이 될 것
        print_path(S); //N+1짜리 경로 출력
        count_answer++;
        //cout<<"hello"<<endl;
        //S.pop();
        return;
    }
    else if(S.size() == N-1 && adjoint[n][start_vertex] == 0){ //해밀턴 경로가 존재하지 않는 것!
        visit[n] = 1;
        S.push(n);
        return;
        
    }
    
    else {
        S.push(n);
        visit[n] = 1; //n번째 방문 했음 == 스택에 넣었음!
        for(int i=1; i<= N; i++){
            if(visit[i] ==0 && adjoint[n][i] ==1 ){ //차례대로 조사하는데 아직 정점 방문 안했고 n이랑 인접하면
                process(i);//끝나고 돌아오면
                visit[i] = 0; //방문 처리 리셋
                S.pop();
                //cout<<S.size()<<endl;
                
            }
        }
    }
    
}


int main(){
    
    cin>> N>> start_vertex;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>> adjoint[i][j] ;
        }
    }
    
    process(start_vertex);
    //cout<<count_answer;
    if(count_answer ==0){
        cout<<-1;
    }
    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<< adjoint[i][j];
        }
        cout<<endl;
    }*/
    
    return 0;
}
