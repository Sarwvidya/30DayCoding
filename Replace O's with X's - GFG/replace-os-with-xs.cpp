//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[], int n, int m){
        vis[r][c] = 1;
        
        for(int i=0; i<4; i++){
            int row = r + delrow[i];
            int col = c + delcol[i];
            if(row >=0 && row < n && col >=0 && col<m && !vis[row][col] && mat[row][col] == 'O'){
                dfs(row, col, vis, mat, delrow, delcol, n, m);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        for(int i=0; i<m; i++){
            //first row
            if(!vis[0][i] && mat[0][i] == 'O'){
                dfs(0, i, vis, mat, delrow, delcol, n, m);
            }
            //last row
            if(!vis[n-1][i] && mat[n-1][i] == 'O'){
                dfs(n-1, i, vis, mat, delrow, delcol, n, m);
            }
        }
        for(int j=0; j<n; j++){
            //first row
            if(!vis[j][0] && mat[j][0] == 'O'){
                dfs(j, 0, vis, mat, delrow, delcol, n, m);
            }
            //last row
            if(!vis[j][m-1] && mat[j][m-1] == 'O'){
                dfs(j, m-1, vis, mat, delrow, delcol, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends