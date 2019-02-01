#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 400001

int parent[N], a[N], nxt = 0;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> M;

int GetMappedNode(int i, bool doInsert){
  if(M.count(i) == 0){
    if(doInsert){
      M[i] = ++nxt;
      parent[nxt] = nxt;
      return nxt;
    }
    else{
      return 0;
    }
  }
  return M[i];
}

int Find(int i){
  if(i == parent[i]){
    return i;
  }
  int j = parent[i];
  parent[i] = Find(parent[i]);
  a[i] ^= a[j];
  return parent[i];
}

void Union(int i, int j, int x){
  int pi = Find(i), pj = Find(j);
  if(pi == pj){
    return ;
  }
  if(pi > pj){
    swap(pi, pj);
  }
  parent[pj] = pi;
  a[pj] = (a[i] ^ a[j] ^ x);
}

int main(){
  int q, ans = 0;

  scanf("%d", &q);
  while(q--){
    int t, l, r, x;
    scanf("%d%d%d", &t, &l, &r);

    if(t == 1){
      scanf("%d", &x);
    }

    if(ans < 0){
      ans = 1;
    }

    l ^= ans, r ^= ans, x ^= ans;

    if(l > r){
      swap(l, r);
    }

    ++r;

    if(t == 1){
      l = GetMappedNode(l, 1), r = GetMappedNode(r, 1);
      Union(l, r, x);
    }
    else{
      l = GetMappedNode(l, 0), r = GetMappedNode(r, 0);
      if(l > 0 && r > 0 && Find(l) == Find(r)){
        ans = (a[l] ^ a[r]);
      }
      else{
        ans = -1;
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}
