// vector<pair<int,int>> DIR = {{-1,0},{1,0},{0,-1},{0,1}};

namespace LCA {
// struct LCA {
//     int n, LOG;
//     vector<int> dep;
//     vector<vector<int>> up;
//
//     LCA(vector<vector<int>> &adj) {
//         n = adj.size() - 1;
//         LOG = __lg(n) + 1;
//
//         up.assign(n + 1, vector<int>(LOG));
//         dep.assign(n + 1, 0);
//
//         function<void(int,int)> dfs = [&](int v, int p) {
//             up[v][0] = p;
//             for (int j = 1; j < LOG; j++)
//                 up[v][j] = up[ up[v][j-1] ][j-1];
//
//             for (int u : adj[v]) {
//                 if (u == p) continue;
//                 dep[u] = dep[v] + 1;
//                 dfs(u, v);
//             }
//         };
//         dfs(1, 1);
//     }
//
//     int find_anc(int a, int k) {
//         if (k > dep[a]) return -1;
//         for (int j = 0; j < LOG; j++)
//             if (k & (1 << j))
//                 a = up[a][j];
//         return a;
//     }
//
//     int lca(int a, int b) {
//         if (dep[a] < dep[b]) swap(a, b);
//         a = find_anc(a, dep[a] - dep[b]);
//         if (a == b) return a;
//
//         for (int j = LOG - 1; j >= 0; j--) {
//             if (up[a][j] != up[b][j]) {
//                 a = up[a][j];
//                 b = up[b][j];
//             }
//         }
//         return up[a][0];
//     }
//     int dist(int a, int b) {
//         return dep[a] + dep[b] - 2 * dep[lca(a, b)];
//     }
//     int common_path(int f1, int f2, int des) {
//         return ((dist(f1, des) + dist(f2, des) - dist(f1, f2)) >> 1) + 1;
//     }
// };
}
namespace bfs {
    // vector<vector<int>> adj;
    // vector<int> dist;
    //
    // void bfs(int start) {
    //     int n = adj.size();
    //     dist.assign(n, -1);
    //     queue<int> q;
    //     q.push(start);
    //     dist[start] = 0;
    //
    //     while(!q.empty()) {
    //         int u = q.front(); q.pop();
    //         for(int v : adj[u]) {
    //             if(dist[v] == -1) {
    //                 dist[v] = dist[u] + 1;
    //                 q.push(v);
    //             }
    //         }
    //     }
    // }
}
namespace dijkstra {
    // const long long INF = 1e18;
    // vector<vector<pair<int,int>>> adj;
    //
    // vector<long long> dijkstra(int start) {
    //     int n = adj.size();
    //     vector<long long> dist(n, INF);
    //     dist[start] = 0;
    //     priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    //     pq.push({0, start});
    //
    //     while(!pq.empty()) {
    //         auto [d, u] = pq.top(); pq.pop();
    //         if(d != dist[u]) continue;
    //         for(auto [v, w] : adj[u]) {
    //             if(dist[v] > dist[u] + w) {
    //                 dist[v] = dist[u] + w;
    //                 pq.push({dist[v], v});
    //             }
    //         }
    //     }
    //     return dist;
    // }
}
namespace prim {
// int n, m;
// cin >> n >> m;
// vector<vector<pair<int,int>>> adj(n + 1);
//
// for (int i = 0; i < m; i++) {
//     int u, v, w;
//     cin >> u >> v >> w;
//     adj[u].push_back({v, w});
//     adj[v].push_back({u, w});
// }
//
// vector<bool> vis(n + 1, false);
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
// pq.push({0, 1});
//
// int mst_cost = 0;
//
// while (!pq.empty()) {
//     auto [w, u] = pq.top();
//     pq.pop();
//     if (vis[u]) continue;
//     vis[u] = true;
//     mst_cost += w;
//
//     for (auto [v, cost] : adj[u]) {
//         if (!vis[v]) {
//             pq.push({cost, v});
//         }
//     }
// }
// cout << mst_cost << "\n";
}
namespace floyd {
    // Floyd-warshall O(n^3)
    // find min dist from each u-v
    // int n;
    // vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    // vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    //
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (i == j) dist[i][j] = 0;
    //         else if (adj[i][j]) dist[i][j] = adj[i][j];
    //         else dist[i][j] = INF;
    //     }
    // }
    //
    // for (int k = 1; k <= n; k++) {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    //         }
    //     }
    // }
    // add edges in query
    // auto Add = [&](int u, int v, long long w) {
    //     if (dist[u][v] > w) dist[u][v] = w;
    //
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             if (dist[i][u] == INF || dist[v][j] == INF) continue;
    //             dist[i][j] = min(dist[i][j],
    //                              dist[i][u] + w + dist[v][j]);
    //         }
    //     }
    // };
    // auto addTwoDirection = [&](int u, int v, long long w) {
    //     Add(u, v, w);
    //     Add(v, u, w);
    // };
}
namespace kruskal {
    // struct DSU {
    //     vector<int> parent, sz;
    //
    //     DSU(int n) {
    //         parent.resize(n + 1);
    //         sz.resize(n + 1, 1);
    //         for (int i = 1; i <= n; i++)
    //             parent[i] = i;
    //     }
    //
    //     int find(int x) {
    //         if (x == parent[x]) return x;
    //         return parent[x] = find(parent[x]); // path compression
    //     }
    //
    //     bool unite(int a, int b) {
    //         a = find(a);
    //         b = find(b);
    //         if (a == b) return false;
    //
    //         // union by size
    //         if (sz[a] < sz[b]) swap(a, b);
    //         parent[b] = a;
    //         sz[a] += sz[b];
    //         return true;
    //     }
    // };
    //
    // struct Edge {
    //     int u, v;
    //     ll w;
    //
    //     bool operator<(const Edge &other) const {
    //         return w < other.w;
    //     }
    // };
    // int n, m;
    // cin >> n >> m;
    //
    // vector<Edge> edges(m);
    // for (int i = 0; i < m; i++) {
    //     cin >> edges[i].u >> edges[i].v >> edges[i].w;
    // }
    //
    // sort(edges.begin(), edges.end());
    //
    // DSU dsu(n);
    //
    // ll mst_cost = 0;
    //
    // for (auto &e : edges) {
    //     if (dsu.unite(e.u, e.v)) {
    //         mst_cost += e.w;
    //     }
    // }
    //
    // cout << mst_cost << "\n";

}
namespace tpSort { 
    // vector<vector<int>> adj(n + 1);
    // vector<int> indegree(n + 1, 0);
    //
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     indegree[v]++;
    // }
    //
    // queue<int> q;
    //
    // // nodes with indegree 0
    // for (int i = 1; i <= n; i++) {
    //     if (indegree[i] == 0)
    //         q.push(i);
    // }
    //
    // vector<int> topo;
    //
    // while (!q.empty()) {
    //     int u = q.front();
    //     q.pop();
    //     topo.push_back(u);
    //
    //     for (auto v : adj[u]) {
    //         indegree[v]--;
    //         if (indegree[v] == 0)
    //             q.push(v);
    //     }
    // }
    //
    // // check cycle
    // if ((int)topo.size() != n) {
    //     cout << "Graph has a cycle\n";
    // } else {
    //     for (auto x : topo)
    //         cout << x << " ";
    // }


}
namespace kosaraju {
// int N = 2e5;
// vector<vector<int>> adj, Tadj, scc, Cadj;
// vector<int> compID, sub; stack<int> order;
// vector<bool> vis(N);
//
// void dfs1(int v) {
//     vis[v] = 1;
//     for (auto u: adj[v]) if (!vis[u]) dfs1(u);
//     order.push(v);
// }
// void dfs2(int v, int id) {
//     compID[v] = id;
//     vis[v] = 1;
//     sub.push_back(v);
//     for (auto u: Tadj[v]) if (!vis[u]) dfs2(u, id);
// }
// void build_cond(int);
//
// void kosaraju(int n) {
//     // adj.resize(n + 1);
//     // Tadj.resize(n + 1);
//     // compID.resize(n + 1);
//     for (int i = 1; i <= n; i++) if (not vis[i]) dfs1(i);
//     vis.assign(n, false);
//     int cnt = 0;
//     while (not order.empty()) {
//         while (not order.empty() && vis[order.top()]) order.pop();
//         if (order.empty()) break;
//         int v = order.top(); order.pop();
//         sub.clear();
//         dfs2(v, ++cnt);
//         scc.push_back(sub);
//     } build_cond(n);
// }
// void build_cond(int n) {
//     Cadj.resize(scc.size() + 1);
//     set<pair<int,int>> seen;
//     for (int i = 1; i <= n; i++) {
//         for (int u: adj[i]) {
//             if (compID[i] != compID[u] && !seen.count({compID[i], compID[u]})) {
//                 Cadj[compID[i]].push_back(compID[u]);
//                 seen.insert({compID[i], compID[u]});
//             }
//         }
//     }
// }
}
namespace tarjan {

}
namespace DFS_tree_Graph {
 //   Articulation points and bridges (Undirected graph)

