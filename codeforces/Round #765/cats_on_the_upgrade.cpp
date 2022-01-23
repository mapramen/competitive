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
#define pil pair<int,ll>
#define N 300002

char s[N];
stack<int> S, P;
int matchOpenBracket[N], parent[N];
ll T[N];
ordered_set children[N];

void Update(int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void AddParentChild(int i, int j){
  while(!P.empty() && P.top() > j){
    int k = P.top();
    P.pop();

    parent[k] = i;
    children[i].insert(k);
  }

  P.push(i);
  matchOpenBracket[i] = j;
}

ll Query(int l, int r){
  int i = parent[r];
  ll c = 1 + children[i].order_of_key(r) - children[i].order_of_key(l);
    
  return Query(r) - Query(l - 1) + c * (c - 1) / 2;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s);

  for(int i = 1; i <= n; ++i){
    char x = s[i - 1];
    if(x == '('){
      S.push(i - 1);
      continue;
    }

    if(S.empty() || s[S.top()] == ')'){
      continue;
    }

    int j = S.top() + 1;
    S.pop();

    AddParentChild(i, j);
  }

  AddParentChild(n + 1, 0);

  for(int i = 1; i <= n; ++i){
    if(matchOpenBracket[i] == 0){
      continue;
    }

    ll c = children[i].size();
    Update(i, 1 + (c * (c - 1) / 2));
  }

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if(t == 1){
      Update(r, -1);

      int i = parent[r];
      children[i].erase(r);
      Update(i, -(int)children[i].size());
    }
    else{
      printf("%lld\n", Query(l, r));
    }
  }

  return 0;
}