// You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

// A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

// Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

// Since the answer may be very large, return it modulo 109 + 7.

 



var countTrapezoids = function (points) {
    const MOD = 1_000_000_007;
    const map = new Map();

    // Count points per y-level
    for (let [x, y] of points) {
        map.set(y, (map.get(y) || 0) + 1);
    }

    let S = 0n, S2 = 0n;

    for (let f of map.values()) {
        if (f >= 2) {
            let c = BigInt(f * (f - 1) / 2); // nC2
            S += c;
            S2 += c * c;
        }
    }

    // (S^2 - S2) / 2
    let ans = (S * S - S2) / 2n;
    return Number(ans % BigInt(MOD));
};
                                                                                                            
