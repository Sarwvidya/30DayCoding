class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> q;
        for(int i = 0; i<3; i++){
            q.push(amount[i]);
        }
        int count;
        while(q.top()!=0){
            int num1 = q.top();
            num1--;
            q.pop();
            int num2 = q.top();
            num2--;
            q.pop();
            q.push(num1);
            q.push(num2);
            count++;
        }
        return count;
    }
};