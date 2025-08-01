#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a[200001];
vector<int> dp[200001];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		a[i].push_back(0);
		for(int j=1;j<=m;j++) {
			int num;
			cin >> num;
			a[i].push_back(num);
		}
	}
	
	vector<int> p(n+m+1);
	for(int i=1;i<=n+m;i++) cin >> p[i];
	
	int l = 0, r = 3e15;
	while( l <= r ) {
		int mid = ( l + r ) / 2;
		for(int i=1;i<=n;i++) dp[i].clear();
		for(int i=0;i<=n;i++) {
			dp[i].push_back((int)-1e18);
			for(int j=1;j<=m;j++) dp[i].push_back((int)-1e18); 
		}
		
		dp[1][1] = mid - p[1] + a[1][1];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if( i == 1 && j == 1 ) continue;
				int now = ( i - 1 ) + ( j - 1 ) + 1;
				if( dp[i-1][j] < 0 && dp[i][j-1] < 0 ) continue;
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) - p[now] + a[i][j];
			}
		}
		
		if( dp[n][m] >= 0 ) r = mid - 1;
		else l = mid + 1;
	}
	
	cout << l << "\n";
	
	return 0;
}
