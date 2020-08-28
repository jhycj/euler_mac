//
//  1024_주사위세개.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    
    int a, b,c;
    int answer{};
    cin>> a>> b>> c;
    
    if(a==b && a==c){
        answer = 10000 + (a*1000);
    }
    else if(a!= b && b!= c && c!= a){
        int max_n = max(max(a, b), c);
        answer = (max_n) * 100;
    }
    else{
        if(a==b){answer = 1000 + a*100;}
        else if(b==c){answer = 1000 + b*100;}
        else {answer = 1000 + c*100;}//c==a
    }
    printf("%d", answer);
    return 0;
}
