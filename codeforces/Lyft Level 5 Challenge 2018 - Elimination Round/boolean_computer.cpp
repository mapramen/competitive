#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N2 4096
#define N3 531441
#define M 12

int m, pow3[M], base2ToBase3[N2], mostSignificant2Bit[N3], C[N2], D[N3], zeroTargetBit[2][256], targetBit[M][2];
char s[M + 1];

void FillMostSignificant2Bit(int i, int n, int b = -1){
  if(i == M){
    mostSignificant2Bit[n] = b;
    return ;
  }
  for(int j = 0; j < 3; ++j){
    FillMostSignificant2Bit(i + 1, n + j * pow3[i], (j == 2) ? i : b);
  }
}

void FillZeroTargetBit(){
  zeroTargetBit[0]['A'] = 2;
  zeroTargetBit[0]['O'] = 0;
  zeroTargetBit[0]['X'] = 0;
  zeroTargetBit[0]['a'] = -1;
  zeroTargetBit[0]['o'] = 1;
  zeroTargetBit[0]['x'] = 1;

  zeroTargetBit[1]['A'] = 0;
  zeroTargetBit[1]['O'] = -1;
  zeroTargetBit[1]['X'] = 1;
  zeroTargetBit[1]['a'] = 1;
  zeroTargetBit[1]['o'] = 2;
  zeroTargetBit[1]['x'] = 0;
}

void PreProcess(){
  for(int i = 1; i < N2; ++i){
    base2ToBase3[i] = 3 * base2ToBase3[(i / 2)] + (i % 2);
  }

  for(int i = 0; i < N2; ++i){
    D[base2ToBase3[i]] = C[i];
  }

  pow3[0] = 1;
  for(int i = 1; i < M; ++i){
    pow3[i] = (3 * pow3[i - 1]);
  }

  FillMostSignificant2Bit(0, 0);
  FillZeroTargetBit();

  for(int i = 0; i < N3; ++i){
    if(mostSignificant2Bit[i] < 0){
      continue;
    }
    int x = pow3[mostSignificant2Bit[i]];
    D[i] = (D[i - 2 * x] + D[i - x]);
  }
}

void FillTargetBit(){
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < 2; ++j){
      targetBit[i][j] = zeroTargetBit[j][s[m - i - 1]];
    }
  }
}

int GetTarget3BitNumber(int n){
  int ans = 0;
  for(int i = 0; i < m; ++i, n /= 2){
    int j = targetBit[i][(n % 2)];
    if(j < 0){
      return -1;
    }
    ans += (j * pow3[i]);
  }
  return ans;
}

int main(){
  int n, q;

  scanf("%d%d%d", &m, &n, &q);

  while(n--){
    int x;
    scanf("%d", &x);
    ++C[x];
  }

  PreProcess();

  while(q--){
    scanf("%s", s);
    FillTargetBit();

    int ans = 0;
    for(int i = 0; i < N2; ++i){
      if(C[i] == 0){
        continue;
      }
      int j = GetTarget3BitNumber(i);
      if(j < 0 || D[j] == 0){
        continue;
      }
      ans += (C[i] * D[j]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
