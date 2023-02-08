class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, curr_End = 0, curr_Farthest = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		curr_Farthest = max(curr_Farthest, i + nums[i]);
		if (i == curr_End) {
			jumps++;
			curr_End = curr_Farthest;
		}
	}
	return jumps;
    }
};