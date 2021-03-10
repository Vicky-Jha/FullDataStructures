#include <bits/stdc++.h>
#include <assert.h>
#define lli long long int
#define mod 1000000007
using namespace std;
void maxHeap(int arr[], int n)  {
    for (int i = 1; i <= n; ++i){
        int parent = i/2;
        int tempI = i;
        while(parent){
            if(arr[parent-1] < arr[tempI-1])
                swap(arr[parent-1], arr[tempI-1]);
            else break;
            tempI = parent;
            parent = parent/2;
        }
    }
}
void heapSort(int arr[], int n)
{
  int swapPos = n - 1;
  for(int i = 0; i < n - 1; ++i){
    swap(arr[0], arr[swapPos]);
    swapPos--;
    int parent = 1;
      while(1){
        int child1 = 0;
        if(2*parent - 1 < n && 2*parent - 1 <= swapPos) child1 = 2*parent - 1;
        int child2 = 0;
        if(2*parent < n && 2*parent <= swapPos) child2 = 2*parent;
        if(child1 && child2){
          if(arr[child1] > arr[child2]){
            if(arr[parent-1] < arr[child1]){
                swap(arr[parent-1], arr[child1]);
                parent = child1 + 1;
              }else if(arr[parent-1] == arr[child1]){
                  break;
                }else{
                    break;
                }
          }else{
                swap(arr[parent-1], arr[child2]);
                parent = child2 + 1;
            }
        }
        else if(child1 && !child2){
            if(arr[child1] > arr[parent-1]){
                swap(arr[child1], arr[parent-1]);
                parent = child1 + 1;
            }else {
                break;
            }
        }else if(!child1 && child2){
            if(arr[child2] > arr[parent-1]){
                swap(arr[child1], arr[parent-1]);
                parent = child2 + 1;
            }else {
                break;
            }
        }else {
            break;
        }
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int arr[] = {40, 20, 30, 43, 18, 19, 23};
    maxHeap(arr, 7);
    heapSort(arr, 7);
    for(int i = 0; i < 7; ++i) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
