#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 6
#define B 3
#define D 2

set<int> s;
map<int,int> d, parent;

int main(){
  s.insert(0);
  d[0] = 0;
  parent[0] = 0;

  for(int n = B; s.size() != (1 << N); ++n){
    for(int mask = 0; mask < (1 << n); ++mask){
      if(__builtin_popcount(mask) != B || (mask & (1 << (n - 1))) == 0){
        continue;
      }

      vector<int> v;
      for(int i = 0; i < n; ++i){
        if((mask & (1 << i)) == 0){
          continue;
        }
        v.PB(i);
      }

      set<int> a;
      for(int i = 0; i < v.size() - 1; ++i){
        a.insert(v[i + 1] - v[i]);
      }

      if(a.size() > 1){
        continue;
      }

      int i = -1;
      while(d.upper_bound(i) != d.end()){
        i = d.upper_bound(i)->first;
        if(d[i] >= D){
          continue;
        }
        int j = (i ^ mask);
        if(d.find(j) == d.end() || d[j] > 1 + d[i]){
          d[j] = 1 + d[i];
          parent[j] = mask;
        }
      }
    }

    for(auto p : d){
      int i, di;
      tie(i, di) = p;
      if(di <= 2){
        s.insert((i & ((1 << N) - 1)));
      }
    }

    printf("%d %lu\n", n, s.size());
  }

  return 0;
}
