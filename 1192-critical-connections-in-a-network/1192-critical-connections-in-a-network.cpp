class Solution {
public:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> Map;
    
     void dfs(int curr, int prev) 
     {
        disc[curr] = low[curr] = time++;
         
        for (int next : Map[curr]) 
        {
            if (disc[next] == 0) 
            {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } 
            else if (next != prev) low[curr] = min(low[curr], disc[next]);
            
            if (low[next] > disc[curr]) ans.push_back({curr, next});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        disc = vector<int>(n);
        
        low = vector<int>(n);
        
        for (auto con : connections) 
        {
            Map[con[0]].push_back(con[1]);
            Map[con[1]].push_back(con[0]);
        }
        
        dfs(0, -1);
        
        return ans;
    }
};