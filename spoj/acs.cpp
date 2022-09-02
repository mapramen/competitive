#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1234
#define M 5678

int r[N], invr[N], c[M], invc[M];

void Swap(int a[], int inva[], int i, int j){
  swap(a[i], a[j]);
  swap(inva[a[i]], inva[a[j]]);
}

int main(){
  iota(r, r + N, 0);
  iota(invr, invr + N, 0);
  iota(c, c + M, 0);
  iota(invc, invc + M, 0);

  for(char op; scanf("%c", &op) != EOF; op = getchar()){
    if(op == 'W'){
      int z;
      scanf("%d", &z);
      --z;
      printf("%d %d\n", invr[z / M] + 1, invc[z % M] + 1);
      continue;
    }

    int i, j;
    scanf("%d%d", &i, &j);
    --i, --j;

    if(op == 'R'){
      Swap(r, invr, i, j);
    }
    else if(op == 'C'){
      Swap(c, invc, i, j);
    }
    else{
      printf("%d\n", M * r[i] + c[j] + 1);
    }
  }

  return 0;
}