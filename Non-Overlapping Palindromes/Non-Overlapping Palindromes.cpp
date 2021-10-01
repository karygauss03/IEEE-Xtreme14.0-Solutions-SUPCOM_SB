//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;

#ifndef preetam
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif




typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
const ll mod = 1e9;

vector<vector<bool>> dp;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
	while(t--){
        cin >> s;
        int n = s.length();
        dp.assign(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i < (n - 1); i++)
            if (s[i] == s[i + 1])
            dp[i][i + 1] = true;
        int t1;
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n; i++) {
            t1 = i + len - 1;
            if (t1 >= n)
                break;
            if (dp[i + 1][t1 - 1]) {
                if (s[i] == s[t1]) {
                dp[i][t1] = true;
                }
            }
            }
        }

        vector<int> endAt(n, 0);
        vector<int> startAt(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = (i); j < n; j++) {
            if (dp[i][j]) {
                startAt[i] = max(startAt[i], j - i + 1);
                endAt[j] = max(endAt[j], j - i + 1);
            }
            }
        }

        for (int i = 1; i < n; i++) {
            endAt[i] = max(endAt[i - 1], endAt[i]);
        }

        for (int i = (n - 2); i >= 0; i--) {
            startAt[i] = max(startAt[i + 1], startAt[i]);
        }

        int ans = 0;

        for (int i = 0; i < (n - 1); i++) {
            ans = max(ans, endAt[i] + startAt[i + 1]);
        }
        cout << ans << endl;
	}
	return 0;
}