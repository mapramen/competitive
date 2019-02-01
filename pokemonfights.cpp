#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n, BLOCK_SIZE, NUM_BLOCKS;
int A1[N], B1[N], A2[N], B2[N];
ll C1[N], C2[N];

void InitialiseBlockSize(){
  BLOCK_SIZE = 320;
  NUM_BLOCKS = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
}

void ProcessBlock(int i){
  int start = ((i + BLOCK_SIZE - 1) / BLOCK_SIZE - 1) * BLOCK_SIZE + 1;
  int finish = min(n, start + BLOCK_SIZE - 1);

  for(int i = start; i <= finish; ++i){
    B1[i] = A1[i];
    B2[i] = A2[i];
  }

  sort(B1 + start, B1 + finish + 1);
  sort(B2 + start, B2 + finish + 1);

  C1[start] = B1[start], C2[start] = B2[start];
  for(int i = start + 1; i <= finish; ++i){
    C1[i] = B1[i] + C1[i - 1];
    C2[i] = B2[i] + C2[i - 1];
  }
}

void PreProcess(){
  InitialiseBlockSize();

  for(int i = 1; i <= n; ++i){
    int x = A1[i], y = A2[i];
    A1[i] = x + y, A2[i] = x - y;
  }

  for(int start = 1; start <= n; start += BLOCK_SIZE)
    ProcessBlock(start);
}

void Update(int i, int x, int y){
  A1[i] = x + y, A2[i] = x - y;
  ProcessBlock(i);
}

int LowerBound(int *B, int x, int y, int val){
  int z = x - 2;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(B[mid] < val)
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z + 1;
}

ll QueryBlock(int blockNo, int x, int y){
  int start = (blockNo - 1) * BLOCK_SIZE + 1;
  int finish = min(n, start + BLOCK_SIZE - 1);
  ll ans = 0;

  int k = LowerBound(B1, start, finish, x);

  if(k <= start)
    ans += C1[finish] - 1ll * (finish - start + 1) * x;
  else if(k > finish)
    ans += 1ll * (finish - start + 1) * x - C1[finish];
  else
    ans += C1[finish] - 2 * C1[k - 1] + 1ll * (2 * k - start - finish - 1) * x;

  k = LowerBound(B2, start, finish, y);

  if(k <= start)
    ans += C2[finish] - 1ll * (finish - start + 1) * y;
  else if(k > finish)
    ans += 1ll * (finish - start + 1) * y - C2[finish];
  else
    ans += C2[finish] - 2 * C2[k - 1] + 1ll * (2 * k - start - finish - 1) * y;

  return ans;
}

ll QueryInBlock(int l, int r, int x, int y){
  ll ans = 0;
  for(int i = l; i <= r; ++i)
    ans += abs(0ll + A1[i] - x) + abs(0ll + A2[i] - y);
  return ans;
}

ll Query(int l, int r, int x, int y){
  int lBlockNo = (l + BLOCK_SIZE - 1) / BLOCK_SIZE, rBlockNo = (r + BLOCK_SIZE - 1) / BLOCK_SIZE;
  ll ans = 0;

  x += y, y = x - y - y;

  for(int k = lBlockNo + 1; k < rBlockNo; ++k)
    ans += QueryBlock(k, x, y);

  if(lBlockNo == rBlockNo)
    ans += QueryInBlock(l, r, x, y);
  else{
    ans += QueryInBlock(l, min(n, lBlockNo * BLOCK_SIZE), x, y);
    ans += QueryInBlock((rBlockNo - 1) * BLOCK_SIZE + 1, r, x, y);
  }

  return ans;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &A1[i], &A2[i]);

  PreProcess();

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 0){
      int i, x, y;
      scanf("%d%d%d", &i, &x, &y);
      Update(i, x, y);
    }
    else{
      int l, r, x, y;
      scanf("%d%d%d%d", &l, &r, &x, &y);
      printf("%lld\n", Query(l, r, x, y) / 2);
    }
  }

  return 0;
}
