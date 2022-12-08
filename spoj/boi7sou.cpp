#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int A[N];
deque<int> Q1, Q2;

void AddToMinSlidingWindow(int k, int i){
  int x = A[i];
  while(!Q1.empty() && A[Q1.back()] >= x){
    Q1.pop_back();
  }

  while(!Q1.empty() && i - Q1.front() >= k){
    Q1.pop_front();
  }

  Q1.push_back(i);
}

void AddToMaxSlidingWindow(int k, int i){
  int x = A[i];
  while(!Q2.empty() && A[Q2.back()] <= x){
    Q2.pop_back();
  }

  while(!Q2.empty() && i - Q2.front() >= k){
    Q2.pop_front();
  }

  Q2.push_back(i);
}

int main(){
  int n, m, c;
  scanf("%d%d%d", &n, &m, &c);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &A[i]);
  }

  bool found = false;
  for(int i = 1; i <= n; ++i){
    AddToMinSlidingWindow(m, i);
    AddToMaxSlidingWindow(m, i);

    if(i >= m && A[Q2.front()] - A[Q1.front()] <= c){
      printf("%d\n", i - m + 1);
      found = true;
    }
  }

  if(!found){
    printf("NONE\n");
  }

  return 0;
}