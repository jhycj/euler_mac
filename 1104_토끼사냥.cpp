//
//  1104_토끼사냥.cpp
//  euler_mac
//
//  Created by Mac on 9/8/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<vector>
using namespace std;

vector<int> get_divisors(int N){
    vector<int> ret;
    for(int i=1; i<=N; i++){
        if(N %i ==0){
            ret.push_back(i);
        }
    }
    return ret;
}

void make_combi(vector<int> Dx, vector<int> Dy){
    for(int i = 0; i<Dx.size(); i++){
        for(int j=0; j<Dy.size(); j++){
            printf("%d %d\n", Dx[i], Dy[j]);
        }
    }
}




int main(){
    int Y, X;
    scanf("%d %d",&X, &Y);
    vector<int> Dx = get_divisors(X);
    vector<int> Dy = get_divisors(Y);
    make_combi(Dx, Dy);
    return 0;
}
