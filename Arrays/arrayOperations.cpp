#include <iostream>
using namespace std;

struct array
{
    int A[10];
    int size;
    int length;
};

// DISPLAY
void Display(struct array arr)
{
    int i;
    cout << "Elements are: " << endl;
    for (i = 0; i < arr.length; i++){
        cout << arr.A[i] << " ";
    }
    cout<<endl;
}
//APPEND
void Append(struct array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}
//INSERTION
void Insert(struct array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length-1)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
//DELETION
void Delete(struct array *arr, int index){
    if(index>=0 && index <= arr->length){
        for(int i = index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}
// SWAP FUNCTION
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// LINEAR SEARCH
int linearSearch(struct array *arr, int key){
    for(int i = 0;i<arr->length;i++){
    if(key == arr->A[i]){
        swap(&arr->A[i],&arr->A[i-1]);
        return i;
    }
    }
    return -1;
}
// BINARY SEARCH
int binarySearch(struct array *arr, int key){
    int s=0,e = arr->length;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr->A[mid] == key)
        {
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;

}

// GET()
int Get(struct array arr, int index){
    if(index >= 0 && index< arr.length){
        return arr.A[index];
    }
    return -1;
}
// SET()
int Set(struct array *arr, int index, int x){
    if(index>=0 && index< arr->length){
        arr->A[index] = x;
    }
}
// Max()
int Max(struct array arr){
    int max = arr.A[0];
    for(int i = 0;i<arr.length;i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}
// Min()
int Min(struct array arr){
    int min = arr.A[0];
    for(int i = 0;i<arr.length;i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}
// Sum()
int Sum(struct array arr){
    int sum = 0;
    for(int i = 0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}
// Average()
int Average(struct array arr){
    int sum = 0;
    for(int i = 0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    int average = sum/2;
    return average;
}
// Reverse()
void Reverse(struct array *arr){
    for(int i = 0,j = arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
// Reverse using other array
void Reverse2(struct array *arr){
    int *B;
    int i,j;

    B = (int*)malloc(arr->length*sizeof(int)); // This does not work well!
    for(i = arr->length-1,j = 0;i<=0;i--,j++){
        B[j] = arr->A[i];
    }
    for(i = 0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 10);
    Insert(&arr, 4, 12);
    Delete(&arr,2);
    Display(arr);
    cout<<"Element searched is at index: "<<linearSearch(&arr,10)<<endl;
    cout<<"Max element -> "<<Max(arr)<<endl;
    cout<<"Min element -> "<<Min(arr)<<endl;
    cout<<"Min element -> "<<Min(arr)<<endl;
    cout<<"Sum -> "<<Sum(arr)<<endl;
    cout<<"Average -> "<<Average(arr)<<endl;

    cout<<"Element-> "<<Get(arr,2)<<endl;
    Set(&arr,2,9);
    cout<<"Element after set -> "<<Get(arr,2)<<endl;

    Display(arr);
    cout<<"\nElement searched is at index: "<<binarySearch(&arr,9)<<endl;
    Reverse(&arr);
    // Reverse2(&arr);
    // cout<<"After reversing ";
    // Display(arr);
    Display(arr);
    return 0;
}