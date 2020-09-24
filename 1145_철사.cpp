//
//  1145_철사.cpp
//  euler_mac
//
//  Created by Mac on 9/4/20.
//  Copyright © 2020 Mac. All rights reserved.
//

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    
    int answer = 0;
    for(int i=1; i<=N; i++){
        answer += i;
    }
    answer += (N+1) +1;
    
    printf("%d", answer);
    return 0;
}
