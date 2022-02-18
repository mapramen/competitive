#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define data tuple<int,int,int,int,int,int>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<data> a(n);
  for(int i = 0; i < n; ++i){
    int cc, bc, g1, g2, g3, g4;
    scanf("%d%d%d%d%d%d", &cc, &bc, &g1, &g2, &g3, &g4);
    a[i] = {cc, bc, g1, g2, g3, g4};
  }
  sort(a.begin(), a.end());

  for(int i = 0; i < n; ++i){
    int j = i;
    for( ; j < n && a[j] == a[i]; ++j);

    printf("%02d %08d %04d %04d %04d %04d %d\n", get<0>(a[i]), get<1>(a[i]), get<2>(a[i]), get<3>(a[i]), get<4>(a[i]), get<5>(a[i]), j - i);
    i = j - 1;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
    if(t != 0){
      printf("\n");
    }
  }
  return 0;
}