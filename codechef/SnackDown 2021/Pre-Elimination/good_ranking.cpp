#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define ppi pair<pii,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];
int a[N];
bool visited[N];

void Sort(int l, int r){
  for(int i = l; i <= r; ++i){
    for(int j = i + 1; j <= r; ++j){
      if(s[a[i]][a[j]] == '0'){
        swap(a[i], a[j]);
      }
    }
  }
}

bool Check(int n){
  for(int i = 0; i < n; ++i){
    for(int j = min(i + ((n + 1) / 2), n - 1); j != i; --j){
      if(s[a[i]][a[j]] == '0'){
        return false;
      }
    }
  }
  return true;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  vector<ppi> v;
  for(int i = 0; i < n; ++i){
    int w = 0, l = 0;
    for(int j = 0; j < n; ++j){
      w += (j != i && s[i][j] == '1');
      l += (j != i && s[i][j] == '0');
    }
    v.push_back({{-w, l}, i});
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; ++i){
    a[i] = v[i].second;
  }

  Sort(0, n / 2 - 1);
  Sort((n + 1) / 2, n - 1);

  if(!Check(n)){
    printf("-1\n");
    return;
  }

  for(int i = 0; i < n; ++i){
    printf("%d ", a[i] + 1);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}