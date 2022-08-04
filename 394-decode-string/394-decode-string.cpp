class Solution {
public:
    string decodeString(string s) {
        int len = s.length();
        stack<char> st;
        for(auto x: s){
            if(x!=']'){
                st.push(x);
            }else{
                string temp = "";
                while(st.top()!='['){
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();   // '['
                string k = "";
                while(st.empty()==false && isdigit(st.top())){
                    k = st.top()+k;
                    st.pop();
                }
                int num = stoi(k);
                while(num>0){
                    for(auto ch: temp){
                        st.push(ch);
                    }
                    num--;
                }
            }
        } 
        
        string ans = "";
        while(st.empty()==false){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};