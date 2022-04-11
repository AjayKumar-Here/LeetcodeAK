class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        
        for(auto x:s)
        {
            if( ( x =='(' ) || (x == '{') || (x=='['))
            {
                st.push(x);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                
                char c=st.top();
                
                st.pop();
                
                if( ( x == ')' && c == '(' )  || ( x == '}' && c == '{' ) || ( x == ']' && c == '[' ) ) continue;
                else return false;
            }
        }
        
        return st.empty();
    }
};