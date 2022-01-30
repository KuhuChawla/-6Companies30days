int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++){
             p[i]={efficiency[i],speed[i]}; 
        }
        sort(rbegin(p),rend(p));
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans = 0;
        long long sum = 0;
        for(auto i: p){
            sum+=i.second;
            pq.push(i.second);
            
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ans = max(ans,sum*(i.first));
        }
        return ans % (int)(1e9+7);
    }