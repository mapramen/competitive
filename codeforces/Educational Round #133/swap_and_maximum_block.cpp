#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define segment_data tuple<ll,ll,ll,ll>

segment_data Combine(segment_data left_segment_data, segment_data right_segment_data){
  auto [left_sum, left_ans, left_prefix_ans, left_suffix_ans] = left_segment_data;
  auto [right_sum, right_ans, right_prefix_ans, right_suffix_ans] = right_segment_data;

  return 
  {
    left_sum + right_sum,
    max(left_suffix_ans + right_prefix_ans, max(left_ans, right_ans)),
    max(left_prefix_ans, left_sum + right_prefix_ans),
    max(left_suffix_ans + right_sum, right_suffix_ans)
  };
}

vector<segment_data> GetVersions(vector<int>& a, int k, int i){
  if(k == 0){
    return {{a[i], max(0, a[i]), max(0, a[i]), max(0, a[i])}};
  }

  vector<segment_data> A = GetVersions(a, k - 1, i);
  vector<segment_data> B = GetVersions(a, k - 1, i + (1 << (k - 1)));

  vector<segment_data> C(1 << k);

  for(int x = 0, y = (1 << (k - 1)); x < (1 << (k - 1)); ++x, ++y){
    C[x] = Combine(A[x], B[x]);
    C[y] = Combine(B[x], A[x]);
  }

  return C;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(1 << n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<segment_data> T = GetVersions(a, n, 0);
  
  int q;
  scanf("%d", &q);

  int mask = 0;
  while(q--){
    int m;
    scanf("%d", &m);
    
    mask ^= (1 << m);
    
    auto [_, ans, __, ___] = T[mask];
    printf("%lld\n", ans);
  }

  return 0;
}