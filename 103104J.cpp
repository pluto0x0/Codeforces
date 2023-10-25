#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll xa, ya, xb, yb, xc, yc;

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}

void test_l(ll l) {
    for (ll a = 1; a * a < l; a++) {
        ll b_ = ll(sqrt(l - a * a));
        if (a * a + b_ * b_ == l) {
            for (ll b = -b_; b != b_; b = b_) {
                ll Xb = a * xb + b * yb, Yb = -b * xb + a * yb;
                ll Xc = a * xc + b * yc, Yc = -b * xc + a * yc;
                if (Xb % l == 0 && Yb % l == 0 && Xc % l == 0 && Yc % l == 0) {
                    printf("0 0 %lld %lld %lld %lld\n", Xb / l, Yb / l, Xc / l, Yc / l);
                    return;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        xb -= xa, xc -= xa;
        yb -= ya, yc -= ya;
        ll lb = xb * xb + yb * yb, lc = xc * xc + yc * yc,
           la = (xb - xc) * (xb - xc) + (yb - yc) * (yb - yc);
        ll lgcd = gcd(gcd(lb, lc), la);
        test_l(lgcd);
    }
    return 0;
}