#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002
#define M (1 << 19)

set<int> probablySick;

int T[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
 
  T[k] = N;
}
 
void Update(int k, int l, int r, int i, int val){
  if(i < l || r < i){
    return;
  }
 
  if(i == l && r == i){
    T[k] = min(T[k], val);
    return;
  }
 
  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, i, val);
  Update(2 * k + 2, mid + 1, r, i, val);
  T[k] = min(T[2 * k + 1], T[2 * k + 2]);
}
 
int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return N;
  }
 
  if(ql <= l && r <= qr){
    return T[k];
  }
 
  int mid = (l + r) / 2;
  return min(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}
 
void Initialize(){
  for(int i = 0; i <= N; ++i){
    probablySick.insert(i);
  }
  BuildSegmentTree(0, 0, N);
}

void UpdateNotSick(int l, int r){
  while(true){
    auto it = probablySick.lower_bound(l);
    if(*it > r){
      break;
    }
    probablySick.erase(it);
  }
}

void UpdateProbablySick(int l, int r){
  Update(0, 0, N, l, r);
}

void Update(int l, int r, int x){
  if(x == 0){
    UpdateNotSick(l, r);
  }
  else{
    UpdateProbablySick(l, r);
  }
}

string Query(int i){
  auto it = probablySick.find(i);

  if(it == probablySick.end()){
    return "NO";
  }

  if(Query(0, 0, N, *prev(it) + 1, i) < *next(it)){
    return "YES";
  }

  return "N/A";
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  Initialize();

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 0){
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      Update(l, r, x);
    }
    else{
      int i;
      scanf("%d", &i);

      printf("%s\n", Query(i).c_str());
    }
  }
  return 0;
}