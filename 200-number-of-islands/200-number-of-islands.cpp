class Solution 
{
public:
    
    int dr[4]={1, 0, -1, 0};
    int dc[4]={0, -1, 0, 1};
    
    bool valid_index(int i, int j, vector<vector<char>>& grid) 
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        return true;
    }
    
    void bfs(vector<vector<char>>&grid,int i,int j)
    {
        grid[i][j]='0';
        
        queue<pair<int,int>> q;
        
        q.push({i,j});
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            
            q.pop();
           
       
            for(int k=0;k<4;k++)
            {
                int ri=dr[k]+i;
                int ci=dc[k]+j;
                if(!valid_index(ri,ci,grid))
                {
                    continue;
                }
                
                if(grid[ri][ci]=='1')
                {
                    q.push({ri,ci});
                    grid[ri][ci]='0';
                }    
            }  
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        
        int count=0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,i,j);
                }
            }
            
            
        }
        
        return count;
    }
};