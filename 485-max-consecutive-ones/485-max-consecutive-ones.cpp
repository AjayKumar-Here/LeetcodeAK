class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res=0,count=0;
        
        for(int x:nums)
        {
            if(x==1)
            {
                count++;
                res=max(res,count);
            }
            else
            {
                count=0;
            }
        }
        
        return res;
    }
};