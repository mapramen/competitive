#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Query(int i){
  printf("? %d\n", i);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n + 1);
  vector<bool> visited(n + 1);

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }

    int j = i;
    vector<int> v;
    while(true){
      j = Query(i);
      v.push_back(j);

      if(visited[j]){
        break;
      }

      visited[j] = true;
    }

    for(int x = 1; x < v.size(); ++x){
      p[v[x - 1]] = v[x];
    }
  }

  printf("! ");
  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}