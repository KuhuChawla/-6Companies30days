class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n = A.size();
		   queue<int>q;
		   string temp1 ="";
		   int arr[26]={0};
		   for(int i =0;i<n;i++){
		       arr[A[i]-'a']++;
		       if(arr[A[i]-'a']==1){
		           q.push(A[i]);
		       }
		       while(!q.empty() && arr[q.front()-'a']!=1){
		           q.pop();
		       }
		       if(q.empty()){
		           A[i]='#';
		       }
		       else{
		           A[i]=q.front();
		       }
		   }
		   return A;
		}

};