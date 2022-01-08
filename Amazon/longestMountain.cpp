
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return 0;
        }
        int ans = 0;
        int count =0;
        for(int i=1;i<n;i++){
            if(arr[i] == arr[i-1]){
                count = 0;
            }
            else if(arr[i]>arr[i-1]){
                count++;
            }
            else if (count>0){
                while(i<n && arr[i]<arr[i-1]){
                    count++;
                    i++;
                }
                ans = max(ans,count+1);
                count = 0;
                i--;
            }
        }
        return ans;
    }
};