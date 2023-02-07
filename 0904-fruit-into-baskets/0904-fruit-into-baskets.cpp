class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> b(2, 0);
        int type1 = -1, type2 = -1, ans = 0;
        for(int i = 0; i<fruits.size(); i++){
            if(type1 == -1 || fruits[i] == type1){
                type1 = fruits[i];
                b[0]++;
            }
            else if(type2 == -1 || fruits[i] == type2){
                type2 = fruits[i];
                b[1]++;
            }
            else{
                ans = max(ans, b[0]+b[1]);
                int prev = i-1;
                while(prev >=0 && fruits[prev] == fruits[i-1]){
                    prev--;
                }
                type1 = fruits[i-1], type2 = fruits[i];
                b[0] = i-prev-1;
                b[1] = 1;
            }
        }
        ans = max(ans, b[0]+b[1]);
        return ans;
    }
};