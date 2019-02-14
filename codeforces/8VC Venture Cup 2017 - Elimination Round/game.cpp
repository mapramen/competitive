#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define B 26

int T[N][B], treeSize;

int GetStringNo(int i, char c){
  int j = c - 'a';
  if(T[i][j] == 0)
    T[i][j] = ++treeSize;
  return T[i][j];
}

bool Solve(int n, int m){
  return n > m;
}

int main(){
  int n, m, p;
  set<int> s1, s2, s3;
  bool ans;

  cin >> n >> m;

  while(n--){
    string s;
    int stringNo = 0;

    cin >> s;

    for(int i = 0; i < s.size(); i++)
      stringNo = GetStringNo(stringNo, s[i]);

    s1.insert(stringNo);
  }

  while(m--){
    string s;
    int stringNo = 0;

    cin >> s;

    for(int i = 0; i < s.size(); i++)
      stringNo = GetStringNo(stringNo, s[i]);

    s2.insert(stringNo);
  }

  for(auto x : s1)
    if(s2.find(x) != s2.end())
      s3.insert(x);

  p = s3.size(), n = s1.size() - p, m = s2.size() - p;

  if(p % 2 == 0)
    ans = Solve(n, m);
  else
    ans = 1 - Solve(m, n);

  if(ans)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
