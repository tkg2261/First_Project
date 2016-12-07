#include <iostream>

using namespace std;

int INT_MAX = 500;

void swap_keys(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MaxHeap{

private:
    int capacity;
    int* arr;
    int heapsize;
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    int parent(int i){
        return ((i-1)/2);
    }
    void BuildMaxHeap(){
        int i=heapsize/2 - 1;
        for(i;i>=0;i--){
            max_heapify(i);
        }
    }
public:
    MaxHeap(int capacity);
    void insert_key(int x);// inserts key with value x
    void delete_key(int i);// deletes key at index i
    void change_key(int i,int x);// changes value of key at index i to x
    int get_max();// returns key with max value
    int extract_max();// extracts key with max value and returns it
    void max_heapify(int i);// clears violation of max heap property at index i
    void printheap();
    void Heapsort();
};

MaxHeap :: MaxHeap(int cap){
    heapsize = 0;
    capacity = cap;
    arr = new int[capacity];
}

void MaxHeap :: insert_key(int x){
    heapsize++;
    int i = heapsize-1;
    arr[i] = x;
    while(i!=0 && arr[parent(i)]<arr[i]){
        swap_keys(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap :: delete_key(int i){
    change_key(i,INT_MAX);
    extract_max();
}

void MaxHeap :: change_key(int i,int x){
    if(arr[i]>x){
        arr[i] = x;
        max_heapify(i);
    }
    else if (arr[i]<x){
        arr[i] = x;
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap_keys(&arr[i],&arr[parent(i)]);
            i = parent(i);
        }
    }
}

int MaxHeap :: get_max(){
    return arr[0];
}

int MaxHeap :: extract_max(){
    int temp = arr[0];
    arr[0]=arr[heapsize-1];
    heapsize--;
    max_heapify(0);
    return temp;
}

void MaxHeap :: max_heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<heapsize && arr[l]>arr[i])
        largest = l;
    if(r<heapsize && arr[r]>arr[largest])
        largest = r;
    if(i!=largest){
        swap_keys(&arr[largest],&arr[i]);
        max_heapify(largest);
    }
}

void MaxHeap :: printheap(){
    int i=0;
    while(i<heapsize){
        cout<<arr[i]<<" ";
        i++;
    }
}

void MaxHeap :: Heapsort(){
    BuildMaxHeap();
    int temp = heapsize;
    while(heapsize>0){
        swap_keys(&arr[0],&arr[heapsize-1]);
        heapsize--;
        max_heapify(0);
    }
    heapsize = temp;
}


int main()
{
    MaxHeap h(11);
    h.insert_key(3);
    h.insert_key(2);
    h.delete_key(1);
    h.insert_key(15);
    h.insert_key(5);
    h.insert_key(4);
    h.insert_key(45);
//    h.extract_max();
//    cout << h.get_max()<< " ";
    h.Heapsort();
//    cout << h.get_max();
    h.printheap();
    return 0;
}
