// KARYGAUSS03
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

const int C = 13;
const int K = 11;
const int INF = 1e9;

int n, k;
string A, B;
string val = "23456789XJQKA";
int score[C][K];
int dp[C][K], vis[C][K];

int calc(int card, int cnt) {
  for(int i = 0; i < sz(A); i++) {
    if(A[i] == val[card]) {
      char expected = 'n';
      cnt++;
      if(cnt == 2 || cnt == 3 || cnt == 4) {
        expected = 'y';
      }
      if(expected != B[i]) {
        return -1;
      }
    }
  }
  if(cnt <= 1) return 0;
  if(cnt == 2) return 1;
  if(cnt == 3) return 20;
  if(cnt == 4) return 1760;
  return -1;
}

int solve(int cur, int rem) {
  if(cur >= C) {
    return rem == 0 ? 0 : -INF;
  }
  int& r = dp[cur][rem];
  if(vis[cur][rem]) return r;
  vis[cur][rem] = 1;
  r = -INF;
  for(int t = 0; t <= min(4, rem); t++) {
    if(score[cur][t] >= 0) {
      r = max(r, score[cur][t] + solve(cur + 1, rem - t));
    }
  }
  return r;
}

string ans = "";
void trace(int cur, int rem) {
  if(cur >= C) {
    return;
  }
  for(int t = min(4, rem); t >= 0; t--) {
    if(score[cur][t] >= 0 && solve(cur + 1, rem - t) + score[cur][t] == solve(cur, rem)) {
      ans += string(t, val[cur]);
      trace(cur + 1, rem - t);
      return;
    }
  }
}

int main()
{
  cin >> n >> k;
  cin >> A >> B;
  
  for(int i = 0; i < C; i++) {
    for(int take = 0; take <= 4; take++) {
      score[i][take] = calc(i, take);
    }
  }

  // for(int i = 0; i < C;i ++) {
  //   for(int j = 0; j <= k; j++) {
  //     cout << score[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if(solve(0, k) < 0) {
    cout << "impossible" << endl;
  } else {
    trace(0, k);
    cout << ans << endl;
  }
  return 0;
}


  for(int i = 0; i < C; i++) {
    for(int take = 0; take <= 4; take++) {
      score[i][take] = calc(i, take);
    }
  }

  // for(int i = 0; i < C;i ++) {
  //   for(int j = 0; j <= k; j++) {
  //     cout << score[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if(solve(0, k) < 0) {
    cout << "impossible" << endl;
  } else {
    trace(0, k);
    cout << ans << endl;
  }
  return 0;
}
