//// 3 2 1 4 의 경우를 잘 생각!!!!!!!!!!!!!!

#include <iostream> 
#include <stack> 
#include <vector> 
using namespace std; 
stack<int> S; 
int input_trains[4]; 
vector<char> answers; 
int recent_remove = 0; 

void get_input(){
  for(int i=0; i<4; i++){
    int tmp; 
    cin >> tmp; 
    input_trains[i] = tmp; 
  }
}

void process_train(){

  for(int i=0; i<4; i++){

    int train_num = input_trains[i]; 
    //일단 넣는다. 
    S.push(train_num); 
    answers.push_back('S'); 

    // 뺄수 있는지 체크 
    while(!S.empty()){
      
      if(S.top() == recent_remove+1){
        //제거 

        S.pop();
        answers.push_back('X') ; 
        recent_remove ++; 
      
      }
      else{
        break; 
      }
    }


  }
}





int main(){
  get_input(); 
  process_train(); 
  if (answers.size() != 8 ){
    cout << "impossible"; 

  }
  else{
    for(int i=0; i<answers.size(); i++){
    cout << answers[i];
  }
  }
  
  return 0; 
}