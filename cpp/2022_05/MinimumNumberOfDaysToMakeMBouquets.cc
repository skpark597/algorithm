/** 1482. Minimum Number of Days to Make m Bouquets */
/*  You are given an integer array bloomDay, an integer m and an integer k.
 *  You want to make m bouquets. To make a bouquet, you need to use k adjacent
 *  flowers from the garden.
 *  The garden consists of n flowers, the ith flower will bloom in the
 *  bloomDay[i]
 *  and then can be used in exactly one bouquet.
 *  Return the minimum number of days you need to wait to be able to make m
 *  bouquets
 *  from the garden. If it is impossible to make m bouquets return -1.
 *
 *  Example 1:
 *  Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 *  Output: 3
 *  Explanation: Let us see what happened in the first three days. x means
flower
 *  bloomed and _ means flower did not bloom in the garden. We need 3 bouquets
each
 *  should contain 1 flower. After day 1: [x, _, _, _, _]   // we can only make
one
 *  bouquet. After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After
 *  day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
 *
 *  Example 2:
 *  Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
 *  Output: -1
 *  Explanation: We need 3 bouquets each has 2 flowers, that means we need 6
 *  flowers. We only have 5 flowers so it is impossible to get the needed
bouquets
 *  and we return -1.
 *
 *  Example 3:
 *  Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
 *  Output: 12
 *  Explanation: We need 2 bouquets each should have 3 flowers.
 *  Here is the garden after the 7 and 12 days:
 *  After day 7: [x, x, x, x, _, x, x]
 *  We can make one bouquet of the first three flowers that bloomed. We cannot
make
 *  another bouquet from the last three flowers that bloomed because they are
not
 *  adjacent. After day 12: [x, x, x, x, x, x, x] It is obvious that we can make
two
 *  bouquets in different ways.
 *
 * Constraints:
 * bloomDay.length == n
 * 1 <= n <= 10^5
 * 1 <= bloomDay[i] <= 10^9
 * 1 <= m <= 10^6
 * 1 <= k <= n */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long getBouquetCount(vector<int> &bloomDays, int m, int k, int day) {
  long long totalBloom = 0;
  long long bloom = 0;

  for (long long bloomDay : bloomDays) {
    if (bloomDay <= day) {
      bloom++;
    } else {
      totalBloom += bloom / k;
      bloom = 0;
    }
  }

  totalBloom += bloom / k;
  return totalBloom;
}

int minDays(vector<int> &bloomDays, int m, int k) {
  if (m * k > bloomDays.size()) {
    return -1;
  }

  long long left = 1;
  long long right = *max_element(bloomDays.begin(), bloomDays.end());

  while (left <= right) {
    long long middle = left + (right - left) / 2;
    long long boquetCount = getBouquetCount(bloomDays, m, k, middle);

    if (boquetCount >= m) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return left;
}

int main() {
  vector<int> bloomDay0{1, 10, 3, 10, 2};
  int m0 = 3;
  int k0 = 1;

  vector<int> bloomDay1{1, 10, 3, 10, 2};
  int m1 = 3;
  int k1 = 2;

  vector<int> bloomDay2{7, 7, 7, 7, 12, 7, 7};
  int m2 = 2;
  int k2 = 3;

  int ans0 = minDays(bloomDay0, m0, k0);
  int ans1 = minDays(bloomDay1, m1, k1);
  int ans2 = minDays(bloomDay2, m2, k2);

  cout << ans0 << endl; // 3
  cout << ans1 << endl; // -1
  cout << ans2 << endl; // 12

  return 0;
}