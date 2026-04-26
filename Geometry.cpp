// inline T X(point p){ return p.real(); }
// inline T Y(point p){ return p.imag(); }
namespace VecOps {
//     typedef long double T;
//     typedef complex<T> point;
//
// #define x real()
// #define y imag()
//
//     T cross(point a, point b) {
//         return (conj(a) * b).y;
//     }
//
//     T dot(point a, point b) {
//         return (conj(a) * b).x;
//     }
}
namespace Angles {
//     using namespace VecOps;
// #define PI acosl(-1)
//
//     // [0, 2pi]
//     T angle_withX(point v) {
//         T a = atan2(v.y, v.x);
//         if (a < 0) a += 2 * PI;
//         return a;
//     }
//
//     // from a to b CCW [0, 2pi]
//     T angle_a_b_ccw(const point &a, const point &b) {
//         T ang = atan2(cross(a,b), dot(a,b));
//         if (ang < 0) ang += 2*PI;
//         return ang;
//     }
//
//     // smallest angle [0, pi]
//     T smallest_angle(const point &a, const point &b) {
//         T ang = atan2(cross(a,b), dot(a,b));
//         return fabsl(ang);
//     }
}
namespace PolarSort {
    // using namespace VecOps;
    //
    // bool half(point p) {
    //     assert(p.x != 0 || p.y != 0);
    //     return p.y > 0 || (p.y == 0 && p.x < 0);
    // }
    //
    // bool polar_sort(point &a, point &b) {
    //     if (half(a) != half(b)) return half(a) < half(b);
    //     return cross(a, b) > 0;
    // }
}
namespace Geometry {
    // using namespace VecOps;
    //
    // T orient(point a, point b, point c) {
    //     return cross(b - a, c - a);
    // }
    //
    // auto ornt = [](auto x, auto y, auto z) {
    //     pair<int, int> xy = {y.first - x.first, y.second - x.second};
    //     pair<int, int> xz = {z.first - x.first, z.second - x.second};
    //     return xy.first * xz.second - xy.second * xz.first;
    // };
    //
    // auto segIntersect = [ornt](auto u1, auto v1, auto w1, auto w2) {
    //     return (ornt(u1, v1, w1) * ornt(u1, v1, w2) < 0 &&
    //             ornt(w1, w2, v1) * ornt(w1, w2, u1) < 0);
    // };
}
namespace Polygon {
    // using namespace VecOps;
    //
    // T PolygonArea(vector<point> ply) {
    //     T area = 0.0;
    //     int n = ply.size();
    //     for (int i = 0; i < n; i++) {
    //         area += cross(ply[i], ply[(i + 1) % n]);
    //     }
    //     return abs(area) / 2.0;
    // }
}
namespace MathUtils {
    // int countSquaresInsideCircle(int r) {
    //     int ans = 0;
    //     int y = r;
    //     for (int x = 0; ; x++) {
    //         while (y >= 0) {
    //             long double dx = x + 0.5L;
    //             long double dy = y + 0.5L;
    //             if (dx * dx + dy * dy <= r * r) break;
    //             y--;
    //         }
    //         if (y < 0) break;
    //         if (x == 0) ans += 2 * y + 1;
    //         else ans += 4 * y + 2;
    //     }
    //     return ans;
    // }
}