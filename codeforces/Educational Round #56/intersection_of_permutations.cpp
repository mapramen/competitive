#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], b[N], invA[N], invB[N];
ordered_set T[N];

void Insert(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i].insert(x);
  }
}

void Remove(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i].erase(x);
  }
}

int Query(int i, int x){
  int ans = 0;
  for(++x; i > 0; i -= (i & -i)){
    ans += T[i].order_of_key(x);
  }
  return ans;
}

void Insert(int i){
  Insert(invA[i], invB[i]);
}

void Remove(int i){
  Remove(invA[i], invB[i]);
}

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    invA[a[i]] = i;
  }

  for(int i = 1; i <= n; ++i){
    invB[b[i]] = i;
  }

  for(int i = 1; i <= n; ++i){
    Insert(i);
  }
}

void Update(){
  int i, j;
  scanf("%d%d", &i, &j);

  Remove(b[i]);
  Remove(b[j]);

  swap(b[i], b[j]);
  i = b[i], j = b[j];
  swap(invB[i], invB[j]);

  Insert(i);
  Insert(j);
}

int Query(){
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
  return Query(x2, y2) + Query(x1 - 1, y1 - 1) - Query(x2, y1 - 1) - Query(x1 - 1, y2);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  PreProcess(n);

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      printf("%d\n", Query());
    }
    else{
      Update();
    }
  }
  return 0;
}