#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

priority_queue<int> A, B;

int Characterize(int n){
  for( ; n != 0 && n % 2 == 0; n /= 2);
  return n;
}

void ReadArray(int n, priority_queue<int>& Q){
  for( ; !Q.empty(); Q.pop());

  while(n--){
    int x;
    scanf("%d", &x);
    Q.push(Characterize(x));
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);

  ReadArray(n, A);
  ReadArray(n, B);

  while(!A.empty() && !B.empty()){
    if(A.top() == B.top()){
      A.pop(), B.pop();
      continue;
    }

    if(B.top() == 0){
      return false;
    }

    B.push(Characterize(B.top() / 2));
    B.pop();
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}