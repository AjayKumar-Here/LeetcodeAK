class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc,int prevC,int newColor)
    {
        // Base cases
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size())
            return;
        if (image[sr][sc] != prevC)
            return;
        if (image[sr][sc] == newColor)
            return;
        
        image[sr][sc]=newColor;
        
        
        fill(image,sr-1,sc,prevC,newColor);
        fill(image,sr,sc+1,prevC,newColor);
        fill(image,sr+1,sc,prevC,newColor);
        fill(image,sr,sc-1,prevC,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int prevC=image[sr][sc];
        fill(image,sr,sc,prevC,newColor);
        return image;
    }
};