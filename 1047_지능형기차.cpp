//
//  1047_지능형기차.cpp
//  euler_mac
//
//  Created by Mac on 8/31/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    int max_num = 0;
    int tmp_num = 0;
    for(int i=0; i<4; i++){
        int in, out;
        cin>> out>> in;
        tmp_num += (-1* out + in);
        if(max_num < tmp_num){
            max_num = tmp_num;
        }
    }
    printf("%d", max_num);
    return 0;
}
