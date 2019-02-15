#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N), choices;
int k, d[N], edgeXOR[N];
char s[N];
vector<string> ans;

void GenerateTrees(int i){
  if(ans.size() == k){
    return ;
  }

  if(i == choices.size()){
    ans.PB(string(s));
    return ;
  }

  for(auto x : choices[i]){
    s[x] = '1';
    GenerateTrees(i + 1);
    s[x] = '0';
    if(ans.size() == k){
      return ;
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d%d", &n, &m, &k);

  for(int x = 0; x < m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(x);
    adj[j].PB(x);
    edgeXOR[x] = (i ^ j);
  }

  for(int i = 1; i <= n; ++i){
    d[i] = n;
  }
  d[1] = 0;

  queue<int> Q;
  Q.push(1);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    for(auto x : adj[i]){
      int j = (edgeXOR[x] ^ i);
      if(d[i] + 1 < d[j]){
        d[j] = 1 + d[i];
        Q.push(j);
      }
    }
  }

  for(int x = 0; x < m; ++x){
    s[x] = '0';
  }

  for(int i = 1; i <= n; ++i){
    vector<int> v;
    for(auto x : adj[i]){
      int j = (edgeXOR[x] ^ i);
      if(d[i] <= d[j]){
        continue;
      }
      v.PB(x);
    }
    if(v.size() == 1){
      s[v.back()] = '1';
    }

    if(v.size() > 1){
      choices.PB(v);
    }
  }

  GenerateTrees(0);

  cout << ans.size() << '\n';
  for(auto s : ans){
    cout << s << '\n';
  }

  return 0;
}
