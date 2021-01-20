//Fenwick Tree is a linear array which contains logical values to find the cumulative sums
//Array elements are inserted using fenwick logic

#include <bits/stdc++.h>
#include <assert.h>
#define lli long long int
#define mod 1000000007
using namespace std;

void updateBit(int BIT[], int x, int size, int index)
{
	while(index <= size){
		BIT[index] += x;
		index += (index & -index);
	}
	
}
int getSum(int index, int BIT[])
{
	int sum = 0;

	while(index > 0){
		sum += BIT[index];
		index -= (index & -index);		
	}
	return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cout<<"Enter Size of array\n";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin>>arr[i];
    int BIT[n+1];

    for (int i = 0; i <= n; ++i){
		BIT[i] = 0;
	}
    for (int i = 0; i < n; ++i){
		updateBit(BIT, arr[i], n,i+1);
	}

    
    for (int i = 0; i <= n; ++i) cout<<BIT[i]<<" ";
    cout<<endl;
    
    cout<<"Enter the index to find the sum from 0 to index\n";
    int index;
    cin>>index;
    updateBit(BIT, 9, n, 3 + 1); //addding 9 to index 3
    cout<<"Sum of the elements from 0 to "<<index<<" is "<<getSum(index+1, BIT)<<endl;
    
    return 0;
    assert(false);
}
//Input
//11
//3 2 -1 6 5 4 -3 3 7 2 3
