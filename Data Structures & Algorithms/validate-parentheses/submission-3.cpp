class Solution {
public:
    bool isValid(string s) {
        //using a stack, push chars in whenever a { [ or ( is encountered.
        //pop the stack when an opposing bracket encountered, and eliminate upon discrepancy.
        //int i = 0;    USE it INSTEAD OF s[i]
        stack<char> st;
        auto it = s.begin();
        
        while( it != s.end()){

            //build stack on left parentheses
            if(*it != '}' && *it != ')' && *it != ']'){
            st.push(*it);
            it++;
            continue;
            }
            if (st.empty())
                return false;
            //compare right parentheses to stack
            if((*it == '}' || *it == ')' || *it == ']') && (
               st.top()=='{' && *it!='}'||
               st.top()=='(' && *it!=')'||
               st.top()=='[' && *it!=']'                 )
            ){
                return false;
            }
            st.pop();
            it++;
        }
        return st.empty();
    }
};
