#include<bits/stdc++.h>
using namespace::std;

/*
	Problem: Pashmak and Parmida's problem - Codeforces 459D

	Author: Racso Galvan
*/

const int N = 1000000+5;

int n;
int a[N];

long long merge(vector<int> &L, vector<int> &R){
	int pR = 0;
	long long ans = 0LL;
	for(int i=0; i<L.size(); i++){
		while(pR < R.size() and R[pR] < L[i]){
			pR += 1;
		}
		ans += pR;
	}
	return ans;
}

long long solve(vector<int> &prefix, vector<int> &suffix){
	int len = prefix.size();
	if(len <= 1){
		return 0LL;
	}
	vector<int> Lprefix(prefix.begin(),prefix.begin() + len/2);
	vector<int> Lsuffix(suffix.begin(),suffix.begin() + len/2);
	vector<int> Rprefix(prefix.begin() + len/2, prefix.end());
	vector<int> Rsuffix(suffix.begin() + len/2, suffix.end());
	long long ans = 0LL;
	ans += solve(Lprefix,Lsuffix);
	ans += solve(Rprefix,Rsuffix);
	sort(Lprefix.begin(),Lprefix.end());
	sort(Rsuffix.begin(),Rsuffix.end());
	ans += merge(Lprefix,Rsuffix);
	return ans;
}

void computePrefix(vector<int> &v){
	map<int,int> F;
	for(int i=1; i<=n; i++){
		F[a[i]] += 1;
		v[i-1] = F[a[i]];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
	}
	vector<int> prefix(n);
	computePrefix(prefix);
	reverse(a+1,a+n+1);
	vector<int> suffix(n);
	computePrefix(suffix);
	reverse(suffix.begin(),suffix.end());
	long long ans = solve(prefix,suffix);
	cout << ans << endl;
	return 0;
}
