#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k;
  queue<int> q;

  cin >> n >> k;

  for(int i = 1; i <= n; i++)
    q.push(i);

  while(k--){
    int a;
    cin >> a;

    a = a % n;
    while(a--){
      q.push(q.front());
      q.pop();
    }

    cout << q.front() << ' ';
    q.pop();
    n--;
  }

  cout << '\n';

  return 0;
}
