//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
      vis[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      
      for(int r = -1; r <=1; r++){
          for(int c = -1; c <=1; c++){
              int nrow = row + r;
              int ncol = col + c;
              
              if(nrow >=0 && nrow < n && ncol >=0 && ncol < m 
              && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                  dfs(nrow, ncol, vis, grid);
              }
          }
      }
  }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count= 0;
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    count++;
                    dfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends