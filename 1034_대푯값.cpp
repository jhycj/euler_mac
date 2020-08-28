//
//  1034_대푯값.cpp
//  euler_mac
//
//  Created by Mac on 8/12/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<array>

int main(){
    
    std::array<int, 10> arr{};
    int count_arr[10] = {0,};
    
    int sum{};
    int answer;
    
    for(int a: arr){
        std::cin>> a;
        sum += a;
    }
    
    for(int i=0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(arr.at(i) == arr.at(j)){
                count_arr[i] ++;
            }
        }
    }
    int most_freq = 0;
    
    for(int x: count_arr){
        printf("%d ", x);
    }
    
    for(int i=0; i<10; i++){
        if(most_freq < count_arr[i]){
            most_freq = count_arr[i];
            answer = arr[i];
        }
    }
    
    printf("%d\n", sum /arr.size());
    printf("%d", answer);
    
    
    
    
    
    return 0;
}
