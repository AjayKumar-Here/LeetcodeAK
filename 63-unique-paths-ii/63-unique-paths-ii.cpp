class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,int m,int n)
    {
        vector<int> pre(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            
            for(int j=0;j<n;j++)
            {
                if( i > 0 && j > 0 && obstacleGrid[i][j]==1 ||  i >= 0 && j > 0 && obstacleGrid[i][j]==1 || i > 0 && j >= 0 && obstacleGrid[i][j]==1 )
                {
                     temp[j]=0;
                     continue;
                }
                
                if(i==0 && j==0)
                {
                    temp[j]=1;
                    continue;
                }
            
                int up=0,left=0;
                
                if(i > 0) up=pre[j];
                if(j > 0) left=temp[j-1];
                
                temp[j]=up+left;
            }
            pre=temp;
        }
        
        return pre[n-1];
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        
        int m=obstacleGrid.size();
        
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1) return 0;
        
        if(m==1) return !obstacleGrid[m-1][n-1];
        
        return paths(obstacleGrid,m,n);
    }
};