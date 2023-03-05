class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        vector<int> temp, ans;
        int n=num;
        
        while(n){
            int r = n%10;
            temp.push_back(r);
            if(r%2==0) even.push(r);
            else odd.push(r);
            n /=10;
        }
        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]%2==0){
                ans.push_back(even.top());
                even.pop();
            }
            else{
                ans.push_back(odd.top());
                odd.pop();
            }
        }
        int great =0;
        for(int i = 0; i<ans.size(); i++){
            great = (great*10)+ans[i];
        }
        return great;
    }
};