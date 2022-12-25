#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int arr[n] = {3,6,8,8,10,12,15,15,15,20};

    int lastDuplicate;
    cout<<"Duplicate Elements-> ";
    for(int i = 0;i<n;i++){
        if(arr[i]==arr[i+1] && arr[i]!= lastDuplicate){
            cout<<arr[i]<<" ";
            lastDuplicate = arr[i]; // To not print again and again repeating elements.
        }
    }
    return 0;
}