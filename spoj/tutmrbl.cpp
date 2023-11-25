#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10000001

int least_prime_divisor[N];

void Initialize() {
  for (int i = 1; i < N; ++i) {
    least_prime_divisor[i] = i;
  }

  for (int i = 2; i * i < N; ++i) {
    if (least_prime_divisor[i] != i) {
      continue;
    }

    for (int j = i * i; j < N; j += i) {
      if (least_prime_divisor[j] == j) {
        least_prime_divisor[j] = i;
      }
    }
  }
}

int GetDivisorsCount(vector<int>& prime_divisors) {
  int number_of_divisors = 1;
  for (int i = 0; i < prime_divisors.size(); ++i) {
    int cnt = 1;
    while (i + 1 < prime_divisors.size() && prime_divisors[i] == prime_divisors[i + 1]) {
      ++cnt, ++i;
    }
    number_of_divisors *= (cnt + 1);
  }
  return number_of_divisors;
}

int main() {
  Initialize();

  while (true) {
    int n;
    scanf("%d", &n);

    if (n == 0) {
      break;
    }

    vector<int> prime_divisors;
    for (int i = n; i > 1; i /= least_prime_divisor[i]) {
      prime_divisors.push_back(least_prime_divisor[i]);
    }

    printf("%d =", n);
    for (int i = 0; i < prime_divisors.size(); ++i) {
      if (i) {
        printf(" *");
      }
      printf(" %d", prime_divisors[i]);
    }
    printf("\n");

    printf("With %d marbles, %d different rectangles can be constructed.\n", n, (GetDivisorsCount(prime_divisors) + 1) / 2);
  }

  return 0;
}