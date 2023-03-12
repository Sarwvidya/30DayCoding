/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    void dfs(TreeNode* org, TreeNode* copy, TreeNode* target, TreeNode* &ans){
        if(!org){
            return;
        }
        if(org == target){
            ans = copy;
        }
        
        dfs(org->left, copy->left, target, ans);
        dfs(org->right, copy->right, target, ans);
        
        return;
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};