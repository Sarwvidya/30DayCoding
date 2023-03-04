class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> ans, temp;
        
        for(int i = 0; i<nums.size(); i++){
            q.push({nums[i], i});
        }
        
        while(k--){
            auto a = q.top();
            q.pop();
            temp.push_back(a.second);
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i<temp.size(); i++){
            ans.push_back(nums[temp[i]]);
        }
        
        return ans;
    }
};