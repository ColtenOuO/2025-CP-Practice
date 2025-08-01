#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    vector<pair<int,int>> v;
    for(int i=0;i<m;i++) {
        cin >> a[i] >> b[i];
        v.push_back(make_pair(a[i]-b[i], a[i]));
    }

    sort(v.rbegin(), v.rend());
    int cnt = n, idx = m - 1, ans = 0;
    while( idx >= 0 ) {

        if( cnt < v[idx].second ) {
            idx--;
            continue;
        }

        int div = ( cnt - v[idx].second + 1 ) / v[idx].first;
        if( ( cnt - v[idx].second + 1 ) % v[idx].first != 0 ) div++;
        ans += div;
        cnt -= v[idx].first * div;
        idx--;
    }

    cout << ans << "\n";

    return 0;
}