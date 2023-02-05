class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        vector<int> ans;
        int window = p.size();
        int length = s.size();
        
        if(length < window){
            return ans;
        }
        int left = 0, right = 0;
        while(right < window){
            phash[p[right] - 'a'] +=1;
            hash[s[right] - 'a'] +=1;
            right ++;
        }
        right -=1;
        while(right<length){
            if(phash == hash){
                ans.push_back(left);
            }
            right +=1;
            if(right != length){
                hash[s[right] - 'a'] +=1;
            }
            hash[s[left] - 'a'] -=1;
            left++;
        }
        return ans;
    }
};