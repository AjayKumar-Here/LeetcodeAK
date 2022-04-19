class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans;
        
        int n=temperatures.size();
        
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            int res=1;
            while(!st.empty() && st.top().first <=  temperatures[i])
            {
                res+=st.top().second;
                st.pop();
            }
            
            if(!st.empty())
            {
                st.push({temperatures[i],res});
                ans.push_back(res);
                
            }
            else
            {
                st.push({temperatures[i],0});
                ans.push_back(0);
            }
        
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};