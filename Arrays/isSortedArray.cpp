#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};
bool isSorted(struct array arr){
    for(int i = 0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    array arr = {{1,2,3,4,5},10,5};
    cout<<isSorted(arr);
    return 0;

}