#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];
vector< vector<int> > ans;
bool visited[N];

void Compress(int n){
  vector<int> v;
  for(int i = 1; i <= n; ++i)
    v.PB(a[i]);
  sort(v.begin(), v.end());
  for(int i = 1; i <= n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  Compress(n);

  for(int i = 1; i <= n; ++i){
    if(visited[i] == 1)
      continue;
    vector<int> v;
    for(int j = i; visited[j] == 0; j = a[j]){
      v.PB(j);
      visited[j] = 1;
    }
    ans.PB(v);
  }

  printf("%lu\n", ans.size());
  for(auto v : ans){
    printf("%lu ", v.size());
    for(auto x : v)
      printf("%d ", x);
    printf("\n");
  }

  return 0;
}
