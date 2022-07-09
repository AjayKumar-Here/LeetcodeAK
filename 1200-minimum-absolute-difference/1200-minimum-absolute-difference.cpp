class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        
        int min_dif = INT_MAX;
        
        vector<vector<int>> ans;
        
        
        for(int i=1; i<arr.size();i++)
        {
            int diff = arr[i] - arr[i-1];
            
            if(diff<min_dif)
            {
                min_dif = diff;
                ans.clear();
            }
            
            if(diff == min_dif)
            {
                ans.push_back(vector<int>{arr[i-1], arr[i]});
            }
            
        }
        return ans;
    }
};