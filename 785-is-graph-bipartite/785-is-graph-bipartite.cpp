class Solution {
public:
    
    bool dfs(vector<int> &visited,vector<int> adj[],vector<int> &color,int u,int ans)
    {
        visited[u]=true;
        
        color[u]=ans;
        
        for(int v:adj[u])
        {
            if(!visited[v])
            {
               if(dfs(visited,adj,color,v,ans^1)) return true;
    
            }
            else if(color[v]==color[u])
            {
                return true;
            }
            
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v=graph.size();
        
        vector<int> adj[v];
        
        for(int i=0;i<v;i++)
        {
            for(int u:graph[i])
            {
                adj[u].push_back(i);
                adj[i].push_back(u);
            }
        }
        
        vector<int> color(v,-1);
        vector<int> visited(v,0);
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(dfs(visited,adj,color,i,1)) return false;
            }
        }
        
        return true;
        
        
        
    }
};