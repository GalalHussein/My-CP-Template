namespace min_heap {
// template<typename U>
// using min_heap = priority_queue<U, vector<U>, greater<U>>;
}
namespace SegTree {
    /*
struct segTree {
#define L(x) (2 * x + 1)
#define R(x) (2 * x + 2)
int size;
const int init = 1e18;
vector<int> tree;
segTree(int n) {
size = 1uLL << (64 - __builtin_clzll(n - 1));
tree.assign(2 * size, init);
}
int merge (int __left, int __right) {
return min(__left, __right);
}
void update (int i, int v, int x, int lx, int rx) {
if (rx - lx == 1) {
    tree[x] = v;
    return;
}
int mid = (lx + rx) / 2;
if (i < mid) {
    update (i, v, L(x), lx, mid);
} else {
    update (i, v, R(x), mid, rx);
}
tree[x] = merge (tree[L(x)], tree[R(x)]);
}

void update (int i, int v) {
update (i, v, 0, 0, size);
}

int query (int l, int r, int x, int lx, int rx) {
if (l >= rx or r <= lx) return init;
if (lx >= l && rx <= r) return tree[x];

int mid = (lx + rx) / 2;
return merge (query (l, r, L(x), lx, mid),query (l, r, R(x), mid, rx));
}

int query (int l, int r) {
return query(l, r, 0, 0, size);
}

#undef L
#undef R
};
struct Max2SegTree {
struct Node { long long mx, smax; };
int n;
vector<Node> st;
Max2SegTree() = default;
Max2SegTree(const vector<long long>& a){
n=(int)a.size();
st.assign(4*n, {LLONG_MIN, LLONG_MIN});
build(1,0,n-1,a);
}
Node merge(const Node& A,const Node& B){
Node R;
if(A.mx>=B.mx){ R.mx=A.mx; R.smax=max(A.smax, B.mx); }
else { R.mx=B.mx; R.smax=max(B.smax, A.mx); }
return R;
}
void build(int p,int l,int r,const vector<long long>& a){
if(l==r){ st[p]={a[l], LLONG_MIN}; return; }
int m=(l+r)/2;
build(p<<1,l,m,a);
build(p<<1|1,m+1,r,a);
st[p]=merge(st[p<<1],st[p<<1|1]);
}
Node query(int ql,int qr){ return query(1,0,n-1,ql,qr); }
Node query(int p,int l,int r,int ql,int qr){
if(ql>r||qr<l) return {LLONG_MIN, LLONG_MIN};
if(ql<=l&&r<=qr) return st[p];
int m=(l+r)/2;
return merge(query(p<<1,l,m,ql,qr), query(p<<1|1,m+1,r,ql,qr));
}
void point_update(int idx,long long v){ point_update(1,0,n-1,idx,v); }
void point_update(int p,int l,int r,int idx,long long v){
if(l==r){ st[p]={v,LLONG_MIN}; return; }
int m=(l+r)/2;
if(idx<=m) point_update(p<<1,l,m,idx,v); else point_update(p<<1|1,m+1,r,idx,v);
st[p]=merge(st[p<<1],st[p<<1|1]);
}
};

*/
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
namespace successorPath {
    // vector<vector<int>> up(n + 1, vector<int>(20));
    // for (int i = 1; i <= n; i++) {
    //     up[i][0] = par[i];
    // }
    // for (int j = 1; j < 20; j++) {
    //     for (int i = 1; i <= n; i++) {
    //         up[i][j] = up[ up[i][j - 1] ][j - 1];
    //     }
    // }
    // auto getRoot = [&](int v) {
    //     for (int j = 19; j >= 0; j--) {
    //         if (up[v][j] != v) {
    //             v = up[v][j];
    //         }
    //     }
    //     return v;
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
/*    struct monoStack {
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
namespace OrderedSet {
    // #include <ext/pb_ds/assoc_container.hpp>
    // #include <ext/pb_ds/tree_policy.hpp>
    //     using namespace std;
    //     using namespace __gnu_pbds;
    //
    //     typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
namespace dsu_setGroup {
    // using namespace std;
    // using namespace __gnu_pbds;
    // typedef tree<int, null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
    //
    //
    // struct DSU {
    //     vector<int> parent, size;
    //     vector<ordered_set> st;
    //     DSU(int n) {
    //         parent.resize(n+1);
    //         size.resize(n+1, 1);
    //         st.resize(n + 1);
    //         for(int i = 0; i <= n; i++)
    //             parent[i] = i, st[i].insert(i);
    //     }
    //     int find(int x) {
    //         if(parent[x] != x)
    //             parent[x] = find(parent[x]);
    //         return parent[x];
    //     }
    //     bool unite(int a, int b) {
    //         a = find(a);
    //         b = find(b);
    //         if(a == b) return false;
    //         if(size[a] < size[b]) swap(a, b);
    //         parent[b] = a;
    //         size[a] += size[b];
    //         for (int i: st[b]) st[a].insert(i);
    //         st[b].clear();
    //         return true;
    //     }
    //     int query(int u, int k) {
    //         int v = find(u);
    //         if (k >= st[v].size()) return -1;
    //         return *st[v].find_by_order(k);
    //     }
    //     bool same(int a, int b) {
    //         return find(a) == find(b);
    //     }
    // };
}
