class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int m = s.size();
        set<string> set1;
        vector<vector<string>> ans(m);
        for(int i=0;i<n;i++){
            set1.insert(contact[i]);
        }
        for(int i=0;i<m;i++){
            for(auto it:set1){
                if(s.substr(0,i+1)==it.substr(0,i+1)){
                    ans[i].push_back(it);
                }
            }
            if(ans[i].size()==0){
                ans[i].push_back(to_string(0));
            }
        }
        return ans;
    }
};