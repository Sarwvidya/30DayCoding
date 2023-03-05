class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i=0; i<stones.size(); i++){
            q.push(stones[i]);
        }
        if(stones.size()==1){
            return stones[0];
        }
        int weight=0;
        while(q.size() !=1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            weight = a-b;
            q.push(weight);
        }
        return weight;
    }
};