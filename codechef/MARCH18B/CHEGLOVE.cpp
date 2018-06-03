#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<stack>
#include<math.h>
#define mp make_pair
#define pb push_back
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define pii pair< long, int >
#define pr(a) printf("%d ",a)
#define prl(a) printf("%lld ",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
using namespace std;
int main() {
       int t;
       cin>>t;
       while(t--)
       {
               int n;
               cin>>n;
               int f[n],g[n];
               rep(i,0,n)
                       cin>>f[i];
               rep(i,0,n)
                       cin>>g[i];
               int fr = 1;
               int b = 1;
               rep(i,0,n)
               {
                       if(g[i] < f[i])
                               fr = 0;
                       if(g[i]<f[n-1-i])
                               b = 0;

               } 
               if(fr and b)
                       cout<<"both\n";
               else if(fr)
                       cout<<"front\n";
               else if(b)
                       cout<<"back\n";
               else 
                       cout<<"none\n";
       }
        return 0;
}
