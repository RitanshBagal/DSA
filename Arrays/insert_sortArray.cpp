#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};
// Display()
void display(struct array arr){
    for(int i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

// InsertSort()
// Insertion in a sorted array
void insertSort(struct array *arr, int n){
    if(arr->length == arr->size){
        return;
    }
    int i = arr->length-1;
    while(i>=0&& arr->A[i]>n){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = n;
    arr->length++;
}
int main(){
    array arr = {{1,3,4,5,6},10,5};
    display(arr);
    insertSort(&arr,2);
    display(arr);

    return 0;
}