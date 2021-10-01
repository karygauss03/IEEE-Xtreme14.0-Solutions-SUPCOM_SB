//KARYGAUSS03
#include <bits/stdc++.h>
using namespace std;
#define s 10000009
long long int a[s],b[s];


int main()

{
   long long int t,m,n,k,i,j,sum,p,l;


   cin>>t;

   for(i=0;i<t;i++)
   {

       sum=0;
       cin>>m>>n>>k;
       for(j=0;j<m;j++)
       {

           cin>>a[j];
           b[j]=n-a[j];

       }

       sort(a, a + m, greater<int>());
       sort(b, b + m, greater<int>());

       for(l=0;l<k;l++)
        sum+=b[l];
       for(p=0;p<(m-k);p++)
        sum+=a[p];
       cout<<sum<<endl;
   }
   return 0;

}
