class Solution {
public:
    int houserob(vector<int>& nums)
    {
        int p1=nums[0];
	    int p2=0;
	   
	   for(int i=1;i<nums.size();i++)
	   {
	       int take=nums[i];
           
	       if(i > 1)
           {
               take+=p2;
               
           }
           
	       int pick=0+p1;
	       
	       int curr=max(take,pick);
	       
	       p2=p1;
	       p1=curr;
        }
        
        return p1;
        
    }
    
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 1) return nums[0];
        
        vector<int> arr1(nums.begin(), nums.end()-1);
        vector<int> arr2(nums.begin()+1, nums.end());
        
        
        return max(houserob(arr1), houserob(arr2));
    }
};