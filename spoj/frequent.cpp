#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)

struct Node{
  int ans_value;
  int ans_count;
  int left_value;
  int left_count;
  int right_value;
  int right_count;
};

int a[N];
Node T[M];

Node Combine(Node a, Node b){
  int ans_value, ans_count;
  
  if(a.ans_count >= b.ans_count){
    ans_count = a.ans_count, ans_value = a.ans_value;
  }
  else{
    ans_count = b.ans_count, ans_value = b.ans_value;
  }

  int left_value = a.left_value, left_count = a.left_count;
  if(a.left_value == a.right_value && a.right_value == b.left_value){
    left_count += b.left_count;
  }

  int right_value = b.right_value, right_count = b.right_count;
  if(b.left_value == b.right_value && a.right_value == b.left_value){
    right_count += a.right_count;
  }

  if(left_count > ans_count){
    ans_count = left_count, ans_value = left_value;
  }

  if(right_count > ans_count){
    ans_count = right_count, ans_value = right_value;
  }

  if(a.right_value == b.left_value && a.right_count + b.left_count > ans_count){
    ans_count = a.right_count + b.left_count, ans_value = a.right_value;
  }

  return Node{
    ans_value,
    ans_count,
    left_value,
    left_count,
    right_value,
    right_count
  };
}

Node BuildSegmentTree(int k, int l, int r){
  if(l == r){
    int value = a[l];
    T[k] = Node{value, 1, value, 1, value, 1};
  }
  else{
    int mid = (l + r) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

Node Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return Node {0, 0, 0, 0, 0, 0};
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = (l + r) / 2;
  return Combine(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

void Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  int q;
  scanf("%d", &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", Query(0, 1, n, l, r).ans_count);
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}