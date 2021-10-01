//KARYGAUSS03
#include <bits/stdc++.h>
#include<numeric>

using namespace std;

int main() {
    int n,cb,cp;
    cin>>n>>cb>>cp;
    int ans=0;
    vector<int> b(n);
    vector <int> p(n);
    for (int i=0;i<n;i++){
        cin>>b[i]>>p[i];
    }
    int bb = accumulate(b.begin(),b.end(),0);
    int pp =accumulate(p.begin(),p.end(),0);

    if (bb%10==0){
        ans+=(bb/10)*cb;
    }else{
        ans+=(bb/10)*cb +cb;
    }
    if (pp%10==0){
        ans+=(pp/10)*cp;
    }else{
        ans+=(pp/10)*cp +cp;
    }
    cout<<ans<<endl;




}
