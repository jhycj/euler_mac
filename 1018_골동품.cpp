//
//  1018_골동품.cpp
//  euler_mac
//
//  Created by Mac on 8/17/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    
    int my_first, your_first;
    int my_diff , your_diff;

    
    cin>> my_first >> my_diff >> your_first >> your_diff;
    
    if(my_first == your_first){
        printf("%d", my_first);
    }
    else{
        while(my_first < your_first){
            my_first += my_diff;
            your_first -= your_diff;
        }
        printf("%d", my_first); 
    }
    
    
    return 0;
}
