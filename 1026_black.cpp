//
//  1026_black.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include <vector>

using namespace std;
int main(){
    /*
    int answer_arr[6] = {1,1,2,2,2,8};
    int input_arr[6]{};
    
    for(int i=0; i<6; i++){
        cin>> input_arr[i];
    }
    for(int i=0; i<6; i++){
        printf("%d ", answer_arr[i] - input_arr[i]);
    }
    */
    

    vector<int> V;
    V.push_back(1);
    V.push_back(1);
    V.push_back(2);
    V.push_back(2);
    V.push_back(2);
    V.push_back(8);
    
    vector<int> I;
    for(int i=0; i<6; i++){
        int tmp;
        cin>>tmp;
        I.push_back(tmp);
    }
    
    vector<int> :: iterator it;
    vector<int> :: iterator it_;
    it_ = I.begin();
    for(it = V.begin(); it!= V.end() ; it++){
        int tmp1 = *it;
        int tmp2 = *it_;
        printf("%d ", tmp1- tmp2);
        it_++;
    }
    
    
    
    return 0;
}
