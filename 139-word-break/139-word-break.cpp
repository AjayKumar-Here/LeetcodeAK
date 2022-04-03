class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        set <string> dic(wordDict.begin(),wordDict.end());
        
        if(dic.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    if(dic.find(s.substr(j,i-j))!=dic.end())
                    {
                        dp[i]=true;
                        break;
                    } 
                }
               
            }
        }
        
        return dp[s.size()];
    }

};