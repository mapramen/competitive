#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

set<string> S;
vector< vector<char> > V(10);
bool found = 0;
string ans;
char s[100];

void DFS(int i, int m){
  if(found == 1)
    return ;

  if(i == m){
    if(S.find(string(s)) == S.end()){
      found = 1;
      ans = string(s);
    }
    return ;
  }

  for(auto c : V[i]){
    s[i] = c;
    DFS(i + 1, m);
  }
}

string Solve(){
  int n, m;

  cin >> n >> m;

  S.clear();

  for(int i = 0; i < m; ++i)
    V[i].clear();

  for(int x = 0; x < n; ++x){
    string t;
    cin >> t;
    for(int i = 0; i < m; ++i)
      V[i].PB(t[i]);
    S.insert(t);
  }

  for(int i = 0; i < m; ++i){
    sort(V[i].begin(), V[i].end());
    V[i].erase(unique(V[i].begin(), V[i].end()), V[i].end());
  }

  for(int i = 0; i < 100; ++i)
    s[i] = '\0';

  found = 0;
  DFS(0, m);

  if(found == 0)
    return "-";
  else
    return ans;
}

int main(){
  int t;

  cin >> t;
  for(int k = 1; k <= t; ++k)
    cout << "Case #" << k << ": " << Solve() << '\n';

  return 0;
}
