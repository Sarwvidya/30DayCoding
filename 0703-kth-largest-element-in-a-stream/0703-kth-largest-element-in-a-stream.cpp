class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        int x= min(k,(int)nums.size());
        for(int i=0; i<x; i++){
            q.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(q.size()<size){
            q.push(val);
            return q.top();
        }
        if(val > q.top()){
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};
