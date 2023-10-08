#include <bits/stdc++.h>

using namespace std;

#define START_YEAR 1970
#define END_YEAR 2031

const uint64_t MOD = 4000000007;
mt19937 rnd(random_device{}());
uniform_int_distribution<uint64_t> dis(1, MOD - 1);

uint64_t ModularExponentation(uint64_t a, uint64_t n, uint64_t mod) {
  uint64_t ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
  }
  return ans % mod;
}

bool IsResidue(uint64_t n, uint64_t p) {
  return ModularExponentation(n, (p - 1) / 2, p) == 1;
}

uint64_t GetNonResidue(uint64_t p) {
  uint64_t n = dis(rnd);
  while (IsResidue(n, p)) {
    n = dis(rnd);
  }
  return n;
}

uint64_t TonelliShanks(uint64_t n, uint64_t p) {
  uint64_t S = 0, Q = p - 1;
  while (Q % 2 == 0) {
    Q /= 2;
    ++S;
  }

  uint64_t z = GetNonResidue(p);

  uint64_t M = S;
  uint64_t c = ModularExponentation(z, Q, p);
  uint64_t t = ModularExponentation(n, Q, p);
  uint64_t R = ModularExponentation(n, (Q + 1) / 2, p);

  while (true) {
    if (t == 0) {
      return 0;
    }

    if (t == 1) {
      return R;
    }

    uint64_t i = 0;
    uint64_t x = t;
    while (x != 1 && i < M - 1) {
      x = (x * x) % p;
      ++i;
    }

    if (i == M) {
      break;
    }

    uint64_t b = ModularExponentation(c, 1ull << (M - i - 1), p);
    M = i;
    c = (b * b) % p;
    t = (t * c) % p;
    R = (R * b) % p;
  }

  return -1;
}

bool IsLeapYear(uint64_t year) {
  if (year % 4 == 0 && year % 100 != 0) {
    return true;
  }
  if (year % 400 == 0) {
    return true;
  }
  return false;
}

uint64_t GetDaysInAYear(uint64_t year) {
  if (IsLeapYear(year)) {
    return 366;
  }
  return 365;
}

uint64_t GetDaysInAMonth(uint64_t month, uint64_t year) {
  if (month == 2) {
    if (IsLeapYear(year)) {
      return 29;
    }
    return 28;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  }
  return 31;
}

uint64_t GetSecondsInADay() {
  return 24 * 60 * 60;
}

bool IsWithinTimeRange(uint64_t total_seconds) {
  for (uint64_t year = START_YEAR; year < END_YEAR; ++year) {
    uint64_t days = GetDaysInAYear(year);
    if (total_seconds < days * GetSecondsInADay()) {
      return true;
    }
    total_seconds -= days * GetSecondsInADay();
  }
  return false;
}

string GetDayOfWeekString(uint64_t day, uint64_t month, uint64_t year) {
  // 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday
  int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

  year -= month < 3;
  int res = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

  switch (res) {
    case 0:
      return "Sun";
    case 1:
      return "Mon";
    case 2:
      return "Tue";
    case 3:
      return "Wed";
    case 4:
      return "Thu";
    case 5:
      return "Fri";
    case 6:
      return "Sat";
  }

  return "";
}

string GetMonthOfYearString(uint64_t month) {
  switch (month) {
    case 1:
      return "Jan";
    case 2:
      return "Feb";
    case 3:
      return "Mar";
    case 4:
      return "Apr";
    case 5:
      return "May";
    case 6:
      return "Jun";
    case 7:
      return "Jul";
    case 8:
      return "Aug";
    case 9:
      return "Sep";
    case 10:
      return "Oct";
    case 11:
      return "Nov";
    case 12:
      return "Dec";
  }
  return "";
}

int main() {
  uint64_t n;
  cin >> n;

  uint64_t total_seconds = TonelliShanks(n, MOD);
  if (!IsWithinTimeRange(total_seconds)) {
    total_seconds = (MOD - total_seconds) % MOD;
  }

  uint64_t seconds = total_seconds % 60;

  uint64_t total_minutes = total_seconds / 60;
  uint64_t minutes = total_minutes % 60;

  uint64_t total_hours = total_minutes / 60;
  uint64_t hours = total_hours % 24;

  uint64_t total_days = total_hours / 24 + 1;

  uint64_t year = START_YEAR;
  while (true) {
    uint64_t days_in_year = GetDaysInAYear(year);
    if (total_days <= days_in_year) {
      break;
    }
    total_days -= days_in_year;
    ++year;
  }

  uint64_t month = 1;
  while (true) {
    uint64_t days_in_month = GetDaysInAMonth(month, year);
    if (total_days <= days_in_month) {
      break;
    }
    total_days -= days_in_month;
    ++month;
  }

  printf("%s %s %lu %02lu:%02lu:%02lu %lu\n", GetDayOfWeekString(total_days, month, year).c_str(), GetMonthOfYearString(month).c_str(), total_days, hours, minutes, seconds, year);

  return 0;
}