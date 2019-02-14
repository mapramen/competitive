#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

void PrintOperation1(vector<int>& v){
  while(v.size() > 1){
    int i = v.back();
    v.pop_back();
    printf("1 %d %d\n", i, v.back());
  }
}

int main(){
  int n;
  vector<int> neg, pos, zeros;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    if(a[i] < 0){
      neg.PB(i);
    }
    else if(a[i] > 0){
      pos.PB(i);
    }
    else{
      zeros.PB(i);
    }
  }

  if(neg.size() % 2 == 1){
    int index = -1, m = INT_MIN;
    for(int i = 0; i < neg.size(); ++i){
      if(a[neg[i]] > m){
        m = a[neg[i]];
        index = i;
      }
    }
    zeros.PB(neg[index]);
    neg.erase(neg.begin() + index);
  }

  pos.insert(pos.end(), neg.begin(), neg.end());

  PrintOperation1(pos);
  PrintOperation1(zeros);

  if(pos.size() > 0 && zeros.size() > 0){
    printf("2 %d\n", zeros.back());
  }

  return 0;
}
