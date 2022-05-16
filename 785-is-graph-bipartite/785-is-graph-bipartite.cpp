class Solution {
public:
    
    bool bfs(vector<int> adj[],vector<int> &color,int src)
    {
        queue<pair<int,bool>> q;
        q.push({src,0});
        
        while(!q.empty())
        {
            int u=q.front().first;
            
            bool c=q.front().second;
            
            q.pop();
            
            for(int v:adj[u])
            {
                if(color[v]==-1)
                {
                     color[v]=!c;
                     q.push({v,!c});
                }
                else if(color[v]==c)
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