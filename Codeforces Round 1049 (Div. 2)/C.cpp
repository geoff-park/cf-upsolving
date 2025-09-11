/* Editorial

Note that if Bob chooses two indices l,r on his turn,
then Alice can also choose the same indices l,r on her next turn
and this will increase the value of f(a) ultimately.
-> optimal for Bob to end the game on his first turn.

Now there are two possibilities:
  1. Alice can end the game on her first turn. ->  finding f(a) is trivial.
  2. Alice can choose two indices and Bob ends the game.

There are only two types of swaps between even index values and odd index values:
  1. swap e,e or o,o -> only cost increases by absolute difference in index
  2. swap e,o or o,e -> the total change is "abs(i - j) + 2 * (a[i] - a[j])" where i % 2 == 0 and j % 2 == 1
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2)
        ans -= a[i];
      else
        ans += a[i];
    }

    ll init = ans;

    // 짝짝, 홀홀 교환 고려 (인덱스 차이만 보기 때문에, 1-based index -> 0-based index 변환 상관없음)
    for (int i = 0; i < n; ++i) ans = max(ans, init + i - (i % 2));
    // 0 - 0
    // 1 - 1
    // 2 - 0
    // 3 - 1

    // using "prefix minimum": “지금까지 본 값 중에서 가장 작은 것”을 계속 들고 다니자 -> O(n)

    // delta = abs(e - o) + 2 * (a[o] - a[e])

    // 1. even < odd
    // delta = (o + 2 * a[o]) - (e + 2 * a[e])
    // 홀수 스캔 시, 왼쪽 짝수에 대하여 (e + e * a[e])의 최솟값을 기억

    // 2. odd < even
    // delta = (e - 2 * a[e]) - (o - 2 * a[o])
    // 짝수 스캔 시, 왼쪽 홀수에 대하여 (o - 2 * a[o])의 최솟값을 기억

    ll min_even = LLONG_MAX / 2;
    ll min_odd = LLONG_MAX / 2;

    for (int i = 0; i < n; ++i) {
      if (i % 2 == 1) {  // i is odd
        ans = max(ans, init + i + 2 * a[i] - min_even);
        min_odd = min(min_odd, i - 2 * a[i]);
      } else {  // i is even
        ans = max(ans, init + i - 2 * a[i] - min_odd);
        min_even = min(min_even, i + 2 * a[i]);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
