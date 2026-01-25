namespace SegTree {
//     struct segTree {
//      #define L(x) (2 * x + 1)
//      #define R(x) (2 * x + 2)
//         int size;
//         const int init = 0ll;
//         vector<int> tree;
//         segTree(int n) {
//             size = 1;
//             while (size < n) size *= 2;
//             tree.assign(2 * size + 100, init);
//         }
//         int merge (int __left, int __right) {
//             return __left + __right;
//         }
//
//         void update (int i, int v, int x, int lx, int rx) {
//             if (rx - lx == 1) {
//                 tree[x] += v;
//                 return;
//             }
//             int mid = (lx + rx) / 2;
//             if (i < mid) {
//                 update (i, v, L(x), lx, mid);
//             } else {
//                 update (i, v, R(x), mid, rx);
//             }
//             tree[x] = merge (tree[L(x)], tree[R(x)]);
//         }
//
//         void update (int i, int v) {
//             if (i < 0 || i >= size) return;
//             update (i, v, 0, 0, size);
//         }
//
//         int query (int l, int r, int x, int lx, int rx) {
//             if (l >= rx or r <= lx) return init;
//             if (lx >= l && rx <= r) return tree[x];
//
//             int mid = (lx + rx) / 2;
//             return merge (query (l, r, L(x), lx, mid),query (l, r, R(x), mid, rx));
//
//         }
//
//         int query (int l, int r) {
//             return query(l, r, 0, 0, size);
//         }
//
//      #undef L
//      #undef R
//     };
}

