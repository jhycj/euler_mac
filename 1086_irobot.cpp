//
//  1086_irobot.cpp
//  euler_mac
//
//  Created by Mac on 9/2/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;
vector<int> robots;
vector<pair<int, pair<int, int>>> commands;

int do_command(int n, int a, int b){
    int ret = 0;
    if(n==1){//min
        ret = 20000;
        for(int i= a; i<= b; i++){
            if(ret > robots[i]){
                ret = robots[i];
            }
        }
    }
    else if(n==2){//max
        ret = -20000;
        for(int i= a; i<= b; i++){
            if(ret < robots[i]){
                ret = robots[i];
            }
        }
    }
    else if(n==3){//sum
        ret = 0;
        for(int i= a; i<= b; i++){
            ret += robots[i];
        }
    }
    return ret;
}



int main(){
    int command_n;
    int N;
    cin>> N;
    for(int i=0; i<N; i++){
        int tmp;
        cin>> tmp;
        robots.push_back(tmp);
    }
    cin>> command_n;
    
    for(int i=0; i<command_n; i++){
        int a, b, c;
        cin>> a>> b>> c ;
        pair<int, pair<int,int>> Q ;
        pair<int, int> P;
        Q.first = a;
        P.first = b;
        P.second = c;
        Q.second = P;
        
        commands.push_back(Q);
    }
    
    for(int i=0; i<commands.size(); i++){
        int tmp_command = commands[i].first;
        int a = commands[i].second.first;
        int b = commands[i].second.second;
        
        int ret = do_command(tmp_command, a-1, b-1);
        printf("%d\n", ret);
        
    }
    
    
    
    return 0;
}
