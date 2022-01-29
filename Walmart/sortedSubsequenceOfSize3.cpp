vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> ans;
        if(N<3){
            return ans;
        }
        int prev = arr[0];
        int curr = -1;
        int next = -1;
        for(int i=0;i<N;i++){
            if(curr!=-1 && next!=-1){
                break;
            }
            if(arr[i]<prev && curr == -1){
                prev = arr[i];
            }
            else if(arr[i]>prev && curr == -1){
                curr = arr[i];
            }
            else if(arr[i]>prev && arr[i]<curr){
                curr = arr[i];
            }
            else if(arr[i]>curr && curr!=-1 && next == -1){
                next = arr[i];
            }
        }
        if(curr!=-1 && next!=-1){
            ans.push_back(prev);
            ans.push_back(curr);
            ans.push_back(next);
        }
        return ans;
    }