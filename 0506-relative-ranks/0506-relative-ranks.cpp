class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mp;
        vector<string> v(score.size(), "");
        
        for(int i=0; i<score.size(); i++){
            mp[score[i]] = i;
        }
        
        sort(score.begin(), score.end(), greater<int>());
        for(int i = 0; i<score.size(); i++){
            if(i+1==1){
                v[mp[score[i]]] = "Gold Medal";
            }
            else if(i+1==2){
                v[mp[score[i]]] = "Silver Medal";
            }
            else if(i+1==3){
                v[mp[score[i]]] = "Bronze Medal";
            }
            else
                v[mp[score[i]]] = to_string(i+1);
        }
        return v;
    }
};