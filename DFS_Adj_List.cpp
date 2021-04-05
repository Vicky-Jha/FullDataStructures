#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;
bitset<100001> visited;
vector< vector< int >> adj;
void dfs(int v)
{
	visited[v] = 1;
	cout<<v<<" ";
	for ( int c : adj[v] )
		if(!visited[c])
			dfs(c);
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    int edge;
    cout<<"Enter number of Edges\n";
    cin>>edge;
    
    int x,y;
    adj.resize(n);
    
    for ( int i = 0; i < edge; ++ i )
    {
		cin>>x>>y;
		adj[x].push_back(y);
	}

	dfs(0); // dfs starting from vertex 0


    return 0;
}
//0 1
//0 2
//1 2
//2 0
//2 3 
//3 3

//0 -> 1 -> 2
//1 -> 2
//2 -> 0 -> 3
//3 -> 3

//output
//0 1 2 3
