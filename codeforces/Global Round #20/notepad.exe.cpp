#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1E9

void Print(char c, int x){
  printf("%c %d\n", c, x);
  fflush(stdout);
}

int Query(int x){
  Print('?', x);

  int h;
  scanf("%d", &h);
  return h;
}

void PrintAns(int ans){
  Print('!', ans);
}

int BinarySearch(){
  int x = 1, y = 1E9, ans = y;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query(mid) == 1){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  int S = BinarySearch();
  int ans = S;

  for(int h = 2; h <= n; ++h){
    int w = S / h;
    int qh = Query(w);

    if(qh == 0){
      break;
    }

    ans = min(ans, w * qh);
  }

  PrintAns(ans);

  return 0;
}