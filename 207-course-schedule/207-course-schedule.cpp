class Solution 
{
public:
    
    bool dfs(vector<int> adj[],vector<int>&visited,int s)
    {
        if(visited[s]==1)
        {
            return true;
        }
        
        if(visited[s]==0)
        {
            visited[s]=1;
            for(int x:adj[s])
            {
                if(dfs(adj,visited,x)) return true;
            }
               
        }
        
        visited[s]=2;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        
        vector<int> visited(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(adj,visited,i))
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};