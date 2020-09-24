#include<iostream>
using namespace std;

int main(){
    
    int arr[11] ;
    int sum_arr[11];
    int diff_arr[11];
    
    for(int i=1; i<=10; i++){
        cin>> arr[i];
    }
    
    int sum = 0;

    for(int i=1; i<=10; i++){
        sum += arr[i] ;
        sum_arr[i] = sum;
        int tmp = abs(sum - 100);
        diff_arr[i] = tmp;
        
    }
    int min = 1000000;
    int grade = 0;
    for(int i=1; i<=10; i++){
        if(diff_arr[i] <= min){
            min = diff_arr[i];
            grade = sum_arr[i];
        }
    }
    printf("%d", grade);
    
    
    return 0;
}
