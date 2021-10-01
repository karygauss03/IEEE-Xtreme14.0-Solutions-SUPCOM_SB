//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
int x[200000], y[200000];
long long s[10000000];
long long t[10000000];
long long k[10000000];

int main() {
    int n, q, sq, mk;
    cin >> n >> q >> sq >> mk;
    for(int i = 1 ; i <= n ; i++) {
        cin >> x[i] >> y[i];
    }
    long long as, bs, cs, at, bt, ct, ak, bk, ck;
    cin >> as >> bs >> cs >> at >> bt >> ct >> ak >> bk >> ck;
    
    for(int i = 0 ; i < sq ; i++) {
        cin >> s[i] >> t[i] >> k[i];
    }
    for(int i = sq ; i < q; i++) {
        s[i] = (as * s[i-1] + bs * s[i-2] + cs) % n + 1;
        t[i] = (at * t[i-1] + bt * t[i-2] + ct) % n + 1;
        k[i] = (ak * k[i-1] + bk * k[i-2] + ck) % mk;
    }
    
    if (n<=500) {
        int mat[502][502] ;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = i ; j<=n ; j++) {
                mat[i][j] = mat[j][i] = max(0 , -1 + abs(x[i]-x[j]) + abs(y[i] - y[j]));
            }
        }
        for(int k = 1 ; k <= n ; k++) {
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j<=n ; j++) {
                mat[i][j] = min(mat[i][j], max(mat[i][k],  mat[k][j]));
            }
        }}
        
        long long ans = 0;
        long long mod = 1000000007;
        long long base2 = 2;
        for(int i = 0 ; i < q ; i++) {
            //cout << s[i] << ' ' << t[i] << ' ' << k[i] <<endl;
            ans += (mat[s[i]][t[i]] <= k[i]) * base2;
            ans %= mod;
            base2 = (base2 * 2) % mod;
        }
        cout << ans;
    }
    
    return 0;
}