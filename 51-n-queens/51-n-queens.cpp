class Solution {
public:
    
    void solveNQueens(vector<vector<string>> &res, vector<string> &nq, int col,int n,vector<int> lr,vector<int> &ld,vector<int> &ud){
        
        if(col==n)
        {
            res.push_back(nq);
            return;
        }
    
        
        for(int row=0;row<n;row++)
        {
            if(lr[row]==0 && ud[row+col]==0 && ld[n-1+col-row]==0)
            {
                nq[row][col]='Q';
                lr[row]=1;
                ud[row+col]=1;
                ld[n-1+col-row]=1;
                solveNQueens(res, nq, col+1, n,lr,ld,ud);
                nq[row][col]='.';
                lr[row]=0;
                ud[row+col]=0;
                ld[n-1+col-row]=0;
            }
        }
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        
        vector<string> nq(n,string(n,'.'));
        
        vector<int> lr(n,0),ld(2*n-1,0),ud(2*n-1,0);
        
        solveNQueens(res, nq, 0, n,lr,ld,ud);
        
        return res;
    }
};