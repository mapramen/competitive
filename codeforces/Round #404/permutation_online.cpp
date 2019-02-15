#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define BLOCK_SIZE 450
#define N BLOCK_SIZE * BLOCK_SIZE

vector<int> a(N), b(N);

int GetBlockNo(int i){
  return i / BLOCK_SIZE;
}

void UpdateBlock(int blockNo){
  int l = blockNo * BLOCK_SIZE, r = l + BLOCK_SIZE;
  for(int i = l; i < r; i++)
    b[i] = a[i];
  sort(b.begin() + l, b.begin() + r);
}

int Query(int i){
  int blockNo = GetBlockNo(i), lowerCnt = 0;

  for(int currentBlockNo = 0; currentBlockNo < blockNo; currentBlockNo++){
    int l = currentBlockNo * BLOCK_SIZE, r = l + BLOCK_SIZE;
    lowerCnt += (lower_bound(b.begin() + l, b.begin() + r, a[i]) - b.begin() - l);
  }

  for(int j = blockNo * BLOCK_SIZE; j < i; j++)
    lowerCnt += (a[j] < a[i]);

  return (a[i] - 1 - lowerCnt) + (i - lowerCnt);
}

int Update(int i, int j){
  if(i > j)
    swap(i, j);
    
  int invCntChange = - (Query(i) + Query(j));

  swap(a[i], a[j]);
  UpdateBlock(GetBlockNo(i));
  UpdateBlock(GetBlockNo(j));

  invCntChange += (Query(i) + Query(j));
  invCntChange += ((a[i] < a[j]) - (a[i] > a[j]));

  return invCntChange;
}

int main(){
  int n, q;
  ll invCnt = 0;

  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; i++)
    a[i] = b[i] = i + 1;

  for(int i = n; i < N; i++)
    a[i] = b[i] = n + 1;

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    invCnt += Update(l, r);
    printf("%lld\n", invCnt);
  }

  return 0;
}
