#include<iostream>
#include<stack>
#include <array>
#include <vector>

using namespace std;
int map[21][21];
int N;
int gold_state[11][2];
int dist[11][11];
int arr[12] = {0,};
int visit[11]={0,};
int answer = 99999;


void count_dist(int N){
    int tmp_y, tmp_x;
    int tmp1_y, tmp1_x;
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            tmp_y = gold_state[i][0];
            tmp_x = gold_state[i][1];
            tmp1_y = gold_state[j][0];
            tmp1_x = gold_state[j][1];
            dist[i][j] = dist[j][i] =  abs(tmp_y-tmp1_y) + abs(tmp_x - tmp1_x);
            
        }
    }
}


void process(int level, int sum){
    if(level >N){
    
        if(answer > sum + dist[ arr[level-1]][0]){
            answer = sum + dist[ arr[level-1]][0];
        }
        return ;
    }
    else{
        for(int i=1; i<=N; i++){
            if(visit[i] ==0){
      
                arr[level] = i;
                visit[i] = 1;

                process(level+1, sum+ dist[i][arr[level-1]] );
                visit[i] = 0;
            }
        }
  
        
    }
}





int main(){
    int C, R;

    cin>> C>>R;
    int sy, sx;
    int tmp_x, tmp_y;
    cin>> sx>>sy;
    cin>>N;
    gold_state[0][0] = sy;
    gold_state[0][1] = sx;
    
    for(int i=1; i<=N; i++){
        cin >> tmp_x >> tmp_y;
        gold_state[i][0] = tmp_y;
        gold_state[i][1] = tmp_x;
        
    }
    
    count_dist(N);

    process(1, 0);
    cout<<answer;
    
    return 0;
    
}
