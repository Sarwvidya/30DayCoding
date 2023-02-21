class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        
        int min = n+1, res =-1;
        for(auto i: mp){
            if(min > i.second){
                res = i.first;
                min=i.second;
            }
        }
        return res;
    }
};