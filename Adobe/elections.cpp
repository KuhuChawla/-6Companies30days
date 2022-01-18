vector<string> winner(string arr[],int n)
    {
        map<string,int>mp;
        int num = 0;
        string s;
        vector<string> ans;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto i: mp){
            if(i.second>num){
                num = i.second;
                s = i.first;
            }
        }
        ans.push_back(s);
        ans.push_back(to_string(num));
        return ans;
    }