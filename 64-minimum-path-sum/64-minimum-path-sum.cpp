class Solution {
public:
    int minsum(vector<vector<int>>& grid,int n,int m)
    {
        
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                {
                    temp[j]=grid[i][j];
                    continue;
                }
                
                int up=1e9,left=1e9;
                
                if(i > 0) up=grid[i][j] + prev[j];
        
                if(j > 0) left=grid[i][j] + temp[j-1];
                
                
                temp[j]=min(up,left);
                
            }
            
            prev=temp;
        }
        return prev[m-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m= grid[0].size();
        
        return minsum(grid,n,m);
    }
};