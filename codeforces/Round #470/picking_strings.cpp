#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char S[N], T[N], ans[N];
int A[N], B[N], R1[N], R2[N];

void ProcessString(char S[], int A[], int R[]){
  int n = strlen(S);
  for(int i = 1; i <= n; ++i){
    A[i] = A[i - 1] + (S[i - 1] != 'A');
    R[i] = S[i - 1] == 'A' ? 1 + R[i - 1] : 0;
  }
}

void PrintString(char S[], int x, int y){
  for(int i = x - 1; i < y; ++i)
    putchar(S[i]);
}

int main(){
  scanf("%s%s", S, T);

  ProcessString(S, A, R1);
  ProcessString(T, B, R2);

  for(int i = 0; i < N; ++i)
    ans[i] = '\0';

  int q, k = 0;
  scanf("%d", &q);
  while(q--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int l1 = y1 - x1 + 1, l2 = y2 - x2 + 1, a = min(R1[y1], l1), b = min(R2[y2], l2), c = A[y1] - A[x1 - 1], d = B[y2] - B[x2 - 1] - A[y1] + A[x1 - 1];

    int f = 0;
    f += (a >= b && a == l1 && b == l2 && (a - b) % 3 == 0);
    f += (a >= b && (a - b) % 3 == 0 && c > 0 && d >= 0 && d % 2 == 0);
    f += (a > b && d >= 2 && d % 2 == 0);

    ans[k] = '0' + (f != 0);

    ++k;
  }

  printf("%s\n", ans);

  return 0;
}
