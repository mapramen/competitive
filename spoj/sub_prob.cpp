#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2500001
#define B 62
#define M 2001

int query_to_node[M];
bool visited[N];

//----------------- Aho-Corasick Automation Start -----------------//
int T[B][N], pi[N], nxt;

void Reset(){
  for(int k = 0; k < B; ++k){
    for(int i = 0; i <= nxt; ++i){
      T[k][i] = 0;
    }
  }
  
  for(int i = 0; i <= nxt; ++i){
    pi[i] = 0, visited[i] = false;
  }

  nxt = 0;
}

int Char2Int(char c){
  if('a' <= c && c <= 'z'){
    return c - 'a';
  }

  if('A' <= c && c <= 'Z'){
    return 26 + c - 'A';
  }

  return 52 + c - '0';
}

void AddString(string &s, int query_no){
  int i = 0;
  for(char c: s){
    int k = Char2Int(c);
    if(T[k][i] == 0){
      T[k][i] = ++nxt;
    }
    i = T[k][i];
  }
  query_to_node[query_no] = i;
}

void BuildAutomation(){
  queue<int> Q;

  Q.push(0);

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    int pv = pi[v];

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

int main(){
  string S;
  cin >> S;

  int q;
  scanf("%d", &q);

  Reset();

  for(int k = 1; k <= q; ++k){
    string qs;
    cin >> qs;
    AddString(qs, k);
  }

  BuildAutomation();

  int i = 0;
  for(char c: S){
    int k = Char2Int(c);
    i = T[k][i];
    visited[i] = true;
  }

  for(int i = nxt; i != 0; --i){
    visited[pi[i]] = visited[pi[i]] || visited[i];
  }

  for(int k = 1; k <= q; ++k){
    putchar(visited[query_to_node[k]] ? 'Y' : 'N');
    putchar('\n');
  }

  return 0;
}