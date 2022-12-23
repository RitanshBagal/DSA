#include <iostream>
using namespace std;

int main(){
    int n = 7;
    int arr[n] = {1,2,3,5,6,9,10};

    // print the Array
    for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;

    // print the missing elements 
    
    cout<<"Missing element= ";

    int diff = 1-0;
    for(int i = 0;i<n;i++){
        if(arr[i]-i!=diff){
            while(diff<arr[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }


    return 0;
}