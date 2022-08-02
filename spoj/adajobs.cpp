#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define B 26

char s[N];
int min_query_string_index[N];

//----------------- Aho-Corasick Automation Start -----------------//
int T[B][N], pi[N], nxt;

void AddString(string &s, int query_no){
  min_query_string_index[0] = INT_MAX;
  int i = 0;
  for(char c: s){
    int k = c - 'a';
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
      min_query_string_index[nxt] = INT_MAX;
    }
    i = T[k][i];
  }
  min_query_string_index[i] = min(min_query_string_index[i], query_no);
}

void BuildAutomation(){
  queue<int> Q;

  Q.push(0);

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    int pv = pi[v];
    min_query_string_index[v] = min(min_query_string_index[v], min_query_string_index[pv]);

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

string ReadString(){
  scanf("%s", s);
  return string(s);
}

int Query(string& s){
  int i = 0, ans = INT_MAX;
  for(char c: s){
    int k = c - 'a';
    i = T[k][i];
    ans = min(ans, min_query_string_index[i]);
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<pair<int,string>> a;
  for(int k = 0; k < n; ++k){
    int t;
    scanf("%d", &t);
    string s = ReadString();
    
    if(t == 0){
      AddString(s, k);
    }
    else{
      a.push_back({k, s});
    }
  }

  BuildAutomation();

  for(pair<int,string>& p: a){
    printf("%s\n", Query(p.second) < p.first ? "YES" : "NO");
  }

  return 0;
}