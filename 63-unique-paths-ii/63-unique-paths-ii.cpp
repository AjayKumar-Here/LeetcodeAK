class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>& dp)
    {
        if(m > 0 && n > 0 && obstacleGrid[m][n]==1) return 0;
        
        if(m > 0 && n >= 0 && obstacleGrid[m][n]==1) return 0;
        
        if(m >= 0 && n > 0 && obstacleGrid[m][n]==1) return 0;
        
        if(m==0 && n==0) return 1;
        
        if(m < 0 || n < 0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int up=paths(obstacleGrid,m,n-1,dp);
      
        int left=paths(obstacleGrid,m-1,n,dp);
        
        return dp[m][n]=up+left;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        
        int m=obstacleGrid.size();
        
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1) return 0;
        
        if(m==1) return !obstacleGrid[m-1][n-1];
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return paths(obstacleGrid,m-1,n-1,dp);
    }
};