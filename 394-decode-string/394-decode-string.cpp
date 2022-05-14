class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == ']'){
            
            // forming string
            string temp = "";
            while(st.top() != '['){
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();
            
            // forming number
            string num = "";
            while(!st.empty() && isdigit(st.top())){
                num = st.top() + num;
                st.pop();
            }
            int n = stoi(num);
            
            // concatinate n times
            string str = temp;
            n--;
            while(n--){
                temp = temp + str;
            }
            
            // again push it in stack
            for(int j=0;j<temp.size();j++){
                st.push(temp[j]);
            }
        }
        else{
            st.push(s[i]);
        }
    }
    
    // finally return ans.
    string ans = "";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
    }
};