class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack <int> st;
        
        map<int,int> mp;
        
        vector<int> res(nums1.size(),-1);
        
        
        for(auto x:nums2)
        {
            while(!st.empty() && x > st.top())
            {
                mp[st.top()]=x;
                st.pop();
            }
            
            st.push(x);
        }
        for(int i=0;i<nums1.size();i++)
        {
            int x=nums1[i];
            if(mp.find(x)!=mp.end()) res[i]=mp[x];
        }
        
 
        return res;
    }
};