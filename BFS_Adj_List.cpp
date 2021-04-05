#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void bfs(vector<int> adj[], bool visited[], vector<int>& res, int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        if(!visited[v]){
        res.push_back(v);
        visited[v] = 1;
        for(int i = 0; i < adj[v].size(); ++i){
            q.push(adj[v][i]);
        }
        }
    }
}
    vector<int>bfsOfGraph(int V, vector<int> adj[]){
        bool visited[V];
        memset(visited, false, sizeof(visited));
        vector<int> res;
        bfs(adj, visited, res, 0);
        return res;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 
