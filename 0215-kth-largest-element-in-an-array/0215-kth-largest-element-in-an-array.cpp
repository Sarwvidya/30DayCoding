class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> p;
        
        for(auto n : nums){
            p.push(n);
            if(p.size() > k){
                p.pop();
            }
        }
        return p.top();
    }
};