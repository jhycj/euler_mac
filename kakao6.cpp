#include <stdio.h>
#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;

stack<int>S;

int map[4][4] ;
int sy, sx ;
vector<int> number_list;
vector<int> cathed_list;

void input_process(vector<vector<int>> board){
    int visit[7]{};
    
    for(int i=0; i<board.size(); i++){
        vector<int> tmp = board[i];
        
        for(int j=0; j<tmp.size(); j++){
            int num = tmp[j];
            map[i][j] = num;
            if(visit[num] ==0){
                number_list.push_back(num);
                visit[num] = 1;
            }
        }
    }
}

int arr[7];
vector<vector<int>> Combi;
int visit[7];

void process(int level, int N){
    
    if(level >N){
        printf("hello");
        vector<int> tmp ;
        for(int i=1; i<=N; i++){
            tmp.push_back(arr[i]);
        }
        Combi.push_back(tmp);

        return;
    }
    else{
        int before = arr[level-1];

        for(int i=0; i<number_list.size(); i++){ //(2,4,5,6)
            int tmp = number_list[i];
            if(visit[tmp] != 1 ){
                arr[level] = tmp;
                process(level+1, N);
                visit[tmp] = 0;
            }
        }
    }
}

void make_combi_list(vector<int> number_list){
    
    arr[0] = 0;
    process(1, number_list.size());
    for(int i=1; i<number_list.size(); i++){
        arr[i] = 0;
    }
    process(2, number_list.size());
    
}


int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    sy = r;
    sx = c;
    
    input_process(board);
    
    make_combi_list(number_list);
    
    cout<<Combi.size();
    return answer;
}
int main(){
    
    number_list.push_back(1);
    number_list.push_back(2);
    number_list.push_back(3);
    
    make_combi_list(number_list);
    
    return 0;
}
