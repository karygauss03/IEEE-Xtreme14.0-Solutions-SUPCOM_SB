//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;


int hammingDist(string str1, string str2){
    int i = 0, count = 0;
    while (str1[i] != '\0'){
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin >> t;
  string in[t];
  for (int i = 0; i < t; i++) 
    cin >> in[i];
  sort(in, in + t);
  vector<pair<string, ll>> dic;
  ll counter = 1LL;
  for (int i = 1; i < t; i++) {
    if (in[i] == in[i - 1]) {
      counter++;
    } else {
      dic.push_back({in[i - 1], counter});
      counter = 1LL;
    }
  }
  dic.push_back({in[t - 1], counter}); 
  map<string, ll> dp;
  ll ans = 0;
  for (int i = t - 1; i >= 0; i--) {
    string& cur = dic[i].first;
    ll cnt = dic[i].second;
    for (int j = 0; j < 14; j++) {
      if (cur[j] == '-') continue;
      char temp = cur[j];
      cur[j] = '*';
      if (dp.count(cur)) ans += (cnt * dp[cur]);
      dp[cur] += cnt;
      cur[j] = temp;
    }
  }
  cout << ans << '\n';
    return 0;
}