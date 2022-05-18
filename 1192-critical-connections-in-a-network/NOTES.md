//check just for a single back-edge
else if(child != parent[node])
//check and update if the ancestor was discovered before the earliest connected node to our current node
low[node] = min(low[node],disc[child]);
}
}
public:
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
adjList.resize(n);
disc.resize(n,-1);
low.resize(n,-1);
parent.resize(n,-1);
time = 0;
//build undirected graph
for(auto& conn : connections)
{
adjList[conn[1]].push_back(conn[0]);
adjList[conn[0]].push_back(conn[1]);
}
​
for(int i = 0; i < n; ++i)
if(disc[i] == -1)
DFSHelper(i);
return bridges;
}
};