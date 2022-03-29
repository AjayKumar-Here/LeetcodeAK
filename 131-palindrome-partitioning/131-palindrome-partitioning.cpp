class Solution {
public:
    
    bool palindrome(string str,int s,int e)
    {
        while(s<=e)
        {
            if(str[s]!=str[e])
            {
                return false;
            }
            
            s++;
            e--;
        }
        
        return true;
    }
    
    void partition(int ind,string &s,vector<vector<string >> &ans,vector<string > &res)
    {
        if(ind==s.length())
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=ind;i<s.length();i++)
        {
            if(palindrome(s,ind,i))
            {
                res.push_back(s.substr(ind, i - ind + 1));
                partition(i+1,s,ans,res);
                res.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string >> ans;
        vector<string > res;
        
        partition(0,s,ans,res);
        
        return ans;
    }
};