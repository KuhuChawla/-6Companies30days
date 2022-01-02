//Given a pattern containing only I's and D's. I for increasing and D for decreasing.Devise an algorithm to print the minimum number following that pattern.

class Solution{
    public:
        string printMinNumberForPattern(string S){
            string ans = "";
            stack<int> st;
            for(int i =0;i<=S.length();i++){
                st.push(i+1);
                if(S.length()==i|| S[i] == 'I'){
                    while(!st.empty()){
                    ans+= to_string(st.top());
                    st.pop();  
                    }
                    
                }
            }
            return ans;
    }
};
