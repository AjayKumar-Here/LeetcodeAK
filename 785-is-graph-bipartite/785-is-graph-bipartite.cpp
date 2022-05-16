class Solution {
public:
    
    bool bfs(vector<int> adj[],vector<int> &color,int src)
    {
        queue<int> q;
        q.push(src);
        
        color[src]=true;
        
        while(!q.empty())
        {
            int u=q.front();
            
            q.pop();
            
            for(int v:adj[u])
            {
                if(color[v]==-1)
                {
                     color[v]=!color[u];
                     q.push(v);
                }
                else if(color[v]==color[u])
                {
                    return true;
                }
                
            }
            
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v=graph.size();
        
        vector<int> adj[v];
        
        vector<int> color(v,-1);
        
        for(int i=0;i<v;i++)
        {
            for(int u:graph[i])
            {
                adj[u].push_back(i);
                adj[i].push_back(u);
            }
        }
        
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(adj,color,i)) return false;
            }
        }
        
        return true;
        
        
        
    }
};