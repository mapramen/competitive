#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)

vector<int> a;
vector<vector<int>> b;

void ReadArray(int n, vector<int>& a){
  a.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
}

int T[M], lazyUpdate[M];

void BuildSegmentTree(int k, int l, int r){
  T[k] = 0, lazyUpdate[k] = 0;
  if(l != r){
    int mid = l + (r - l) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
}

void UpdateNode(int k, int x){
  T[k] += x, lazyUpdate[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyUpdate[k] == 0){
    return;
  }

  UpdateNode(2 * k + 1, lazyUpdate[k]);
  UpdateNode(2 * k + 2, lazyUpdate[k]);
  lazyUpdate[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < ql || qr < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);

  int mid = l + (r - l) / 2;
  Update(2 * k + 1, l, mid, ql, qr, x);
  Update(2 * k + 2, mid + 1, r, ql, qr, x);
  T[k] = min(T[2 * k + 1], T[2 * k + 2]);
}

void Update(int val, int x){
  int i = lower_bound(a.begin(), a.end(), val) - a.begin();
  int n = a.size() - 1;
  Update(0, 0, n, n - i, n, x);
}

int Ceil(ll s, int n){
  return (s + n - 1) / n;
}

string Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ReadArray(n, a);

  b.resize(m);
  for(int i = 0; i < m; ++i){
    int k;
    scanf("%d", &k);
    ReadArray(k, b[i]);
  }

  a.push_back(INT_MAX);
  sort(a.begin(), a.end());

  BuildSegmentTree(0, 0, n);
  for(int i = 0; i < n; ++i){
    Update(0, 0, n, n - i, n, 1);
  }

  for(vector<int>& bi: b){
    int k = bi.size();
    ll s = 0;

    for(int x: bi){
      s += x;
    }
    
    Update(Ceil(s, k), -1);
  }

  string ans;
  for(vector<int>& bi: b){
    int k = bi.size();
    ll s = 0;
    
    for(int x: bi){
      s += x;
    }

    Update(Ceil(s, k), 1);

    for(int x: bi){
      Update(Ceil(s - x, k - 1), -1);
      ans.push_back(T[0] < 0 ? '0' : '1');
      Update(Ceil(s - x, k - 1), 1);
    }

    Update(Ceil(s, k), -1);

    bi.clear();
  }

  a.clear();

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}