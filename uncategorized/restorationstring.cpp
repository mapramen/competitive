#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26

vector< vector<int> > v(B);
string s[N];
int parent[N];
bool valid = 1;

string Merge(string s, string t, char c){
  int i = 0, j = 0;
  string ans;

  if(valid == 0)
    return ans;

  for( ; s[i] != c; ++i);
  for( ; t[j] != c; ++j);

  if(i > j)
    ans = string(s, 0, i + 1);
  else
    ans = string(t, 0, j + 1);

  int ix = s.size() - i, jx = t.size() - j;

  if(ix > jx)
    ans += string(s, i + 1, ix);
  else
    ans += string(t, j + 1, jx);

  valid &= (ans.find(s) != string::npos && ans.find(t) != string::npos);

  for(char c = 'a'; c <= 'z'; ++c){
    int cnt = 0;
    for(auto x : ans)
      cnt += (x == c);
    valid &= (cnt <= 1);
  }

  return ans;
}

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

void Union(int i, int j, char c){
  i = Find(i), j = Find(j);

  if(i == j)
    return ;

  if(i > j)
    swap(i, j);

  parent[j] = i;
  s[i] = Merge(s[i], s[j], c);
}

bool cmp(string a, string b){
  return a + b <= b + a;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n && valid == 1; ++i){
    cin >> s[i];
    for(char c = 'a'; c <= 'z' && valid == 1; ++c){
      int cnt = 0;
      for(auto x : s[i])
        cnt += (x == c);
      valid &= (cnt <= 1);
      if(cnt == 1)
        v[c - 'a'].PB(i);
    }
  }

  for(int i = 1; i <= n; ++i)
    parent[i] = i;

  for(int i = 0; i < B && valid == 1; ++i){
    char c = 'a' + i;
    for(auto x : v[i])
      Union(x, v[i][0], c);
  }

  vector<string> S;
  for(int i = 1; i <= n && valid == 1; ++i){
    if(i == parent[i])
      S.PB(s[i]);
  }

  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());

  sort(S.begin(), S.end(), cmp);

  string ans;
  for(auto s : S)
    ans += s;

  vector<int> V;
  for(auto s : S){
    int c = 0, p = 0;
    while(ans.find(s, p) != string::npos){
      ++c;
      p += ans.find(s, p) + 1;
    }
    V.PB(c);
  }

  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());

  valid &= (V.size() == 1);

  if(valid == 0)
    cout << "NO\n";
  else
    cout << ans << '\n';

  return 0;
}
