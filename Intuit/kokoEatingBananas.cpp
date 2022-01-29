int isValid(vector<int>piles, int calhrs){
        int hours1 = 0;
            
        for (int i = 0; i<piles.size() ; i++){
            hours1+=ceil(piles[i]/(double)calhrs);
        }
        
        return hours1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int maxNumber = 0;
        for(int i=0;i<piles.size();i++){
            maxNumber = max(maxNumber,piles[i]);
        }
        if(piles.size()==h){
            return maxNumber;
        }
        int start = 1;
        int end = maxNumber;
        while(start<=end){
            int mid = start+ (end-start)/2;
            int valid = isValid(piles,mid);
            if(valid<=h){
                ans = mid;
                end = mid-1;
            }
            else if(valid>h){
                start = mid+1;
            }
        }
        return ans;
        
    }