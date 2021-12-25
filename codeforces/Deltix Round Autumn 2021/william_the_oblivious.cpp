#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)

char s[N];
char ch[2];

int T[M][3][3];

void InitialiseNode(int A[3][3], char c){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      A[i][j] = N;
    }
  }

  if(c == 'a'){
    A[0][0] = 1, A[0][1] = 0, A[1][1] = 0, A[1][2] = 1, A[2][2] = 0;
    return;
  }

  if(c == 'b'){
    A[0][0] = 0, A[0][1] = 1, A[1][1] = 1, A[1][2] = 0, A[2][2] = 0;
  }

  if(c == 'c'){
    A[0][0] = 0, A[0][1] = 1, A[1][1] = 0, A[1][2] = 1, A[2][2] = 1;
  }
}

void Combine(int A[3][3], int B[3][3], int C[3][3]){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      int ans = N;
      for(int k = 0; k < 3; ++k){
        ans = min(ans, A[i][k] + B[k][j]);
      }
      C[i][j] = ans;
    }
  }
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    InitialiseNode(T[k], s[l - 1]);
  }
  else{
    int mid = l + (r - l) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
    Combine(T[2 * k + 1], T[2 * k + 2], T[k]);
  }
}

void Update(int k, int l, int r, int i, char c){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    InitialiseNode(T[k], c);
    return;
  }

  int mid = l + (r - l) / 2;
  Update(2 * k + 1, l, mid, i, c);
  Update(2 * k + 2, mid + 1, r, i, c);
  Combine(T[2 * k + 1], T[2 * k + 2], T[k]);
}

int main(){
  int n, q;
  scanf("%d%d%s", &n, &q, s);

  BuildSegmentTree(0, 1, n);

  while(q--){
    int k;
    scanf("%d%s", &k, ch);

    Update(0, 1, n, k, ch[0]);

    int ans = INT_MAX;
    for(int j = 0; j < 3; ++j){
      ans = min(ans, T[0][0][j]);
    }

    printf("%d\n", ans);
  }

  return 0;
}