class Solution {
public:
    int minpath(vector<vector<int>> &dp, vector<vector<int>> &triangle,int i,int j,int n)
    {
        if(n-1 == i) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
         int down=triangle[i][j] + minpath(dp,triangle,i+1,j,n);
         int diag=triangle[i][j] + minpath(dp,triangle,i+1,j+1,n);
        
        
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        
        if(n==1) return triangle[0][0];
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return minpath(dp,triangle,0,0,n);
    }
};