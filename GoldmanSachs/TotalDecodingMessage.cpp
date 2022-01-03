//Recursion Method TLE
int helpFunc(string &s,int n){
	    if(n<=1){
	        return 1;
	    }
	    int singleDigit = s[n-1]>'0'? helpFunc(s,n-1):0;
	    int twoDigit = (s[n-2]=='1' || (s[n-2]=='2'&&s[n-1]<'7'))? helpFunc(s,n-2):0;
	    return singleDigit+twoDigit;
}
int CountWays(string s){
	int n = s.length();
	if(s[0]=='0'){
		return 0;
	}
	return helpFunc(s,n);		
}

//optimised solution using dp

	int CountWays(string s){
		int n = s.length();
		int dp[n+1];
		int mod = 1e9 + 7;
		dp[0] = 1;
		dp[1]=1;
		if(n==1 && s[0]!='0'){
		    return 1;
		}
		if(s[0]=='0'){
		    return 0;
		}
		for(int i =2;i<=n;i++){
		    dp[i]=0;
		    if(s[i-1]>'0'){
		        dp[i]=dp[i-1];
		    }
		    if(s[i-2]=='1'|| (s[i-2]=='2'&&s[i-1]<'7')){
		        dp[i]=(dp[i]+dp[i-2])%mod;
		    }
		}
		return dp[n];
		
		}
