//KARYGAUSS03
#include <bits/stdc++.h>
using namespace std;

int main() {


    long long w,h,a,b,m,c,X,Y,Z=0;


    cin>>w>>h>>a>>b>>m>>c;


    if(w%a==0){
        X=w/a;

    }else{
        X=(w/a)+1;
        Z+=(h);
    }


    if(h%b==0){
        Y=h/b;


    }else{

        Y=(h/b)+1;
        Z+=w;


    }


    cout<<(ceil((X*Y)/10.0)*m)+Z*c<<endl;


    return 0;
}
