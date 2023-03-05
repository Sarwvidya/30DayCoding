class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        
        int index=1;
        while(s>>word){
            if(word.find(searchWord) < 1)
                return index;
            index++;
        } 
        return -1;
    }
};