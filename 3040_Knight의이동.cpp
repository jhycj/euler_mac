#include<iostream>
#include<queue> 
#include<vector> 
#include<utility> 
#define INF 100 
using namespace std; 

//vector<vector<int>> map;
int map[9][9]{};

int dy[8] = {-2, -1, 1, 2, 2,1, -1, -2}; 
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 


void init_map(){

	for(int i=1; i<=8; i++){
		for(int j=1; j<=8; j++){
			map[i][j] = INF; 
		}

	}
}

void bfs(int sy, int sx){
	queue<pair<int,int>> Q; 
	Q.push(make_pair(sy, sx)); 
	int visit[9][9]{}; 

	while(!Q.empty()){
		int y = Q.front().first;
		int x = Q.front().second; 
		visit[y][x] = 1; 
		Q.pop(); 
		for(int i=0; i<8; i++){

			int ty = y + dy[i]; 
			int tx = x + dx[i];

			if(ty>=1 && ty<= 8 && tx>=1 && tx<= 8 && visit[ty][tx] ==0 ){

				if(map[ty][tx] > map[y][x] + 1){
					map[ty][tx] = map[y][x] + 1; 
					Q.push(make_pair(ty, tx)); 
					visit[ty][tx] = 1; 
				}
			} 
		}

	}


}


int main(){

	char ch1;
	char ch2;  
	int sx; 
	int ex; 
	cin >> ch1>> sx; 
	cin>> ch2>> ex; 

	int sy = int(ch1) - 96 ; 
	int ey = int(ch2) - 96 ; 
	//printf("%d", sy); 
	//printf("%d", ey); 

	init_map(); 
	map[sy][sx] = 0; 
	bfs(sy, sx); 
	printf("%d", map[ey][ex]); 
	return 0; 
}