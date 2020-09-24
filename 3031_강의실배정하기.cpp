#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
int arr[21][2];

int N;

void sort_arr(){
    
    for(int i=1; i<=N; i++){

        for(int j=1; j<= N-i-1; j++){
            
            if(arr[j][1] > arr[j+1][)
        }
        
    }

    
}

int main(){
    
    cin>> N;
    
    for(int i=1; i<=N; i++){
        int num , start, end;
        cin>> num>> start >> end;
        arr[num][0] = start;
        arr[num][1] = end;
    }
    
    
    return 0;
}
