

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for(int i =0;i<n;i++){
            if(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }
            while(dq.size()>0 && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-k>=-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }