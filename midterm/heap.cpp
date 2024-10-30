#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify_down(vector<long long>&arr,long long n,long long i){
    long long smallest = i;
    long long left = 2*i+1;
    long long right = 2*i+2;

    if(left<n && arr[left]<arr[smallest]){
        smallest = left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest = right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify_down(arr,n,smallest);
    }
}

void heapify_up(vector<long long>& a, long long v){
    while (v > 0 && a[(v-1) / 2] > a[v]){
        swap(a[v],a[(v-1) / 2]);
        v = (v-1) / 2;
    }
}   

void push(vector<long long>& a, long long x){
    a.push_back(x);
    heapify_up(a, a.size() - 1);
}


long long pop(vector<long long>& a){
    long long root = a[0];
    a[0] = a.back();
    a.pop_back();
    if (!a.empty()) {
        heapify_down(a, a.size(), 0);
    }
    return root;
}

long long mixtures(vector<long long>& arr,long long m) {
    vector<long long> heap;
    long long count = 0;
    for (long long val : arr) {
        push(heap, val);
    }
    while(heap.size()>1 && heap[0]<m){
        long long least = pop(heap);
        long long second_least = pop(heap);
        long long mix = least + 2*second_least;
        push(heap,mix);
        count++;
    }
    if(heap[0]>=m){
        return count;
    }
    else{
        return -1;
    }
}


int main(){
    long long n;cin>>n;
    long long m;cin>>m;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    cout<<mixtures(arr,m);
}