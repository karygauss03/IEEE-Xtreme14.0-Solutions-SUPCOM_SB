//KARYGAUSS03
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

long long C, N, P, W;

int main()
{
  cin >> C >> N >> P >> W;
  if(P < C) {
    cout << min(N, W / C) << endl;
    return 0;
  }

  ll low = 0, high = min(N, W / C), best = 0;

  while(low <= high) {
    ll x = (low + high) / 2;
    ll r = W - C * x;
    if(r == 0 || (r - 1) / P < N - x) {
      best = x;
      low = x + 1;
    } else {
      high = x - 1;
    }
  }

  cout << best << endl;

  return 0;
}