namespace LazySegTree {
// struct segTree {
// #define L(x) (2 * x + 1)
// #define R(x) (2 * x + 2)
//
//     int size = 1;
//     vector<ll> tree, lazy;
//     explicit segTree(int n) {
//         while (size < n) size <<= 1;
//         tree.assign(2 * size, 0);
//         lazy.assign(2 * size, -1);
//     }
//
//     void relax (int x, int lx, int rx) {
//         if (lazy[x] == -1) return;
//         tree[x] = (lazy[x] * (rx -lx));
//         if (rx - lx > 1) {
//             lazy[L(x)] = lazy[x];
//             lazy[R(x)] = lazy[x];
//         }
//         lazy[x] = -1;
//     }
//
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
//         tree[x] = tree[L(x)] + tree[R(x)];
//     }
//
//     void mult(int l, int r, ll v) {
//         update(l, r, v, 0, 0, size);
//     }
//
//     ll sum(int l, int r, int x, int lx, int rx) {
//         relax(x, lx, rx);
//         if (l >= rx || r <= lx)
//             return 0;
//         if (l <= lx && rx <= r) return tree[x];
//         return sum(l, r, L(x), lx, (lx + rx) / 2) + sum(l, r, R(x), (lx + rx)/2, rx);
//     }
//     ll sum(int l, int r) {
//         return sum(l, r, 0, 0, size);
//     }
// #undef L
// #undef R
// };
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

namespace MergeSortTree {
// 0-index and Not Include R
/*
    struct MergeSortTrees {
        int size;
        vector<vector<ll>> tree;
        explicit MergeSortTrees(const vector<ll>& a) {
            size = a.size();
            tree.resize(4 * size);
            build(0, 0, size, a);
        }
        void build(int x, int lx, int rx, const vector<ll>& a) {
            if (rx - lx == 1) {
                tree[x] = {a[lx]};
                return;
            }
            int mid = (lx + rx) / 2;
            build(2 * x + 1, lx, mid, a);
            build(2 * x + 2, mid, rx, a);
            tree[x].resize(tree[2 * x + 1].size() + tree[2 * x + 2].size());
            merge(tree[2 * x + 1].begin(), tree[2 * x + 1].end(),
                 tree[2 * x + 2].begin(), tree[2 * x + 2].end(),
                 tree[x].begin());
        }
        int lessOnly(int l, int r, ll v, int x, int lx, int rx) {
            if (lx >= r || rx <= l) return 0;
            if (lx >= l && rx <= r) {
                return int(lower_bound(tree[x].begin(), tree[x].end(), v) - tree[x].begin());
            }
            int mid = (lx + rx) / 2;
            return lessOnly(l, r, v, 2 * x + 1, lx, mid) +
                   lessOnly(l, r, v, 2 * x + 2, mid, rx);
        }
        int lessOnly(int l, int r, ll v) {
            return lessOnly(l, r, v, 0, 0, size);
        }

        int lessEqual(int l, int r, ll v, int x, int lx, int rx) {
            if (lx >= r || rx <= l) return 0;
            if (lx >= l && rx <= r) {
                return int(upper_bound(tree[x].begin(), tree[x].end(), v) - tree[x].begin());
            }
            int mid = (lx + rx) / 2;
            return lessEqual(l, r, v, 2 * x + 1, lx, mid) +
                   lessEqual(l, r, v, 2 * x + 2, mid, rx);
        }
        int lessEqual(int l, int r, ll v) {
            return lessEqual(l, r, v, 0, 0, size);
        }
        int greaterEqual(int l, int r, ll v) {
            return (r - l) - lessOnly(l, r, v, 0, 0, size);
        }
        int greaterOnly(int l, int r, ll v) {
            return (r - l) - lessEqual(l, r, v, 0, 0, size);
        }
    };
*/
}

namespace SparseTable {
    // struct Sparse {
    //     int n, k;
    //     vector<vector<ll>> dp;
    //     vector<int> lg;
    //     explicit Sparse(const vector<ll> &a) {
    //         n = a.size();
    //         k = __lg(n);
    //         lg.assign(n + 1, 0);
    //         dp.assign(k + 1, vector<ll>(n));
    //         dp[0] = a;
    //         pre();
    //         build();
    //     }
    //     void pre() {
    //         for (int i = 2; i <= n; ++i) {
    //             lg[i] = lg[i / 2] + 1;
    //         }
    //     }
    //     ll merge(ll x, ll y) {
    //         return min(x, y);
    //     }
    //     void build() {
    //         for (int i = 1; i <= k; ++i) {
    //             for (int j = 0; j + (1 << i) <= n; ++j) {
    //                 dp[i][j] = merge(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    //             }
    //         }
    //     }
    //     ll query(int l, int r) {
    //         int mpw = lg[r - l + 1];
    //         return merge(dp[mpw][l], dp[mpw][r - (1 << mpw) + 1]);
    //     }
    // };
}

namespace Fenwick {
/*
struct Fenwick { // 1-index
#define int long long
    int size; vector<int> bit;
    Fenwick(int n) {
        size = n; bit.assign(size + 1, 0);
    }
    void add (int i, int v) {
        while (i <= size) bit[i] += v, i += i & -i;
    }
    int sum (int i) {
        int res = 0;
        while (i > 0) res += bit[i], i -= i & -i;
        return res;
    }
    int sum(int l, int r) {
        return l > r ? 0: sum(r) - sum(l - 1);
    }
#undef int
};
*/
}

namespace DSU {
    /*
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};
*/
}

namespace MonoStack {
/*
    struct monoStack {
        vector<ll> nxt;
        stack<ll> st;
        explicit monoStack(const vector<ll>& a) {
            nxt.resize(a.size(), -1);
            for (int i = a.size() - 1; ~i; --i) {
                while (!st.empty() && a[st.top()] <= a[i]) st.pop();
                if (!st.empty())
                    nxt[i] = st.top();
                st.push(i);
            }
        }
        int nxt_idx(int i) {
            return nxt[i];
        }
    };
*/
}

namespace SqrtD {
/*
    struct sqrtDecomposition {
        int n, sq;
        vector<ll> blk_ans, arr;
        vector<vector<ll>> blk;
        explicit sqrtDecomposition(const vector<ll> &a) {
            arr = a; n = a.size(); sq = sqrt(n);
            blk_ans.resize(sq,0);
            blk.assign(sq, vector<ll>(sq, 0));
        }
        void build() {
            forr (i, 0, n) {
                blk[i / sq].push_back(arr[i]);
                blk_ans[i / sq] += arr[i];
            }
        }
        void update (int idx, ll v) {
            blk_ans[idx / sq] -= arr[idx];
            blk_ans[idx / sq] += v;
            blk[idx / sq][idx % sq] = v;
        }
        ll query(int l, int r) {
            ll ans = 0;
            while (l <= r) {
                if (l % sq == 0 && l + sq <= r) {
                    ans += blk_ans[l / sq];
                    l += sq;
                } else {
                    ans += arr[l];
                    ++l;
                }
            } return ans;
        }
    };
    */
}

namespace Mo {
/*
    int SQ = 175;
    const int N = 1e6 + 5;
    vector<ll> freq(N);

    struct Query {
        int l, r, blk_idx, id;
        Query(){}
        explicit Query(int l, int r, int id): l(l), r(r), id(id) {}
    };

    struct Mo {
        int n, L, R, frq;
        vector<Query> Q;
        vector<ll> a, ans;
        explicit Mo(const vector<ll>& arr, const vector<Query>& QQ) {
            n = arr.size(), a = arr, Q = QQ;
            L = 0,  R = -1, frq = 0;
            ans.resize(QQ.size(), 0);
            sort(Q.begin(), Q.end(), [](Query a, Query b) {
                return (a.blk_idx != b.blk_idx) ? a.blk_idx < b.blk_idx: a.r < b.r;
            });
            process();
        }
        void remove(int p) {
            if (--freq[a[p]] == 0) frq --;
        }
        void add (int p) {
            if (freq[a[p]] == 0) frq ++;
            freq[a[p]] ++;
        }
        void process() {
            for(auto &[l, r, _, id]: Q) {
                while (L < l) remove(L++);
                while (L > l) add(--L);
                while (R > r) remove(R--);
                while (R < r) add(++R);
                ans[id] = frq;
            }
        }
    };
*/
}

namespace LCA {
    /*
    struct LCA {
        int n, LOG;
        vector<int> dep;
        vector<vector<int>> up;

        LCA(vector<vector<int>> &adj) {
            n = adj.size() - 1;
            LOG = __lg(n) + 1;

            up.assign(n + 1, vector<int>(LOG));
            dep.assign(n + 1, 0);

            function<void(int,int)> dfs = [&](int v, int p) {
                up[v][0] = p;
                for (int j = 1; j < LOG; j++)
                    up[v][j] = up[ up[v][j-1] ][j-1];

                for (int u : adj[v]) {
                    if (u == p) continue;
                    dep[u] = dep[v] + 1;
                    dfs(u, v);
                }
            };
            dfs(1, 1);
        }

        int find_anc(int a, int k) {
            if (k > dep[a]) return -1;
            for (int j = 0; j < LOG; j++)
                if (k & (1 << j))
                    a = up[a][j];
            return a;
        }

        int lca(int a, int b) {
            if (dep[a] < dep[b]) swap(a, b);
            a = find_anc(a, dep[a] - dep[b]);
            if (a == b) return a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[a][j] != up[b][j]) {
                    a = up[a][j];
                    b = up[b][j];
                }
            }
            return up[a][0];
        }
        int dist(int a, int b) {
            return dep[a] + dep[b] - 2 * dep[lca(a, b)];
        }
        int common_path(int f1, int f2, int des) {
            return ((dist(f1, des) + dist(f2, des) - dist(f1, f2)) >> 1) + 1;
        }
    }; */
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

namespace OrderedSet {
    // #include <ext/pb_ds/assoc_container.hpp>
    // #include <ext/pb_ds/tree_policy.hpp>
    //     using namespace std;
    //     using namespace __gnu_pbds;
    //
    //     typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

}

namespace Trie {
    /*struct TrieNode {
        TrieNode* child[26]; // لو حروف a-z
        int cnt; // عدد الكلمات اللي تمر من هنا
        int end_cnt; // عدد الكلمات اللي تنتهي هنا
        TrieNode() {
            cnt = 0;
            end_cnt = 0;
            for(int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    struct Trie {
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        // Insert word into trie
        void insert(const string &s) {
            TrieNode* cur = root;
            for(char c : s) {
                int idx = c - 'a';
                if(!cur->child[idx]) cur->child[idx] = new TrieNode();
                cur = cur->child[idx];
                cur->cnt++;
            }
            cur->end_cnt++;
        }

        // Search if word exists
        bool search(const string &s) {
            TrieNode* cur = root;
            for(char c : s) {
                int idx = c - 'a';
                if(!cur->child[idx]) return false;
                cur = cur->child[idx];
            }
            return cur->end_cnt > 0;
        }

        // Erase a word (decrease counts)
        bool erase(const string &s) {
            if(!search(s)) return false; // word not present
            TrieNode* cur = root;
            for(char c : s) {
                int idx = c - 'a';
                TrieNode* nxt = cur->child[idx];
                nxt->cnt--;
                // Optional: delete node if cnt==0 to save memory
                if(nxt->cnt == 0) {
                    cur->child[idx] = nullptr;
                    delete nxt;
                    return true;
                }
                cur = nxt;
            }
            cur->end_cnt--;
            return true;
        }
    };

}

namespace BinaryTrie {
    // struct BinaryTrie {
    //     struct Node {
    //         Node* ch[2];
    //         int freq[2];
    //         Node() {
    //             ch[0] = ch[1] = NULL;
    //             freq[0] = freq[1] = 0;
    //         }
    //     };
    //     BinaryTrie() {
    //         insert(0);
    //     }
    //     Node *root = new Node();
    //     void insert(int n) {
    //         Node* cur = root;
    //         for (int i = 29; i >= 0; i--) {
    //             int idx = (n >> i) & 1;
    //             if (cur->ch[idx] == 0)
    //                 cur->ch[idx] = new Node();
    //             cur->freq[idx]++;
    //             cur = cur->ch[idx];
    //         }
    //     }
    //     void del(int n, int i, Node* cur) {
    //         if (i == -1) return;
    //         bool idx = (n >> i) & 1;
    //         del(n, i - 1, cur->ch[idx]);
    //         cur->freq[idx]--;
    //         if (cur->freq[idx] == 0) {
    //             delete cur->ch[idx];
    //             cur->ch[idx] = 0;
    //         }
    //     }
    //     int query(int n) {
    //
    //     }
    // };
}

namespace dsuOnTree {
    /*
    const int N = 200005;
    vector<int> adj[N];
    int C[N], ans[N], freq[N];
    vector<pair<int,int>> queries[N];
    int sz[N], Big[N];

    void pre_sz(int v, int p) {
        sz[v] = 1, Big[v] = -1;
        for (int u : adj[v]) {
            if (u == p) continue;
            pre_sz(u, v);
            sz[v] += sz[u];
            if (Big[v] == -1 || sz[u] > sz[Big[v]]) Big[v] = u;
        }
    }


    void add_subtree(int v, int p, int d) {
        freq[C[v]] += d;
        for (int u : adj[v]) {
            if (u == p) continue;
            add_subtree(u, v, d);
        }
    }

    void dfs(int v, int p, bool keep) {

        for (int u : adj[v]) {
            if (u == p || u == Big[v]) continue;
            dfs(u, v, false);
        }

        if (Big[v] != -1) dfs(Big[v], v, true);

        freq[C[v]]++;
        for (int u : adj[v]) {
            if (u == p || u == Big[v]) continue;
            add_subtree(u, v, +1);
        }

        for (auto &pr : queries[v]) {
            int color = pr.first;
            int idx = pr.second;
            ans[idx] = freq[color];
        }

        if (!keep) add_subtree(v, p, -1);
    }
    */
}

namespace custom_hash {
    // struct custom_hash {
    //     static uint64_t splitmix64(uint64_t x) {
    //         x += 0x9e3779b97f4a7c15;
    //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    //         return x ^ (x >> 31);
    //     }
    //
    //     size_t operator()(uint64_t x) const {
    //         static const uint64_t FIXED_RANDOM =
    //             chrono::steady_clock::now().time_since_epoch().count();
    //         return splitmix64(x + FIXED_RANDOM);
    //     }
    // };
}