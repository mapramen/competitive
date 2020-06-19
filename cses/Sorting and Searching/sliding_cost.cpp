#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
 
int a[N];
multiset<int> smallerHalfSet, largerHalfSet;
ll smallerHalfSum = 0, largerHalfSum = 0;
 
void Fix(){
  int d = ((int)smallerHalfSet.size()) - largerHalfSet.size();
 
  if(d < 0){
    int x = *largerHalfSet.begin();
    smallerHalfSet.insert(x);
    largerHalfSet.erase(largerHalfSet.begin());
    smallerHalfSum += x, largerHalfSum -= x;
  }
  else if(d > 1){
    int x = *smallerHalfSet.rbegin();
    largerHalfSet.insert(x);
    smallerHalfSet.erase(prev(smallerHalfSet.end()));
    smallerHalfSum -= x, largerHalfSum += x;
  }
 
  if(!smallerHalfSet.empty() && !largerHalfSet.empty() && *largerHalfSet.begin() < *smallerHalfSet.rbegin()){
    int x = *smallerHalfSet.rbegin(), y = *largerHalfSet.begin();
    smallerHalfSet.erase(prev(smallerHalfSet.end())), largerHalfSet.erase(largerHalfSet.begin());
    smallerHalfSet.insert(y), largerHalfSet.insert(x);
    smallerHalfSum += (y - x), largerHalfSum += (x - y);
  }
}
 
void Add(int x){
  smallerHalfSet.insert(x);
  smallerHalfSum += x;
  Fix();
}
 
void Remove(int x){
  if(x <= *smallerHalfSet.rbegin()){
    smallerHalfSet.erase(smallerHalfSet.find(x));
    smallerHalfSum -= x;
  }
  else{
    largerHalfSet.erase(largerHalfSet.find(x));
    largerHalfSum -= x;
  }
  Fix();
}

ll Cost(){
  ll x = *smallerHalfSet.rbegin();
  return (smallerHalfSet.size() * x - smallerHalfSum) + (largerHalfSum - x * largerHalfSet.size());
}
 
int main(){
  int n, k;
 
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
 
  for(int i = 1; i < k; ++i){
    Add(a[i]);
  }
 
  for(int i = k, j = 1; i <= n; ++i, ++j){
    Add(a[i]);
    printf("%lld ", Cost());
    Remove(a[j]);
  }
  printf("\n");
 
  return 0;
}