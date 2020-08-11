//
//  3106_byIRO.cpp
//  euler_mac
//
//  Created by Mac on 7/19/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include "3106_byIRO.hpp"
#include <list>
#include <iostream>

void print_proc(std::list<unsigned int>& prefix,
                std::list<unsigned int>& nums){
    if(nums.size() == 0){
        for(auto& p : prefix){
            std::cout << p <<" ";
        }
        std::cout << std::endl;
        return;
    }
    for(auto& num : nums){
        std::list<unsigned int> next = nums;
        std::list<unsigned int> next_prefix = prefix;
        next.remove(num);
        next_prefix.push_back(num);
        print_proc(next_prefix,next);
    }
}


int main(int argc, char* argv[]){
    int n,m;
   
    std::list<unsigned int> q;
    std::list<unsigned int> prefix;
    
    
     std::cin >> n>>m;
    for(size_t i = 0; i < m; ++i){
        
    }
    print_proc(prefix,q);
    return 0;
}
