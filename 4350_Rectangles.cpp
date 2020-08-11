//
//  4350_Rectangles.cpp
//  euler_mac
//
//  Created by Mac on 7/30/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include "4350_Rectangles.hpp"
#include<iostream>
using namespace std;

int N;
int Rectangles[1000][2];
int dynamic_table[1000][2] ;

int get_max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

void initialize(){
    dynamic_table[0][0] = Rectangles[0][0];
    dynamic_table[0][1] = Rectangles[0][1] ;
    //dynamic_table[][0] : 회전 안했을 때
    //dynamic_table[][1] : 회전 했을 때
    
}

void make_dynamic_table(int n){
    //n번째 도형 회전 안했을 때
    
    int BoCx = dynamic_table[n-1][1] + Rectangles[n][0] + abs(Rectangles[n][1] - Rectangles[n-1][0]);
    int BxCx = dynamic_table[n-1][0] + Rectangles[n][0] + abs(Rectangles[n][1] - Rectangles[n-1][1]);
    
    int BoCo = dynamic_table[n-1][1] + Rectangles[n][1] + abs(Rectangles[n][0] - Rectangles[n-1][0]);
    int BxCo = dynamic_table[n-1][0] + Rectangles[n][1] + abs(Rectangles[n][0] - Rectangles[n-1][1]);
    
    
    
    dynamic_table[n][0] = get_max(BoCx, BxCx);
    dynamic_table[n][1] = get_max(BoCo, BxCo);
    
    //n번째 도형 회전 했을 때
}

int main(){
    
    cin>> N;
    for(int i=0; i<N; i++){
        cin>>Rectangles[i][0]>> Rectangles[i][1];
    }
    initialize();
    
    for(int i=1; i<N; i++){
        make_dynamic_table(i);
    }
    /*
    for(int i=0; i<N; i++){
        cout<< dynamic_table[i][0] <<' ' << dynamic_table[i][1] <<endl;
    }*/
    cout<< get_max(dynamic_table[N-1][0], dynamic_table[N-1][1]);
    
    return 0;
}
