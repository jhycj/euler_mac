//
//  3009_아이스크림배분.cpp
//  euler_mac
//
//  Created by Mac on 8/1/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <iostream>
//#include<stack>
//#include<vector>
//
//using namespace std;
//int N, M;
//stack<int> S;
//vector<int> arr;
//
int count_num=0;
//
//void print_vector(vector<int>  arr){
//    vector<int>a::iterator iter = arr.begin();
//    vector<int>::iterator end = arr.end();
//
//    while(iter!= end){
//        std::cout<< *iter<<' ';
//        iter++;
//    }
//    cout<< endl;
//}
//
//
//void process(){
//    if(arr.size() == N){
//        count_num ++;
//        print_vector(arr);
//        return;
//    }
//    else{
//        for(int i=1; i<=M; i++){
//            arr.push_back(i);
//
//            process();
//            arr.pop_back();
//        }
//    }
//}


int my_arr[7]={0,1,1,1,1,1,1};

int count_up(int i, int n){
    my_arr[i] += 1;
    if(my_arr[i] >n){
        my_arr[i] -=n;
        return count_up(i+1, n);
    }
    return i;
}

void proc(int m, int n){
    while(count_up(0,n)<m){
        for(int i=m-1 ; i>=0; i--){
            std::cout << my_arr[i]<<' ';
        }
        std::cout <<'\n';
        count_num++;
    }
}
int main(){
    
    //int N; int M;
    
    //N은 학생수, M은 아이스크림 가짓 수
    //stack<int> S;
    int N, M;
    std::cin>> N>> M;
    proc(N,M);
    std::cout<<count_num;
    return 0;
}
