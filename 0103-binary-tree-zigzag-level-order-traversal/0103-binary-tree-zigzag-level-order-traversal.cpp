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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        vector<int> sub;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            sub.clear();
            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level%2 == 0) sub.push_back(temp->val);
                else sub.insert(sub.begin(), temp->val);
                
                if(temp->left != nullptr)  q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);                
            }
            level++;
            res.push_back(sub);
        }
        return res;
    }
    
};