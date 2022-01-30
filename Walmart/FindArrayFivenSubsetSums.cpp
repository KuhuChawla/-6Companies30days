vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(),sums.end());
        vector<int> ans;
        while(n--){
            int difference = sums[1] - sums[0];
            unordered_map<int,int> mp;
            vector<int> a1,a2;
            bool flag = false;
            for (auto& x: sums){
                if(!mp[x]){
                    a1.push_back(x);
                    mp[x+difference]++;
                    if(x==0){
                        flag = true;
                    }
                }
                else{
                    a2.push_back(x);
                    mp[x]--;
                }
            }
            if(flag){
                ans.push_back(difference);
                sums = a1;
            }
            else{
                ans.push_back(-difference);
                sums= a2;
            }
        }
        return ans;
    }