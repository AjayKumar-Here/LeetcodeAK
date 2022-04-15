❌ Solution - I (Brute-Force)
​
The most brute force way of solving this problem would be to simply consider each and every possible rectangle and consider the maximal out of the rectangles which only consists of 1 in them
​
class Solution {
public:
int maximalRectangle(vector<vector<char>>& M) {
if(!size(M)) return 0;
int ans = 0, m = size(M), n = size(M[0]);
for(int start_i = 0; start_i < m; start_i++)
for(int start_j = 0; start_j < n; start_j++)
for(int end_i = start_i; end_i < m; end_i++)
for(int end_j = start_j; end_j < n; end_j++) {
bool allOnes = true;
for(int i = start_i; i <= end_i && allOnes; i++)
for(int j = start_j; j <= end_j && allOnes; j++)
if(M[i][j] != '1') allOnes = false;
ans = max(ans, allOnes * (end_i - start_i + 1) * (end_j - start_j + 1));
}
​
return ans;
}
};
Time Complexity : O((MN)3)
Space Complexity : O(1)
​
✔️ Solution - II (Optimized Brute-Force)
​
Instead of forming every rectangle, then checking validity of rectangle, we can optimize the brute-force by only considering valid rectangles. For this, we can start from every cell and consider valid rectangle starting from that cell.
​
Let the current cell be at (i, j).
We first consider ith row and find maximum column length of 1s starting from M[i][j].
Then move to i+1th row and find maximum column length of 1s starting from M[i+1][j]. Take minimum of all lengths and find the area and keep updating max area.
Continue similar process till you reach last row and then repeat the process for all other cells as well.
Finally return maximum area found from all valid rectangles.
The below image illustrates the process for first two cells of the grid -
​
​
​
class Solution {
public:
int maximalRectangle(vector<vector<char>>& M) {