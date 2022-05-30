class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int p1=nums[0];
        int p2=0;
        
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            if(i > 1) take+=p2;
            
            int pick=0+p1;
            
            int cur=max(take,pick);
            
            p2=p1;
            p1=cur;
        }
        
        return p1;
    }
};