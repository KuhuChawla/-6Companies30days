Program to find Nth Ugly Number.

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    set<long> k;
	    k.insert(1);
	    long p = 1;
	    for(int i =0;i<n;i++){
	        p=*k.begin();
	        k.erase(k.begin());
	        k.insert(p*2);
	        k.insert(p*3);
	        k.insert(p*5);
	    }
	    return p;
	}
};