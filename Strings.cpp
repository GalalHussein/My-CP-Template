namespace segTree_Hashing {
/*
  Based zero
  [L: R] Included
  double hashing

  ** Palindrome check -> hash s and hash reversed s
     then check hash s[l, r] == hash reversed s [n - r - 1, n - l - 1]

using ll = long long;
const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll base = 31;

struct Node {
    ll h1, h2; int len;
    Node(ll _h1=0, ll _h2=0, int _len=0) {
        h1 = _h1, h2 = _h2, len = _len;
    }
};

struct SegTreeHashing {
    int n;
    string s;
    vector<Node> seg;
    vector<ll> pow1, pow2;

    SegTreeHashing(string _s) {
        s = _s;
        n = s.size();
        seg.resize(4*n);
        pow1.resize(n+1);
        pow2.resize(n+1);

        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i-1] * base) % mod1;
            pow2[i] = (pow2[i-1] * base) % mod2;
        }
        build(1, 0, n-1);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.len = left.len + right.len;

        res.h1 = (left.h1 + right.h1 * pow1[left.len] % mod1) % mod1;
        res.h2 = (left.h2 + right.h2 * pow2[left.len] % mod2) % mod2;

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = Node(s[l], s[l], 1);
            return;
        }

        int mid = (l + r) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);

        seg[node] = merge(seg[node*2], seg[node*2+1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            seg[node] = Node(c, c, 1);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node*2, l, mid, pos, c);
        else
            update(node*2+1, mid+1, r, pos, c);

        seg[node] = merge(seg[node*2], seg[node*2+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return Node();

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        Node left = query(node*2, l, mid, ql, qr);
        Node right = query(node*2+1, mid+1, r, ql, qr);

        return merge(left, right);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, char c) {
        update(1, 0, n-1, pos, c);
    }
};
*/
}
namespace  Lazy_segTree_hashing {
//
// const int N = 1e5 + 5, bs1 = 17, mod = 1e9 + 7;
//
// int mul(int x, int y) {
//     x = ((x % mod) + mod) % mod,
//     y = ((y % mod) + mod) % mod;
//     return (x * y * 1LL) % mod;
// }
// int add(int x, int y) {
//     x = ((x % mod) + mod) % mod,
//     y = ((y % mod) + mod) % mod;
//     return (x + y) % mod;
// }
//
// int pw[N];
// vector<int> sumP(N, 0);
//
// void com_sumP () {
//     sumP[0] = 0;
//     pw[0] = 1;
//     for (int i = 1; i < N; ++i) {
//         pw[i] = mul(pw[i - 1], bs1);
//         sumP[i] = add(sumP[i - 1] , pw[i - 1]);
//     }
// }
//
// struct LazySegTreeHashing {
// #define L(x) (2 * x + 1)
// #define R(x) (2 * x + 2)
// #define ll long long
//
//     int size = 1;
//     struct node {
//         int hash_value, sz;
//     };
//     vector<node> tree; vector<int> lazy;
//     LazySegTreeHashing(int n) {
//         while (size < n) size <<= 1;
//         tree.assign(4 * size, {0, 0});
//         lazy.assign(4 * size, -1);
//
//         int leaf_start = size - 1;
//         for (int i = leaf_start; i <= 2 * size - 2; ++i) {
//             int idx = i - leaf_start;
//             tree[i].sz = (idx < n) ? 1 : 0;
//         }
//         for (int i = leaf_start - 1; i >= 0; --i) {
//             tree[i].sz = tree[L(i)].sz + tree[R(i)].sz;
//         }
//     }
//
//     void relax (int x, int lx, int rx) {
//         if (lazy[x] == -1) return;
//         tree[x].hash_value = mul(lazy[x] , (sumP[tree[x].sz]));
//         if (rx - lx > 1) {
//             lazy[L(x)] = lazy[x];
//             lazy[R(x)] = lazy[x];
//         }
//         lazy[x] = -1;
//     }
//     int operation(int x) {
//         return add(tree[L(x)].hash_value, mul(tree[R(x)].hash_value , pw[tree[L(x)].sz]));
//     }
//     void update(int l, int r, ll v, int x, int lx, int rx) {
//         relax(x, lx, rx);
//         if (l >= rx || r <= lx) return;
//         if (l <= lx && rx <= r) {
//             lazy[x] = v;
//             relax(x, lx, rx);
//             return;
//         }
//         update(l, r, v, L(x), lx, (lx + rx) / 2);
//         update(l, r, v, R(x), (lx + rx) / 2, rx);
//         tree[x].hash_value = operation(x);
//         tree[x].sz = tree[L(x)].sz + tree[R(x)].sz;
//     }
//
//     void query1(int l, int r, ll v) {
//         update(l, r, v, 0, 0, size);
//     }
//
//     ll get_hash(int l, int r, int x, int lx, int rx) {
//         relax(x, lx, rx);
//         if (l >= rx || r <= lx) return 0;
//         if (l <= lx && rx <= r) return tree[x].hash_value;
//         int mid = (lx + rx) / 2;
//         int leftHash = get_hash(l, r, L(x), lx, mid);
//         int rightHash = get_hash(l, r, R(x), mid, rx);
//         int left_len = max(0ll, min(mid, r) - max(l, lx));
//         return add((int)leftHash, mul((int)rightHash, pw[left_len]));
//     }
//     bool query2(int l, int r, int per) {
//         return get_hash(l, r - per, 0, 0, size) == get_hash(l + per, r, 0, 0, size);
//     }
// #undef L
// #undef R
// };

}
namespace hashing {
/* double string hashing
    const int N = 2e5 + 5, bs1 = 31, bs2 = 37, mod = 1e9 + 7;
    int pw1[N], pw2[N], inv1[N], inv2[N];

    int mul(int x, int y) {
        x = ((x % mod) + mod) % mod,
        y = ((y % mod) + mod) % mod;
        return (x * y * 1LL) % mod;
    }
    int add(int x, int y) {
        x = ((x % mod) + mod) % mod,
        y = ((y % mod) + mod) % mod;
        return (x + y) % mod;
    }
    int binpow(int a, int e, int mod = 1e9 + 7) {
        if (!e) return 1;
        a %= mod;
        int res = 1;
        while (e) {
            if (e & 1) res = res * a % mod;
            a = a * a % mod;
            e >>= 1;
        } return res;
    }

    void pre() {
        pw1[0] = 1, pw2[0] = inv1[0] = inv2[0] = 1;
        int invP1 = binpow(bs1, mod - 2);
        int invP2 = binpow(bs2, mod - 2);
        for (int i = 1; i < N; ++i) {
            pw1[i] = mul(pw1[i - 1], bs1);
            pw2[i] = mul(pw2[i - 1], bs2);
            inv1[i] = mul(inv1[i - 1], invP1);
            inv2[i] = mul(inv2[i - 1], invP2);
        }
    }


    struct Hash {
        vector<pair<int, int>> prefix_hash;
        Hash(const string &s) { if (!preCalc) {
            pre(); preCalc = true;
        }
            prefix_hash = vector<pair<int, int>>(s.size(), {0, 0});
            for (int i = 0; i < s.size(); i++) {
                prefix_hash[i].first = mul((s[i] - 'a' + 1), pw1[i]);
                prefix_hash[i].second = mul((s[i] - 'a' + 1), pw2[i]);
                if (i) prefix_hash[i] = {
                    add(prefix_hash[i].first, prefix_hash[i - 1].first),
                    add(prefix_hash[i].second, prefix_hash[i - 1].second),
                };
            }
        }
        pair<int, int> get_hash() {
            return prefix_hash.back();
        }
        pair<int, int> get_range_hash(int l, int r) {
            return {
                mul(add(prefix_hash[r].first, - (l ? prefix_hash[l - 1].first: 0)), inv1[l]),
                mul(add(prefix_hash[r].second, - (l ? prefix_hash[l - 1].second: 0)), inv2[l])
            };
        }
    };
*/
}
namespace Trie {
    // struct TrieNode {
    //     TrieNode* child[26];
    //     int cnt;
    //     int end_cnt;
    //     TrieNode() {
    //         cnt = 0;
    //         end_cnt = 0;
    //         for(int i = 0; i < 26; i++) child[i] = nullptr;
    //     }
    // };
    //
    // struct Trie {
    //     TrieNode* root;
    //     Trie() { root = new TrieNode(); }
    //
    //     // Insert word into trie
    //     void insert(const string &s) {
    //         TrieNode* cur = root;
    //         for(char c : s) {
    //             int idx = c - 'a';
    //             if(!cur->child[idx]) cur->child[idx] = new TrieNode();
    //             cur = cur->child[idx];
    //             cur->cnt++;
    //         }
    //         cur->end_cnt++;
    //     }
    //
    //     bool search(const string &s) {
    //         TrieNode* cur = root;
    //         for(char c : s) {
    //             int idx = c - 'a';
    //             if(!cur->child[idx]) return false;
    //             cur = cur->child[idx];
    //         }
    //         return cur->end_cnt > 0;
    //     }
    //
    //     // Erase a word (decrease counts)
    //     bool erase(const string &s) {
    //         if(!search(s)) return false;
    //         TrieNode* cur = root;
    //         for(char c : s) {
    //             int idx = c - 'a';
    //             TrieNode* nxt = cur->child[idx];
    //             nxt->cnt--;
    //             // Optional: delete node if cnt==0 to save memory
    //             if(nxt->cnt == 0) {
    //                 cur->child[idx] = nullptr;
    //                 delete nxt;
    //                 return true;
    //             }
    //             cur = nxt;
    //         }
    //         cur->end_cnt--;
    //         return true;
    //     }
    // };
}