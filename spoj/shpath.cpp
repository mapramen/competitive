#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[20];
map<string,int> cityIndex;
vector<vector<pii>> adj;
vector<int> d;
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
  }
  
  adj.clear();
  d.clear();
  cityIndex.clear();
}

string ReadCityName(){
  scanf("%s", s);
  return string(s);
}

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int Dis(int n, int s, int t){
  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  CheckAndPush(s, 0);

  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    if(i == t){
      break;
    }

    for(pii edge: adj[i]){
      CheckAndPush(edge.first, di + edge.second);
    }
  }

  for( ; !Q.empty(); Q.pop());

  return d[t];
}

void Solve(){
  int n;
  scanf("%d", &n);

  adj.resize(n + 1);
  d.resize(n + 1);
  
  for(int i = 1; i <= n; ++i){
    cityIndex[ReadCityName()] = i;

    int m;
    scanf("%d", &m);
    while(m--){
      int j, c;
      scanf("%d%d", &j, &c);
      adj[i].push_back({j, c});
    }
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int s = cityIndex[ReadCityName()];
    int t = cityIndex[ReadCityName()];
    printf("%d\n", Dis(n, s, t));
  }

  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}