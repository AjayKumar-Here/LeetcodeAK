class Solution {
public:
    int maxSum(vector<int>&arr,int ind,int n,int k,vector<int> &dp)
    {
        if(ind==n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int maxi=INT_MIN;
        int mxsum=INT_MIN;
        int len=0;
        
        for(int i=ind;i<min(ind+k,n);i++)
        {
            len++;
            maxi=max(maxi,arr[i]);
            
            int sum=len*maxi + maxSum(arr,i+1,n,k,dp);
            
            mxsum=max(mxsum,sum);
        }
        return dp[ind]=mxsum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        vector<int> dp(n+1,-1);
        
        return maxSum(arr,0,n,k,dp);
    }
};