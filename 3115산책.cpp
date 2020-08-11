
//#include "3115산책.hpp"
#include<iostream>
#include<stack>

using namespace std;

int arr[4][4];
stack<int> S;
int visit[4][4];


void initialize(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            visit[i][j] = 0;
        }
    }
}

void stack_init(void){
    while(!S.empty()){
        S.pop();
    }
}

void visit_init(void){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            visit[i][j] = 0;
        }
    }
}


void process_0(int y, int x, int* prev_ret){ // 상하
    int dy[2] = {1, -1};
    int dx[2] = {0, 0};
    int ty, tx;
    int count = 0;
    int ret = 0;
    
    
    S.push(y);
    S.push(x);
    visit[y][x] = 1;
    
    for(int i=0; i<2; i++){
        ty = y+dy[i];
        tx = x + dx[i];
        if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
            count++;
                
        }
    }
    
    if(count==0){
        ret = (int) S.size() / 2;
        
        if(ret>*prev_ret){
            *prev_ret = ret;
        }
        //cout<<ret;
        return;
    }
    else{
        for(int i=0; i<2; i++){
            ty = y+dy[i];
            tx = x + dx[i];
            if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
     
                visit[ty][tx] = 1;
                process_0(ty, tx, prev_ret);
                visit[ty][tx] = 0;
                S.pop();
                S.pop();
            }
        }

    }
}

void process_1(int y, int x, int* prev_ret){ // 좌우
    int dy[2] = {0, 0};
    int dx[2] = {1, -1};
    int ty, tx;
    int count = 0;
    int ret = 0;
    
    
    S.push(y);
    S.push(x);
    visit[y][x] = 1;
    
    for(int i=0; i<2; i++){
        ty = y+dy[i];
        tx = x + dx[i];
        if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
            count++;
                
        }
    }
    
    if(count==0){
        ret = (int) S.size() / 2;
        
        if(ret>*prev_ret){
            *prev_ret = ret;
        }
        //cout<<ret;
        return;
    }
    else{
        for(int i=0; i<2; i++){
            ty = y+dy[i];
            tx = x + dx[i];
            if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
     
                visit[ty][tx] = 1;
                process_1(ty, tx, prev_ret);
                visit[ty][tx] = 0;
                S.pop();
                S.pop();
            }
        }

    }
}

void process_2(int y, int x, int* prev_ret){ // 좌우
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int ty, tx;
    int count = 0;
    int ret = 0;
    
    
    S.push(y);
    S.push(x);
    visit[y][x] = 1;
    
    for(int i=0; i<4; i++){
        ty = y+dy[i];
        tx = x + dx[i];
        if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
            count++;
                
        }
    }
    
    if(count==0){
        ret = S.size() / 2;
        
        if(ret>*prev_ret){
            *prev_ret = ret;
        }
        //cout<<ret;
        return;
    }
    else{
        for(int i=0; i<4; i++){
            ty = y+dy[i];
            tx = x + dx[i];
            if(visit[ty][tx] == 0 && ty>=0 && ty<4 && tx>=0 && tx<4 && abs(arr[ty][tx] - arr[y][x]) <=1 ){ //아직 방문 안했으면
     
                visit[ty][tx] = 1;
                process_2(ty, tx, prev_ret);
                visit[ty][tx] = 0;
                S.pop();
                S.pop();
            }
        }

    }
}




int main(){
    int ret = 0;
    int* prev_ret = &ret;
    int answer1 = 0;
    int answer0 = 0;
    int answer2 = 0;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }
    
    ///////
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            stack_init();
            initialize();
            *prev_ret = 0;
            process_0(i, j, prev_ret);
            //cout<< *prev_ret ;
            if(*prev_ret >= answer0){
                answer0 = *prev_ret;
            }
        }
        //cout<<endl;
    }
    //cout<<answer0<<endl;
    
    visit_init();
    stack_init();
    *prev_ret = 0;
    ///////
    

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            stack_init();
            initialize();
            *prev_ret = 0;
            process_1(i, j, prev_ret);
            //cout<< *prev_ret ;
            if(*prev_ret >= answer1){
                answer1 = *prev_ret;
            }
        }
        //cout<<endl;
    }
    //cout<<answer1<<endl;
    
    cout<<max(answer0, answer1)<<endl;
  
    
    visit_init();
    stack_init();
    *prev_ret = 0;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            stack_init();
            initialize();
            *prev_ret = 0;
            process_2(i, j, prev_ret);
            //cout<< *prev_ret <<' ';
            if(*prev_ret >= answer2){
                answer2 = *prev_ret;
            }
        }
        //cout<<endl;
    }
    cout<< answer2<<endl;
    

    return 0;
}
