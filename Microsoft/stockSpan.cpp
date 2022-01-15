vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;
       st.push({price[0],1});
       vector<int>ans(n,1);
       int i =1;
       while(i<n){
           int curr = price[i];
           int c = 0;
           while(!st.empty() && st.top().first<=curr){
               c+=st.top().second;
               st.pop();
           }
           ans[i]+=c;
           st.push({curr,ans[i]});
           i++;
       }
       return ans;
    }