#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Reverse(struct array *arr){
    for(int i = 0,j = arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
void display(struct array arr){
    for(int i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    struct array arr = {{1,2,3,4,5},10,5};
    Reverse(&arr);
    display(arr);
    return 0;
}