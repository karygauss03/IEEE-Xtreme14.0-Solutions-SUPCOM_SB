//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;

int s[200000];
int main() {
    int n;
    map<int, int> mp;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> s[i];
        mp[i] = s[i];
    }
    mp[n]=0;
    
    int d;
    cin >> d;
    
    int rescued = 0;
    for(int i = 0 ; i < d ;i++) {
        int l , r , v;
        cin >> l >> r >> v;
        l-- ,r--;
        auto it = mp.lower_bound(l);
        if(it->first > l) it--;
        auto itStart = it++;
        while (it->first <= r) {
            int p = it->first;
            itStart->second += it->second;
            it++;
            mp.erase(p);
        }
        rescued+= min(v, itStart->second);
        itStart->second -= min(v, itStart->second);
    }
    cout << rescued ;
    return 0;
}