class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10, 0);
        int bull=0, cow=0;
        string hint;
        
        for(int i = 0; i< secret.size(); ++i){
            if(guess[i] == secret[i]){
                bull++;
            }else{
                if(freq[secret[i] - '0']++ < 0) cow++;
                if(freq[guess[i] - '0']-- > 0) cow++;     
            }
        }
        
        hint =  to_string(bull)+"A"+to_string(cow)+"B";
        return hint;
    }
};