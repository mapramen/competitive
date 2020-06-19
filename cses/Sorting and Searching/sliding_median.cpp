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
multiset<int> smallerHalf, largerHalf;
 
void Fix(){
  int d = ((int)smallerHalf.size()) - largerHalf.size();
 
  if(d < 0){
    int x = *largerHalf.begin();
    smallerHalf.insert(x);
    largerHalf.erase(largerHalf.begin());
  }
  else if(d > 1){
    int x = *smallerHalf.rbegin();
    largerHalf.insert(x);
    smallerHalf.erase(prev(smallerHalf.end()));
  }
 
  if(!smallerHalf.empty() && !largerHalf.empty() && *largerHalf.begin() < *smallerHalf.rbegin()){
    int x = *smallerHalf.rbegin(), y = *largerHalf.begin();
    smallerHalf.erase(prev(smallerHalf.end())), largerHalf.erase(largerHalf.begin());
    smallerHalf.insert(y), largerHalf.insert(x);
  }
}
 
void Add(int x){
  smallerHalf.insert(x);
  Fix();
}
 
void Remove(int x){
  if(x <= *smallerHalf.rbegin()){
    smallerHalf.erase(smallerHalf.find(x));
  }
  else{
    largerHalf.erase(largerHalf.find(x));
  }
  Fix();
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
    printf("%d ", *smallerHalf.rbegin());
    Remove(a[j]);
  }
  printf("\n");
 
  return 0;
}