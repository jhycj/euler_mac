//
//  1067_짝수인지홀수인지.cpp
//  euler_mac
//
//  Created by Mac on 9/10/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

#include<iostream>
#include<limits>
using namespace std;

int main(){
    
    int N;
    char tmp[62];
    
    cin>>N;
    for(int i=0; i<N; i++){
        scanf("%s", tmp);
        int j = 0;
        while(tmp[j] != '\0'){
            j++;
        }
        char end = tmp[j-1];
        //printf("%c", end);
        int end_ascii = end - 48;
        
        //printf("%d ", end_ascii);
        //printf("%d", end-48);
        
        if(end_ascii %2 ==0){
            cout<< "even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
        
    }
    
    
    return 0;
}
