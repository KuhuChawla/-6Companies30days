int indexLeft(MountainArray &mountainArr,int l,int r,int target){
        while(l<=r){
            int mid = (l+r)/2;
            int element  = mountainArr.get(mid);
            if(element == target){
                return mid;
            }
            else if (element>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
    int indexRight(MountainArray &mountainArr,int l,int r,int target){
        while(l<=r){
            int mid = (l+r)/2;
            int element  = mountainArr.get(mid);
            if(element == target){
                return mid;
            }
            else if (element>target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak;
        int l = 0;
        int r = n-1;
        while(l<=r){
            int left = INT_MIN;
            int right = INT_MIN;
            int mid = (l+r)/2;
            int m = mountainArr.get(mid);
            if((mid-1)>=0){
                left = mountainArr.get(mid-1);
            }
            if((mid+1)<=(n-1)){
                right = mountainArr.get(mid+1);
            }
            if(left<m && m>right){
                peak = mid;
                break;
            }
            else if (left<m && right>m){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        int index1 = indexLeft(mountainArr,0,peak,target);
        int index2 = indexRight(mountainArr,peak+1,n-1,target);
        if(index1!=-1 && index2!=-1){
            return index1;
        }
        else if(index1==-1){
            return index2;
        }
        return index1;
    }