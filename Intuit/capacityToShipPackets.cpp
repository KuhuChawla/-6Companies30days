bool isPossible(vector<int> weights,int days,int mid){
        int dayCount = 1;
        int wt = 0;
        for(int i = 0;i<weights.size();i++){
            if(wt+weights[i]<=mid){
                wt+=weights[i];
            }
            else{
                dayCount++;
                if(dayCount>days || weights[i]>mid){
                    return false;
                }
                wt = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i =0;i<weights.size();i++){
            sum+=weights[i];
        }
        int start = 0;
        int end = sum;
        int ans = -1;
        while(start<=end){
            int mid = start+ (end-start)/2;
            if(isPossible(weights,days,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }