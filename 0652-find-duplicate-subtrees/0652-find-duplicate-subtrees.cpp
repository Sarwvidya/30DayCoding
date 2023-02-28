/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> freq;
        vector<TreeNode*> result;
        helper(root, freq, result);
        return result;
    }
    private:
    
    string helper(TreeNode* node, unordered_map<string, int>& freq, vector<TreeNode*>& result){
        if(!node){
            return "#";
        }
        
        string leftId = helper(node->left, freq, result);
        string rightId = helper(node->right, freq, result);
        string identifier = to_string(node->val)+","+leftId+","+rightId;
        freq[identifier]++;
        
        if(freq[identifier] == 2){
            result.push_back(node);
        }        
        
        return identifier;
    }
};