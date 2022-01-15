string findOrder(string dict[], int N, int K) {
        vector<int> h[K];
        for(int i=0;i<N-1;i++){
            int minlen = min(dict[i].size(),dict[i+1].size());
            for(int j =0;j<minlen;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    h[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;  
                }
            }
        }
        vector<int>number(K,0);
        for(int i =0;i<K;i++){
            for(auto e:h[i]){
                number[e]++;
            }
        }
        queue<int>q;
        for(int i =0;i<K;i++){
            if(number[i]==0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=(node + 'a');
            for(auto x: h[node]){
                number[x]--;
                if(number[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==K){
            return ans;
        }
        return "";
    }