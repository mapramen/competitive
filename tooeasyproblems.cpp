#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], t[N];

bool cmpV(int i, int j){
  return (t[i] < t[j] || (t[i] == t[j] && a[i] > a[j]));
}

class cmpQ {
  public:
    cmpQ(){};
    bool operator() (const int& i, const int& j) const {
      return !(a[i] < a[j] || (a[i] == a[j] && t[i] > t[j]));
    }
};

int main(){
  int n, T;
  vector<int> V;
  priority_queue<int, vector<int>, cmpQ> Q;

  scanf("%d%d", &n, &T);

  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i], &t[i]);

  for(int i = 1; i <= n; ++i)
    V.PB(i);

  sort(V.begin(), V.end(), cmpV);

  for(auto i : V){
    if(t[i] > T)
      break;
    T -= t[i];
    Q.push(i);
    if(Q.size() > a[Q.top()]){
      T += t[Q.top()];
      Q.pop();
    }
  }

  printf("%lu\n%lu\n", Q.size(), Q.size());
  while(!Q.empty()){
    printf("%d ", Q.top());
    Q.pop();
  }
  printf("\n");

  return 0;
}
