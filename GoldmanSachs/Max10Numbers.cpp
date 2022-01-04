//Find max 10 numbers in a list having 10M entries.
#include <bits/stdc++.h>
using namespace std;
vector<int> sol(vector<int> a, long long n){
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> pqueue;
    for(int i =0;i<n;i++){
        pqueue.push(a[i]);
        if(pqueue.size()>10){
            pqueue.pop();
        }
    }
    while(!pqueue.empty()){
        int x = pqueue.top();
        pqueue.pop();
        res.push_back(x);
    }
    return res;
}
int main() {
    long long int n;
    vector<int>ans;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans = sol(a,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}