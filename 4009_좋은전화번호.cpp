//
//  4009_좋은전화번호.cpp
//  euler_mac
//
//  Created by Mac on 7/30/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include "4009_좋은전화번호.hpp"
#include<string>
#include<iostream>
#include<stack>


using namespace std;

/*

class PhoneNumber{
public:
    PhoneNumber(const std::string& str){
        for(auto& c : str){
            if(std::isdigit(c)){
                num_.push_back(c - '0');
            }
        }
    }
    void print(){
        auto iter = num_.begin();
        const auto end = num_.end();
        while(iter!= end){
            std::cout << *iter;
            iter++;
        }
        std::cout << std::endl;
    }
private:
    std::vector<unsigned int> num_;
};


*/

int phone_structure[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 10}};
int adjoint[10][10]={0,};
int test_number[5][7];
void make_adjoint(){
    
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int ty, tx, y, x;
    int i;

    //cout<<phone_structure[3][2]<<endl;
    
    for(y=0; y<=3; y++){
        for(x=0; x<=2; x++){
            
            if(phone_structure[y][x] <10){
                int number1 = phone_structure[y][x];
                //cout<<number1<<endl;
                for(i=0; i<4; i++){
                    ty = y+dy[i];
                    tx = x + dx[i];
                    if(ty>=0 && ty<4 && tx>=0 && tx<3 && phone_structure[ty][tx] <10){
                        int number2 = phone_structure[ty][tx];
                        adjoint[number1][number2] =1;
                        adjoint[number2][number1] = 1;
                    }
                    
                }            }
            
        }
    }
}

int* get_test_number_row(int i){
    
    return test_number[i];
}

string check(int * arr){
    int visit[10] = {0,};
    int not_good = 0;
    
    
    for(int i=0; i<6; i++){
        int val = arr[i];
        //visit[val] = 1;
        if(visit[val] == 1){
            not_good = 1;
            break;
        }
       
        
        else{
            visit[val] = 1;
            int next_val = arr[i+1];
            if(adjoint[val][next_val] ==0 || visit[next_val] == 1){
                not_good = 1;
                break;
            }
        }
    }
    
    if(not_good ==1 ){
        return "nogood";
    }
    else{
        return "good";
    }
}





int main(){
    std::string str;
    for(int i =0; i < 5; i++){
        std::cin >> str;
        
        for(int j=0; j<3; j++){
            string tmp = str.substr(j, 1);
            test_number[i][j] = stoi(tmp);
        }
        
        for(int j=4; j<8; j++){
            string tmp = str.substr(j,1);
            test_number[i][j-1] = stoi(tmp);
        }
            
    }
    
   
    make_adjoint();
    
    for(int i=0 ; i<5; i++){
        string answer= check(get_test_number_row(i));
        cout<< answer<<endl;
    }


    return 0;
}



