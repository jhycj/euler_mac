#include <iostream>
#include <queue> 
#include<vector> 
#include <algorithm>


using namespace std; 
vector<int> answer; 
int N; 
int M; 

int adjoint[102][102] = {0,}; 
int num_commit = 0; 

int visit[102] = {0,}; 

void get_input(){
  cin >> N; 
  cin >> M; 

  for(int i=0; i<M; i++){
    int x; 
    int y; 
    cin >> x >> y; 
    adjoint[x][y] = 1; 
    adjoint[y][x] = 1; 
  }
}

void print_adjoint(){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cout <<adjoint[i][j] ; 
    }
    cout<<endl; 
  }
}


void bfs(int start_node, int id){
  queue<int> Q; 
  Q.push(start_node);
  //visit[start_node] = 1; 

  while(!Q.empty()){
    int now_node = Q.front(); 

    for(int i=1; i<=N; i++){
      if(adjoint[i][now_node] == 1 && visit[i] ==0){ //인접했는데 아직 방문 안함 
        Q.push(i); 
      }
    }
    Q.pop(); 
    visit[now_node] = id ; 
  }
}


vector<int> get_family_list(int id){
  vector<int> V; 
  for(int i=1; i<=N; i++){
    if (visit[i] == id){
      V.push_back(i); 
    }
  }
  return V; 
}

int get_max_distance(int p_id, vector<int> F){
  
  queue<int> Q; 
  int visit[102] = {0, }; 
  int max_conn = -1; 

  Q.push(p_id); 
  visit[p_id] = 1; 

  while(!Q.empty()){
    int front_id = Q.front(); 
    for(int i=0; i<F.size(); i++){
      int family_id = F[i] ; 
      if(adjoint[front_id][family_id] == 1 && visit[family_id]== 0){ //아직 방문 안하고, 인접해 있다면 
        Q.push(family_id); 
        visit[family_id] = visit[front_id] + 1; 
      }    
    }
    Q.pop(); 
  }

  int max_dist = -1; 
  for(int i=0; i<F.size(); i++){
    if (max_dist < visit[F[i]]){
      max_dist = visit[F[i]]; 
    }
  }
  return max_dist; 

}

int get_first_id(vector<int> F){
  
  int min_distance = 999999; 
  int min_first_id = -1; 
  // 최소 거리 갖는 ID찾기 
  for(int i=0; i<F.size(); i++){
    int tmp_first = F[i];
    int tmp_max_distance = get_max_distance(tmp_first, F) ;

    if(min_distance > tmp_max_distance){
      min_distance = tmp_max_distance; 
      min_first_id = tmp_first; 
    }
  }
  return min_first_id; 
}





int main() {
	get_input(); 
  //print_adjoint();


  int num_commit = 0; 
  for(int i=1; i<=N; i++){
    if(visit[i] == 0){ //아직 방문 안한 Node 에 대해서 group 찾기 
      
      bfs(i, num_commit+1); 
    
      num_commit ++; 
    } 
  }
  cout <<num_commit << endl; 
  /*
  for(int i=1; i<=N; i++){
    cout <<visit[i] << ' '; 
  }
  cout<<endl;
  */
  for(int i=1; i<=num_commit; i++){
    vector<int> F = get_family_list(i);
    int first_id = get_first_id(F); 
    //cout << first_id << endl;  

    answer.push_back(first_id); 

  }

  sort(answer.begin(), answer.end()); 
  
  for(int i=0; i<answer.size(); i++){
    cout << answer[i]<< endl; 
  }

	return 0;
}