 //    const int N = 1e5;
 //    vector<int> low(N), vis(N), dep(N);
 //    vector<vector<int>> adj(N);
 //    set<pair<int,int>> bridges;
 //    vector<bool> artc_point(N);
 //
 //    void dfs(int v, int p) {
 //        int children =0;
 //        vis[v] = 1, low[v] = dep[v];
 //        for (int u: adj[v]) {
 //            if (u == p) continue;
 //            if (vis[u]) {
 //                    low[v] = min(low[v], dep[u]); continue;
 //            }
 //            dep[u] = dep[v] + 1;
 //            dfs(u, v); children++;
 //            low[v] = min(low[v], low[u]);
 //            if (p != -1 && low[u] >= dep[v])    artc_point[v] = true;
 //            if (low[u] > dep[v])     bridges.insert({u, v});
 //        } if (p == -1 && children > 1) artc_point[v] = true;
 //    }
}
namespace tree_bridges {
// vector<pair<int, int>> edges;
// vector<vector<pair<int, int>>> adj;
// vector<int> tin, low;
// vector<char> isBridge;
// vector<int> comp;
// int n, m;

// void read() {
// adj.resize(n);
// edges.resize(m);
// tin.resize(n, 0);
// low.resize(n, 0);
// isBridge.resize(m, 0);
// comp.resize(n, -1);

// for (int i = 0; i < m; ++i) {
//     int u, v;
//     cin >> u >> v;
//     --u;
//     --v;
//     edges[i] = {u, v};
//     adj[u].push_back({v, i});
//     adj[v].push_back({u, i});
// }
// }

// int timer = 0;

// void find_bridges() {
// function<void(int, int)> dfs = [&](int u, int pe) {
//     tin[u] = low[u] = ++timer;
//     for (auto [v, id] : adj[u]) {
//         if (id == pe) continue;
//         if (!tin[v]) {
//             dfs(v, id);
//             low[u] = min(low[u], low[v]);
//             if (low[v] > tin[u])
//                 isBridge[id] = 1;
//         } else {
//             low[u] = min(low[u], tin[v]);
//         }
//     }
// };

// for (int i = 0; i < n; ++i)
//     if (!tin[i])
//         dfs(i, -1);
// }

// int cid = 0;

// void Compress_2ECC() {
// function<void(int)> dfs2 = [&](int u) {
//     stack<int> st;
//     st.push(u);
//     comp[u] = cid;

//     while (!st.empty()) {
//         int x = st.top();
//         st.pop();
//         for (auto [v, id] : adj[x]) {
//             if (isBridge[id]) continue;
//             if (comp[v] == -1) {
//                 comp[v] = cid;
//                 st.push(v);
//             }
//         }
//     }
// };

// for (int i = 0; i < n; ++i)
//     if (comp[i] == -1)
//         dfs2(i), ++cid;
// }

// vector<vector<int>> tree(cid);

// void build_BridgeTree() {
// for (int i = 0; i < m; ++i) {
//     if (isBridge[i]) {
//         if (comp[edges[i].first] != comp[edges[i].second]) {
//             tree[comp[edges[i].first]].push_back(comp[edges[i].second]);
//             tree[comp[edges[i].second]].push_back(comp[edges[i].first]);
//         }
//     }
// }
// }
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
// const int N = 200005;
// vector<int> adj[N];
// int C[N], ans[N], freq[N];
// vector<pair<int,int>> queries[N];
// int sz[N], Big[N];
//
// void pre_sz(int v, int p) {
//     sz[v] = 1, Big[v] = -1;
//     for (int u : adj[v]) {
//         if (u == p) continue;
//         pre_sz(u, v);
//         sz[v] += sz[u];
//         if (Big[v] == -1 || sz[u] > sz[Big[v]]) Big[v] = u;
//     }
// }
//
//
// void add_subtree(int v, int p, int d) {
//     freq[C[v]] += d;
//     for (int u : adj[v]) {
//         if (u == p) continue;
//         add_subtree(u, v, d);
//     }
// }
//
// void dfs(int v, int p, bool keep) {
//
//     for (int u : adj[v]) {
//         if (u == p || u == Big[v]) continue;
//         dfs(u, v, false);
//     }
//
//     if (Big[v] != -1) dfs(Big[v], v, true);
//
//     freq[C[v]]++;
//     for (int u : adj[v]) {
//         if (u == p || u == Big[v]) continue;
//         add_subtree(u, v, +1);
//     }
//
//     for (auto &pr : queries[v]) {
//         int color = pr.first;
//         int idx = pr.second;
//         ans[idx] = freq[color];
//     }
//
//     if (!keep) add_subtree(v, p, -1);
// }
}
namespace reroot {
//     const auto exclusive = [](const auto& a, const auto& base, const auto& merge_into, int vertex) {
//         int n = (int)a.size();
//         using Aggregate = std::decay_t<decltype(base)>;
//         std::vector<Aggregate> b(n, base);
//         for (int bit = (int)std::__lg(n); bit >= 0; --bit) {
//             for (int i = n - 1; i >= 0; --i) b[i] = b[i >> 1];
//             int sz = n - (n & !bit);
//             for (int i = 0; i < sz; ++i) {
//                 int index = (i >> bit) ^ 1;
//                 b[index] = merge_into(b[index], a[i], vertex, i);
//             }
//         }
//         return b;
//     };
//     // MergeInto : Aggregate * Value * Vertex(int) * EdgeIndex(int) -> Aggregate
//     // Base : Vertex(int) -> Aggregate
//     // FinalizeMerge : Aggregate * Vertex(int) * EdgeIndex(int) -> Value
//     const auto rerooter = [](const auto& g, const auto& base, const auto& merge_into, const auto& finalize_merge) {
//         int n = (int)g.size();
//         using Aggregate = std::decay_t<decltype(base(0))>;
//         using Value = std::decay_t<decltype(finalize_merge(base(0), 0, 0))>;
//         std::vector<Value> root_dp(n), dp(n);
//         std::vector<std::vector<Value>> edge_dp(n), redge_dp(n);
//
//         std::vector<int> bfs, parent(n);
//         bfs.reserve(n);
//         bfs.push_back(0);
//         for (int i = 0; i < n; ++i) {
//             int u = bfs[i];
//             for (auto v : g[u]) {
//                 if (parent[u] == v) continue;
//                 parent[v] = u;
//                 bfs.push_back(v);
//             }
//         }
//
//         for (int i = n - 1; i >= 0; --i) {
//             int u = bfs[i];
//             int p_edge_index = -1;
//             Aggregate aggregate = base(u);
//             for (int edge_index = 0; edge_index < (int)g[u].size(); ++edge_index) {
//                 int v = g[u][edge_index];
//                 if (parent[u] == v) {
//                     p_edge_index = edge_index;
//                     continue;
//                 }
//                 aggregate = merge_into(aggregate, dp[v], u, edge_index);
//             }
//             dp[u] = finalize_merge(aggregate, u, p_edge_index);
//         }
//
//         for (auto u : bfs) {
//             dp[parent[u]] = dp[u];
//             edge_dp[u].reserve(g[u].size());
//             for (auto v : g[u]) edge_dp[u].push_back(dp[v]);
//             auto dp_exclusive = exclusive(edge_dp[u], base(u), merge_into, u);
//             redge_dp[u].reserve(g[u].size());
//             for (int i = 0; i < (int)dp_exclusive.size(); ++i) redge_dp[u].push_back(finalize_merge(dp_exclusive[i], u, i));
//             root_dp[u] = finalize_merge(n > 1 ? merge_into(dp_exclusive[0], edge_dp[u][0], u, 0) : base(u), u, -1);
//             for (int i = 0; i < (int)g[u].size(); ++i) {
//                 dp[g[u][i]] = redge_dp[u][i];
//             }
//         }
//
//         return std::make_tuple(std::move(root_dp), std::move(edge_dp), std::move(redge_dp));
//     };
// }
// // to solve re rooting problem you fill those three function then call re rooter sending them and the graph
//
// using Aggregate = ll;
// using Value = ll;
// auto base = [](int vertex) -> Aggregate {
//     // your dp initialization
//     return 0;
// };
// auto merge_into = [](Aggregate vertex_dp, Value neighbor_dp, int vertex, int edge_index) -> Aggregate {
//     // how to merge answer of the vertex and it's child
//    // note edge index is the index in the adj list like adj[3] : 2 1 12 , then the edge_index of 2 represent the edge 3 --> 12
//     return 0;
// };
// auto finalize_merge = [&](Aggregate vertex_dp, int vertex, int edge_index) -> Value {
//     // before finish the dfs any work with the dp value
//     return 0;
// };
}
namespace HLD {
// struct segTree {
//     int size;
//     int init = 1e18;
//     vector<int> tree;
//     segTree(){}
//     segTree(int n) {
//         size = 1uLL << (64 - __builtin_clzll(n - 1));
//         tree.assign(2 * size, init);
//     }
//     int merge (int __left, int __right) {
//         return min(__left, __right);
//     }
//     void update (int i, int v, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             tree[x] = v;
//             return;
//         }
//         int mid = (lx + rx) / 2;
//         if (i < mid)
//             update (i, v, (2 * x + 1), lx, mid);
//         else
//             update (i, v, (2 * x + 2), mid, rx);
//         tree[x] = merge (tree[2 * x + 1], tree[2 * x + 2]);
//     }
//
//     void update (int i, int v) {
//         update (i, v, 0, 0, size);
//     }
//     int query (int l, int r, int x, int lx, int rx) {
//         if (l >= rx or r <= lx) return init;
//         if (lx >= l && rx <= r) return tree[x];
//         int mid = (lx + rx) / 2;
//         return merge (query (l, r, 2 * x + 1, lx, mid),query (l, r, 2 * x + 1, mid, rx));
//     }
//     int query (int l, int r) {
//         return query(l, r, 0, 0, size);
//     }
// };
//
// struct HLD {
//     int n;
//     vector<vector<int>> tree;
//     vector<int> parent, depth, heavy, head, pos, sz, rev, value;
//     int cur_pos;
//     segTree seg;
//
//     HLD(int n=0) {
//         init(n);
//     }
//     void init(int _n) {
//         n = _n;
//         tree.assign(n + 1, {});
//         parent.assign(n + 1, 0);
//         depth.assign(n + 1, 0);
//         heavy.assign(n + 1, -1);
//         head.assign(n + 1, 0);
//         pos.assign(n + 1, 0);
//         sz.assign(n + 1, 0);
//         rev.assign(n + 1, 0);
//         value.assign(n + 1, 0);
//         cur_pos = 0;
//     }
//     void addEdges(int u, int v) {
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }
//     int dfs1(int u, int p) {
//         parent[u] = p;
//         sz[u] = 1;
//         int max_sz = 0;
//         for (int v: tree[u]) { if (v == p) continue;
//             depth[v] = depth[u] + 1;
//             int sub_sz = dfs1(v, u);
//             sz[u] += sub_sz;
//             if (sub_sz > max_sz) {
//                 max_sz = sub_sz;
//                 heavy[u] = v;
//             }
//         } return sz[u];
//     }
//     void dfs2(int u, int h) {
//         head[u] = h;
//         pos[u] = cur_pos;
//         rev[cur_pos ++] = u;
//         if (~heavy[u]) {
//             dfs2(heavy[u], h);
//         }
//         for (int v: tree[u]) {
//             if (v == parent[u] || v == heavy[u]) continue;
//             dfs2(v, v);
//         }
//     }
//     void build(int root = 1) {
//         depth[root] = 0;
//         dfs1(root, 0);
//         cur_pos = 0;
//         dfs2(root, root);
//         vector<int> flatten(n);
//         for (int u = 1; u <= n; u++) {
//             flatten[pos[u]] = value[u];
//         }
//         // build segTree
//         seg = segTree(n);
//         for (int u = 1; u <= n; u++) seg.update(pos[u], value[u]);
//     }
//     int path_query(int u, int v) {
//         int ans = 0;
//         while (head[u] != head[v]) {
//             if (depth[head[u]] < depth[head[v]]) swap(u, v);
//             // Query on segment
//             ans += seg.query(pos[head[u]], pos[u] + 1);
//             u = parent[head[u]];
//         }
//         if (depth[u] < depth[v]) swap(u, v);
//         ans += seg.query(pos[u], pos[u] + 1);
//         return ans;
//     }
//     void update_node(int u, int v) {
//         value[u] = v;
//         seg.update(pos[u], v);
//     }
// };
}
