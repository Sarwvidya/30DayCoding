class Solution {
public:
    void solve(int k, int n, vector<int> temp, vector<vector<int>>& ans, int s){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(n==0) return;
        if(k==0) return;
        
        for(int i = s; i <=9; i++){
            temp.push_back(i);
            solve(k-1, n-i, temp, ans, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k>=n || n==1){
            return ans;
        }
        
        vector<int> temp;
        solve(k, n, temp, ans, 1);
        return ans;
        
    }
};