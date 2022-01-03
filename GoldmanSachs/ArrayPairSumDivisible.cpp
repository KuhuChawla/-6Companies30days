//Array Pair Sum Divisibility Problem

bool canPair(vector<int> nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            mp[nums[i]%k]++;
        }
        for(int i = 0;i<n;i++){
            int r = nums[i]%k;
            if(r==0){
                if(mp[0]&1){
                    return 0;
                }
            }
            else if (mp[r]!=mp[k-r]){
                return 0;
            }
        }
        return 1;
    }