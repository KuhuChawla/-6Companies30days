int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i =0 ;i<points.size();i++){
            unordered_map<int,int>mp;
            for(int j =0;j<points.size();j++){
                mp[(points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1])]++;
            }
            for(auto i:mp){
            if(i.second>1){
                ans+=(i.second*(i.second-1));
                }
            }
        }
        return ans;                                         
    }