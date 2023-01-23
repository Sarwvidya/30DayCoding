class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/")
            {
                long long opt1 = st.top();
                st.pop();
                long long opt2 = st.top();
                st.pop();         
                if(s == "+") st.push(opt2 + opt1);
                else if(s == "-") st.push(opt2 - opt1);
                else if(s == "*") st.push(opt2 * opt1);
                else st.push(opt2 / opt1);
            }else{
                st.push((int)stoi(s));
            }
        }
        return st.top();
    }
};