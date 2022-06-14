class Solution {
public:
     int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
         
        int m = matrix[0].size();
        
        vector<int> dp(matrix[0]);
        
        vector<int>cur(m,0);
        
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                int dr=1e9,dl=1e9;
                
                if(j-1 >= 0)  dl=matrix[i][j] + dp[j-1];
                
                if(j+1 < m)   dr=matrix[i][j] + dp[j+1]; 
                
                int d=matrix[i][j] + dp[j];
                
                cur[j]=min(d,min(dl,dr));
                  
                }
                
                dp=cur;
            }
        
            int mini=dp[0];
    
            for(int x=1;x<m;x++)
            {
                mini=min(mini,dp[x]);
            }
    
            return mini;
    }
};