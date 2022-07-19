class Solution {
public:
    
    bool validParentheses(char open, char closing){
        if(closing==')' && open=='('){
            return true;
        }
        if(closing==']' && open=='['){
            return true;
        }
        if(closing=='}' && open=='{'){
            return true;
        }
        return false;
    }
    
    bool isValid(string s) {
        stack<char> OpenBrackets;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                OpenBrackets.push(s[i]);
            }else {
                if(OpenBrackets.empty()==false){
                    if(validParentheses(OpenBrackets.top(), s[i])==false)
                           return false;
                }else{
                    return false;
                }
                OpenBrackets.pop();
            }         
        }
        if(OpenBrackets.empty()==false)
            return false;
        return true;
    }
};