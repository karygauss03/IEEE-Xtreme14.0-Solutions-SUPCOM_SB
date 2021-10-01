//KARYGAUSS03
#include <bits/stdc++.h>
using namespace std;

// Region Debug
string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0)
      res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

typedef complex<double> point;
#define PI acos(-1.0)
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine
typedef long long ll;

const int N = 1e5 + 5;

int n;
vector<pair<point, int>> pt;

void solve() {
  cin >> n;
  pt.clear(); pt.resize(n);
  for(int i = 0; i < n; i++) {
    double x, y, t;
    cin >> x >> y >> t;
    pt[i] = {point(x, y), t};
  }
  sort(all(pt), [](const pair<point, int>& a, const pair<point, int>& b) {
    return angle(a.first) < angle(b.first);
  });
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    // cout << pt[i].first.X << " " << pt[i].first.Y << endl;
    if(i == 0 || pt[i - 1].second != pt[i].second) {
      cnt++;
    }
  }
  if(cnt == 1) {
    cout << "YES" << endl;
    return;
  }
  if(cnt > 3) {
    cout << "NO" << endl;
    return;
  }
  vector<int> A, B;
  for(int i = 0; i < n; i++) {
    if(pt[i].second != pt[(i + 1) % n].second) {
      if(pt[i].second == 1) A.push_back(i), B.push_back((i + 1) % n);
      else B.push_back(i), A.push_back((i + 1) % n);
    }
  }
  sort(all(A));
  sort(all(B));
  // debug(A); debug(B);
  double a = angle(pt[A[1]].first) - angle(pt[A[0]].first);
  double b = angle(pt[B[1]].first) - angle(pt[B[0]].first);
  // cout << a / PI * 180 << " " << b / PI * 180 << endl;
  bool good = 2 * PI > a + b;
  cout << (good ? "YES" : "NO") << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while(T--) {
    solve();
  }
  return 0;
}
