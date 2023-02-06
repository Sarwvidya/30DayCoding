class Solution {
public:
    int fs(vector<int>& nums, int n, int k){
        int low = 0, high = n-1;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(k == nums[mid]){
                res = mid;
                high = mid-1;
            }
            else if(k < nums[mid]){
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
    
    int bs(vector<int>& nums, int n, int k){
        int low = 0, high = n-1;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(k == nums[mid]){
                res = mid;
                low = mid+1;
            }
            else if(k < nums[mid]){
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = fs(nums, nums.size(), target);
        int b = bs(nums, nums.size(), target);
        
        return {a, b};
    }
};