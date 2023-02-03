class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        
        stringstream answer;
        int n = s.length();
        int diff = 2*(numRows-1);
        int diagdiff = diff;
        int secondindex;
        int index;
        
        for(int i = 0; i<numRows; i++){
            index = i;
            while(index<n){
                answer<<s[index];
                if(i!=0 && i!=numRows-1){
                    diagdiff = diff-(2*i);
                    secondindex = index + diagdiff;
                    if(secondindex <n){
                        answer<<s[secondindex];
                    }
                }
                index += diff;
            }
        }
        return answer.str();
    }
};