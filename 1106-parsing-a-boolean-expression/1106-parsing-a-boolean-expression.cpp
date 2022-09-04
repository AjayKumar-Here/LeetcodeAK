class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        int n=expression.length();
        
        stack<char> st;
        
       
        
        
        for(int i=0;i<n;i++)
        {
           
            if(expression[i]==')')
            {
                bool f=false,t=false;
                
                while(st.top()=='t' || st.top()=='f')
                {
                   if(st.top()=='f')
                   {
                       f|=true;
                   }
                   else if(st.top()=='t')
                   {
                       t|=true;  
                   }
                    
                    st.pop();
                }
                
                auto op = st.top();
                st.pop();
                st.push(op == '!' ? f ? 't' : 'f' : op == '&' ? !f ? 't' : 'f' : t ? 't' : 'f');
            
            }
            else
            {
                 if(expression[i]!=',' && expression[i]!='(') st.push(expression[i]);
            }
            
           
        }
                    
         return st.top() == 't' ? true : false;
    }
};