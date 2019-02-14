#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26

vector< vector<int> > v(N);
int T[N][B], nxt;
char s[N];

void AddString(){
  int i = 0;
  for(int k = 0; s[k] != '\0'; ++k){
    int j = s[k] - 'a';
    if(T[i][j] == 0)
      T[i][j] = ++nxt;
    i = T[i][j];
  }
  v[i].PB(strlen(s));
}

void DFS(int i, int d){
  bool canReduceLength = (v[i].empty() && d != 0);

  for(int j = 0; j < B; ++j){
    int k = T[i][j];
    if(k == 0){
      continue;
    }
    DFS(k, d + 1);
    for(auto x : v[k])
      v[i].PB(x);
  }

  if(!canReduceLength){
    return;
  }

  int k = 0;
  for(int j = 1; j < v[i].size(); ++j){
    if(v[i][j] > v[i][k])
      k = j;
  }

  v[i][k] = d;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    scanf("%s", s);
    AddString();
  }

  DFS(0, 0);

  int ans = 0;
  for(auto l : v[0])
    ans += l;

  printf("%d\n", ans);

  return 0;
}
