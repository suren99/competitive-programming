#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define pii pair<int , int >
#define pr(a) printf("%d\n",a)
#define prl(a) printf("%lld\n",a)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a) for(int i=a;i>=0;i--)
#define ll long long
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if (a.x == b.first) 
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    string s;
    cin >> s;
    /* find all regular brackets */
    stack <pair<char,int> > st;
    vector<pair<int,int> > ranges;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(make_pair(s[i],i));
        }
        else {
            if (!st.size())
                continue;
            pair<char, int> top = st.top();
            st.pop();
            ranges.push_back(make_pair(top.second, i));            
        }
    }
    if (!ranges.size()) {
        cout<<"0  1\n";
        return 0;
    }
    /* merge overlapping ranges */
    sort(ranges.begin(), ranges.end(), cmp);
    stack<pair<int,int> > res;
    res.push(ranges[0]);
    for (int i = 1; i < ranges.size(); i++) {
        pair<int,int> now = ranges[i];
        pair<int,int> top = res.top();
        res.pop();
        if (now.x <= top.y and now.y <= top.y)
            res.push(top);
        else if (now.x == top.y + 1) 
            res.push(make_pair(top.x, now.y));
        else if (now.x > top.y) {
            res.push(top);
            res.push(now);
        }
        else
            res.push(make_pair(top.x, now.y));
    }
    /* find largest range and also the count */
    int mx_sz = 0;
    int cnt = 0;
    while (res.size()) {
        pair<int,int> top = res.top();
        res.pop();
        if (top.y - top.x + 1 > mx_sz) {
            mx_sz = top.y - top.x + 1;
            cnt = 1;
        }
        else if ((top.y - top.x + 1) == mx_sz) {
            cnt++;
        }
    }
    cout<< mx_sz<<" "<<cnt<<"\n";
}