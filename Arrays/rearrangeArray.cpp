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
void Rearrange(struct array *arr){
    int i,j;
    i = 0;
    j = arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}
void display(struct array arr){
    for(int i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    array arr = {{2,-3,25,10,-15,-7,-8},10,6};
    cout<<"Before Rearranging: ";
    display(arr);
    cout<<"After Rearranging: ";
    Rearrange(&arr);
    display(arr);
    return 0;
}