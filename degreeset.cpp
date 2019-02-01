//https://pdfs.semanticscholar.org/1704/a52b11415a2a874d43fe3ded29b71e63e16d.pdf
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

bool adj[N][N];

void BuildGraph(vector<int>& d){
  int k = d.back();

  if(d.size() > 1){
    vector<int> v;
    for(int i = d.size() - 2; i > -1; --i)
      v.PB(k - d[i]);
    BuildGraph(v);
  }

  for(int i = 0; i <= k; ++i)
    for(int j = 0; j < i; ++j)
      adj[i][j] = !adj[i][j];
}

int main(){
  int n;
  vector<int> d;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    d.PB(x);
  }

  BuildGraph(d);

  int k = d.back(), m = 0;
  for(int i = 0; i <= k; ++i)
    for(int j = 0; j < i; ++j)
      m += adj[i][j];

  printf("%d\n", m);
  for(int i = 0; i <= k; ++i)
    for(int j = 0; j < i; ++j)
      if(adj[i][j])
        printf("%d %d\n", j + 1, i + 1);

  return 0;
}
