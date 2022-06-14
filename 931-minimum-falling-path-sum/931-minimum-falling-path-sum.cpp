class Solution {
public:
    int minsum(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int n)
    {
        
        
        if( (j < 0) || (j > n-1) ) return 1e9;
        
        if( i==n-1 ) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int dl=matrix[i][j] + minsum(matrix,dp,i+1,j-1,n);
        int d=matrix[i][j] + minsum(matrix,dp,i+1,j,n);
        int dr=matrix[i][j] + minsum(matrix,dp,i+1,j+1,n);
        
        return dp[i][j]=min(d,min(dl,dr));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int mi=INT_MAX;
        
        for(int i=0;i<matrix[0].size();i++)
        {
               mi=min(mi,minsum(matrix,dp,0,i,n));
        }
        
        return mi;
    }
};