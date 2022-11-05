#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 9
#define BLOCK_SIZE (1 << B)

struct block_data
{
  ll sum;
  ll ans;
  ll left_ans;
  ll right_ans;
};

int a[BLOCK_SIZE * BLOCK_SIZE];
vector<vector<block_data>> dp(BLOCK_SIZE, vector<block_data>(BLOCK_SIZE));

block_data Calculate(int k){
  int l = k * BLOCK_SIZE, r = l + BLOCK_SIZE;
  ll sum = 0, ans = 0, left_ans = 0, right_ans = 0;

  for(int i = l; i < r; ++i){
    sum = max(0ll, sum + a[i]);
    ans = max(ans, sum);
  }

  sum = 0;
  for(int i = l; i < r; ++i){
    sum += a[i];
    left_ans = max(left_ans, sum);
  }

  sum = 0;
  for(int i = r - 1; i >= l; --i){
    sum += a[i];
    right_ans = max(right_ans, sum);
  }

  return {sum, ans, left_ans, right_ans};
}

void Swap(int k, int bit){
  int l = k * BLOCK_SIZE, r = l + BLOCK_SIZE, bit_mask = (1 << bit);
  for(int i = l; i < r; ++i){
    if((i & bit_mask) == 0){
      continue;
    }
    swap(a[i], a[(i ^ bit_mask)]);
  }
}

void Swap(int bit){
  int bit_mask = (1 << bit);
  for(int i = 0; i < BLOCK_SIZE; ++i){
    if((i & bit_mask) == 0){
      continue;
    }
    dp[i].swap(dp[(i ^ bit_mask)]);
  }
}

void PreProcess(int k, int bit, int mask){
  if(bit == -1){
    dp[k][mask] = Calculate(k);
    return;
  }

  PreProcess(k, bit - 1, 2 * mask);

  Swap(k, bit);
  PreProcess(k, bit - 1, 2 * mask + 1);

  Swap(k, bit);
}

void PreProcess(int k){
  PreProcess(k, B - 1, 0);
}

void PreProcess(){
  for(int k = 0; k < BLOCK_SIZE; ++k){
    PreProcess(k); 
  }
}

ll Query(int mask){
  ll s = 0, qans = 0;
  for(int k = 0; k < BLOCK_SIZE; ++k){
    block_data d = dp[k][mask];
    qans = max(qans, d.ans);
    qans = max(qans, s + d.left_ans);
    s = max(s + d.sum, d.right_ans);
  }
  return qans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < (1 << n); ++i){
    scanf("%d", &a[i]);
  }

  PreProcess();

  int q;
  scanf("%d", &q);

  int mask = 0;
  while(q--){
    int m;
    scanf("%d", &m);

    if(m >= B){
      m -= B;
      Swap(m);
    }
    else{
      mask ^= (1 << m);
    }

    printf("%lld\n", Query(mask));
  }
  return 0;
}