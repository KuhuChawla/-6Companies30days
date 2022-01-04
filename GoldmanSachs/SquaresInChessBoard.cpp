//Find total number of Squares in a N*N chessboard

#include <iostream>
using namespace std;

int main() {
   int n;
    cin>>n;
	if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int ans = (n*(n+1)*(2*n+1))/6;
    cout<<ans;
	return 0;
}