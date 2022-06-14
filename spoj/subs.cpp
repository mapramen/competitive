#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(string& A, string& B, int k){
  int m = B.size(), i = 0;

  for(char c: A){
    int kx = k;
    for( ; kx != 0 && i != m; ++i){
      if(B[i] != c){
        continue;
      }
      --kx;
    }

    if(kx != 0){
      return false;
    }
  }

  return true;
}

int BinarySearch(string& A, string& B){
  int x = 1, y = B.size() / A.size(), ans = 0;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(A, B, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

int Solve(){
  string a, b;
  cin >> a >> b;
  return BinarySearch(a, b);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}