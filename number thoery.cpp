namespace Math {
    // using ll = long long;
    //
    // ll fastPow(ll a, ll e, ll mod) {
    //     ll r = 1 % mod;
    //     a %= mod;
    //     while (e) {
    //         if (e & 1) r = (r * a) % mod;
    //         a = (a * a) % mod;
    //         e >>= 1;
    //     }
    //     return r;
    // }
    //
    // ll eGCD(ll a, ll b, ll &x0, ll &y0) {
    //     auto nxt = [](ll &a, ll &b, ll q) {
    //         ll n = a - q * b;
    //         a = b;
    //         b = n;
    //     };
    //     ll r0 = a, r1 = b;
    //     ll x1, y1;
    //     x1 = y0 = 0;
    //     x0 = y1 = 1;
    //     while (r1) {
    //         ll q = r0 / r1;
    //         nxt(x0, x1, q);
    //         nxt(y0, y1, q);
    //         nxt(r0, r1, q);
    //     }
    //     return r0;
    // }
    //
    // ll invModPrime(ll a, ll mod) {
    //     ll r = 1 % mod;
    //     ll e = mod - 2;
    //     a %= mod;
    //     while (e) {
    //         if (e & 1) r = (r * a) % mod;
    //         a = (a * a) % mod;
    //         e >>= 1;
    //     }
    //     return r;
    // }
    //
    // ll invModGeneral(ll a, ll mod) {
    //     ll x0, y0;
    //     auto eGCD_local = [](ll a, ll b, ll &x0, ll &y0) {
    //         auto nxt = [](ll &a, ll &b, ll q) {
    //             ll n = a - q * b;
    //             a = b;
    //             b = n;
    //         };
    //         ll r0 = a, r1 = b;
    //         ll x1, y1;
    //         x1 = y0 = 0;
    //         x0 = y1 = 1;
    //         while (r1) {
    //             ll q = r0 / r1;
    //             nxt(x0, x1, q);
    //             nxt(y0, y1, q);
    //             nxt(r0, r1, q);
    //         }
    //         return r0;
    //     };
    //
    //     ll g = eGCD_local(a, mod, x0, y0);
    //     if (g != 1) return -1;
    //     x0 %= mod;
    //     if (x0 < 0) x0 += mod;
    //     return x0;
    // }
    //
    // ll lcmMod(ll a, ll b, ll mod) {
    //     ll x0, y0;
    //     auto eGCD_local = [](ll a, ll b, ll &x0, ll &y0) {
    //         auto nxt = [](ll &a, ll &b, ll q) {
    //             ll n = a - q * b;
    //             a = b;
    //             b = n;
    //         };
    //         ll r0 = a, r1 = b;
    //         ll x1, y1;
    //         x1 = y0 = 0;
    //         x0 = y1 = 1;
    //         while (r1) {
    //             ll q = r0 / r1;
    //             nxt(x0, x1, q);
    //             nxt(y0, y1, q);
    //             nxt(r0, r1, q);
    //         }
    //         return r0;
    //     };
    //
    //     ll g = eGCD_local(a, b, x0, y0);
    //     a /= g;
    //     return (a % mod) * (b % mod) % mod;
    // }
}
namespace Combinatorics {
    // using ll = long long;
    //
    // vector<ll> fact, invfact;
    //
    // ll fastPow(ll a, ll e, ll mod) {
    //     ll r = 1 % mod;
    //     a %= mod;
    //     while (e) {
    //         if (e & 1) r = (r * a) % mod;
    //         a = (a * a) % mod;
    //         e >>= 1;
    //     }
    //     return r;
    // }
    //
    // ll invModPrime(ll a, ll mod) {
    //     return fastPow(a, mod - 2, mod);
    // }
    //
    // void initFact(int n, ll mod) {
    //     fact.assign(n + 1, 1);
    //     invfact.assign(n + 1, 1);
    //
    //     for (int i = 1; i <= n; i++)
    //         fact[i] = fact[i - 1] * i % mod;
    //
    //     invfact[n] = invModPrime(fact[n], mod);
    //
    //     for (int i = n; i > 0; i--)
    //         invfact[i - 1] = invfact[i] * i % mod;
    // }
    //
    // ll nCr(int n, int r, ll mod) {
    //     if (r < 0 || r > n) return 0;
    //     return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
    // }
    //
    // ll nPr(int n, int r, ll mod) {
    //     if (r < 0 || r > n) return 0;
    //     return fact[n] * invfact[n - r] % mod;
    // }
}
namespace Sieve {
    // vector<int> primes, spf;
    //
    // void build(int n) {
    //     primes.clear();
    //     spf.assign(n + 1, 0);
    //
    //     for (int i = 2; i <= n; i++) {
    //         if (!spf[i]) {
    //             spf[i] = i;
    //             primes.push_back(i);
    //         }
    //         for (int p : primes) {
    //             if (p > spf[i] || 1LL * i * p > n) break;
    //             spf[i * p] = p;
    //         }
    //     }
    // }
}
namespace Factorization {
    // using ll = long long;
    //
    // vector<pair<ll, int>> trial(ll n) {
    //     vector<pair<ll, int>> res;
    //     for (ll i = 2; i * i <= n; i++) {
    //         if (n % i == 0) {
    //             int c = 0;
    //             while (n % i == 0) {
    //                 n /= i;
    //                 c++;
    //             }
    //             res.push_back({i, c});
    //         }
    //     }
    //     if (n > 1) res.push_back({n, 1});
    //     return res;
    // }
    //
    // vector<pair<int, int>> usingSPF(int n, const vector<int>& spf) {
    //     vector<pair<int, int>> res;
    //     while (n > 1) {
    //         int p = spf[n], c = 0;
    //         while (n % p == 0) {
    //             n /= p;
    //             c++;
    //         }
    //         res.push_back({p, c});
    //     }
    //     return res;
    // }
}
// Add and Multiply string numbers
namespace BigInt {
    // add two large numbers (string + string)
    // string add(string a, string b) {
    //     if (a.size() < b.size()) swap(a, b);
    //     reverse(a.begin(), a.end());
    //     reverse(b.begin(), b.end());
    //
    //     string res;
    //     int carry = 0;
    //
    //     for (int i = 0; i < (int)a.size(); i++) {
    //         int x = a[i] - '0';
    //         int y = (i < (int)b.size() ? b[i] - '0' : 0);
    //         int sum = x + y + carry;
    //         res.push_back((sum % 10) + '0');
    //         carry = sum / 10;
    //     }
    //
    //     if (carry) res.push_back(carry + '0');
    //
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    // multiply large number into int (string * int)
    // string mul(string a, int x) {
    //     reverse(a.begin(), a.end());
    //     string res;
    //     int carry = 0;
    //
    //     for (char c : a) {
    //         int cur = (c - '0') * x + carry;
    //         res.push_back((cur % 10) + '0');
    //         carry = cur / 10;
    //     }
    //
    //     while (carry) {
    //         res.push_back((carry % 10) + '0');
    //         carry /= 10;
    //     }
    //
    //     reverse(res.begin(), res.end());
    //     return res;
    // }
}