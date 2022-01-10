class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    set<char> nuts1;
	    set<char> bolts1;
	    for (int i=0;i<n;i++){
	        nuts1.insert(nuts[i]);
	        bolts1.insert(bolts[i]);
	    }
	    auto itr = nuts1.begin();
	    for(int i = 0;i<n;i++){
	        if(nuts1.find(bolts[i])!=nuts1.end() && bolts1.find(nuts[i])!= bolts1.end()){
	            nuts[i]=*itr;
	            bolts[i]=*itr;
	        }
	        itr++;
	    }
	}

};