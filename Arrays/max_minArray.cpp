#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int arr[n] = {1,3,4,5,6,8,9,20,12,14};

    int min = arr[0];
    int max = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        else if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<<"Minimum element-> "<<min<<endl<<"Maximum element-> "<<max;
    return 0;
}