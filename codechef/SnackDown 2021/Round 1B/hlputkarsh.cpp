#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001
#define B 26

char R[N];
int a[N];
pii b[N];

//----------------- Aho-Corasick Automation Start -----------------//
int T[B][N], pi[N], nxt;

void Reset(){
  for(int k = 0; k < B; ++k){
    for(int i = 0; i <= nxt; ++i){
      T[k][i] = 0;
    }
  }
  
  for(int i = 0; i <= nxt; ++i){
    pi[i] = 0, a[i] = 0;
    b[i] = {0, 0};
  }

  nxt = 0;
}

void AddString(string &s){
  int i = 0;
  for(char c: s){
    int k = c - 'a';
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
    }
    i = T[k][i];
  }
  a[i] = s.size();
}

void BuildAutomation(){
  queue<int> Q;

  Q.push(0);

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    int pv = pi[v];
    if(a[v] == 0){
      b[v] = b[pv];
    }
    else{
      b[v] = {a[v], b[pv].first};
    }

    for(int k = 0; k < B; ++k){
      int u = T[k][v];
      if(u != 0){
        if(v != 0){
          pi[u] = T[k][pv];
        }
        Q.push(u);
      }
      else{
        T[k][v] = T[k][pv];
      }
    }
  }
}
//------------------ Aho-Corasick Automation End ------------------//

vector<vector<int>> Calculate(vector<string>& S){
  Reset();

  for(auto &s: S){
    AddString(s);
  }

  BuildAutomation();

  vector<vector<int>> V;
  for(auto &s: S){
    int k = 0;
    vector<int> v(s.size() + 1);

    for(int i = 1, n = s.size(); i <= n; ++i){
      k = T[s[i - 1] - 'a'][k];
      v[i] = i == n ? b[k].second : b[k].first;
    }

    V.push_back(v);
  }

  return V;
}

int Solve(){
  int n;
  scanf("%d", &n);
  
  vector<string> S;
  for(int i = 1; i <= n; ++i){
    scanf("%s", R);
    S.push_back(string(R));
  }
  sort(S.begin(), S.end(), [](string &a, string &b) { return a.size() < b.size(); });

  vector<vector<int>> P = Calculate(S);

  for(int i = 0; i < n; ++i){
    reverse(S[i].begin(), S[i].end());
  }

  vector<vector<int>> Q = Calculate(S);

  int ans = 0;
  for(int k = 0; k < n; ++k){
    vector<int>& p = P[k];
    vector<int>& q = Q[k];

    int m = S[k].size();
    
    for(int i = 2; i <= m; ++i){
      p[i] = max(p[i], p[i - 1]);
    }

    int ansx = p[m];
    for(int i = m - 1, j = 1, x = 0; i != 0; --i, ++j){
      x = max(x, q[j]);
      ansx = max(ansx, p[i] + x);
    }

    ans += (m - ansx);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}