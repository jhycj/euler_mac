
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include<stack>
#include<cmath>

using namespace std;
int map[21][28]{}; //1~ 27 ,26개 알파벳
int N ; //order size (사람수)
vector<int> menu_v;
stack<int> S;
vector<int> answer_v;
vector<vector<int>> V;
vector<vector<int>>A;

int visit[28]{};

vector<int> get_combi(stack<int>S){
    vector<int> ret;
    stack<int> revS;
    while(!S.empty()){
        int tmp = S.top();
        revS.push(tmp);
        S.pop();
    }
    while(!revS.empty()){
        int tmp = revS.top();
        //printf("%d ", tmp);
        ret.push_back(tmp);
        revS.pop();
    }
    return ret;
}

void stack_init(){
    while(!S.empty()){
        S.pop();
    }
}
void visit_init(){
    for(int i=0; i<28; i++){
        visit[i] = 0;
    }
}


int alpha2ascii(char C){
    int ret = C;
    ret -= 64;
    return ret;
}

void input_process(vector<string> orders){
    
    for(int i =0; i<orders.size(); i++){
        string each_str = orders[i] ;
        for(int j=0; j<each_str.length(); j++){
            int ascii_num = alpha2ascii(each_str[j]);
            map[i][ascii_num] = 1;
        }
    }
}

vector<int> which_menu_want(int n){ //n은 주문한 사람 번호 (0 ~ N-1까지)
    vector<int> ret;
    
    for(int i=0; i<menu_v.size(); i++){
        int menu_num = menu_v[i];
        if(map[n][menu_num] == 1){
            ret.push_back(menu_num);
        }
    }
    
    return ret;
}

void process(int want_len, vector<int> menu_list_person, int person_n){
    
    if(S.size() == want_len){
        answer_v = get_combi(S);
        V.push_back(answer_v);
        return;
    }
    else{
        int s_top = S.top();
        for(int i=0; i<menu_list_person.size(); i++){
            int menu_num = menu_list_person[i];
            
            if(visit[menu_num] == 0 && (s_top < menu_num)){
                S.push(menu_num);
                visit[menu_num] = 1;
                process(want_len, menu_list_person, person_n);
                S.pop();
                visit[menu_num] = 0;
            }
        }
    }
}

void combi_menu(int want_len, int person_n){
    stack_init(); // S = {}
    visit_init();
    vector<int> ret ;
    vector<int> menu_list_person = which_menu_want(person_n); //각 사람 별 menu
    for(int i=0; i<menu_list_person.size(); i++){
        stack_init();
        visit_init();
        S.push(menu_list_person[i]);
        process(want_len, menu_list_person, person_n);
    }
    stack_init();
    visit_init();

}


vector<int> make_menu_v(){
    for(int j=1; j<=27; j++){
        int count = 0;
        for(int i =0; i<N; i++){
            if(map[i][j] == 1){
                count++;
            }
        }
        if(count >=2){
            menu_v.push_back(j);
        }
    }
    return menu_v;
}

bool is_vector_in(vector<int> v, vector<vector<int>> visit_list){
    for(int i=0; i<visit_list.size(); i++){
        if(v == visit_list[i]){
            return true;
        }
    }
    return false;
}


void make_answer(int course_num){
    vector<vector<int>> visit_list;
    vector<pair<vector<int>, int>> tmp_v;
    
    int len = course_num;
    int max_count = -1;
    
    for(int i=0; i<V.size(); i++){
        if(V[i].size() == len && is_vector_in(V[i], visit_list) == false){
            int count = 0;
            visit_list.push_back(V[i]) ;
            
            for(int j=0; j<V.size(); j++){
                if(V[j] == V[i] ){
                    count++;
                }
            }
            if(count>= 2 && max_count <= count){
                
                pair<vector<int>, int> P = make_pair(V[i], count);
                tmp_v.push_back(P);
                
                //A.push_back(P);
                max_count = count;
            }
            
        }
        
    }
    
    for(int i=0 ; i<tmp_v.size(); i++){
        if(max_count == tmp_v[i].second){
            A.push_back(tmp_v[i].first);
        }
    }
}

void make_dict_order(){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size()-1-i; j++){
            
            vector<int> first = A[j];
            vector<int> second = A[j+1];
            int max_idx = min(first.size(), second.size());
            for(int k = 0; k<max_idx; k++){
                if(first[k] == second[k]){
                    continue;
                }
                else if(first[k] > second[k]){
                    swap(A[j], A[j+1]);
                    break;
                }
                else if(first[k] < second[k]){
                    break;
                }
            }
            
        }
    }
}

vector<string> vector2answer(vector<vector<int>> A){
    vector<string> ret;
    for(int i=0; i<A.size(); i++){
        vector<int> Ai = A[i];
        string s;
        
        for(int j=0; j<Ai.size(); j++){
            char ascii = char(Ai[j]+64);
            
            s = s + ascii;
        ret.push_back(s);
    }
    return ret;
}


vector<string> solution(vector<string> orders, vector<int> course){
    //input process
    input_process(orders);
    N = orders.size();

    menu_v = make_menu_v();
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<course.size(); j++){
            int len = course[j];
            combi_menu(len, i);
        }
    }
    
    
    for(int i=0; i<course.size(); i++){
        int len = course[i];
        make_answer(len);
        
    }
    
    make_dict_order();
    /*
    for(int i=0; i<A.size(); i++){
        vector<int>Ai = A[i];
        for(int j=0; j<Ai.size(); j++){
            printf("%d ", Ai[j]);
        }
        printf("\n");
    }
    */
    vector<string> answer = vector2answer(A);
    //vector<string> answer;
    
    return answer;
}

