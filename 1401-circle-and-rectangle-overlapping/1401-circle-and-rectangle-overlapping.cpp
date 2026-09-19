class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,int x1, int y1, int x2, int y2) { //T.C = S.C = O(1) 
   
        // Closest point on the rectangle to the circle's center.
        // max(x1, min(xCenter, x2)) clamps xCenter into [x1, x2].
        int px = max(x1, min(xCenter, x2));
        int py = max(y1, min(yCenter, y2));

        // Distance from center to that point, kept squared so no sqrt is needed.
        // Max value is about 2 * (2e4)^2 = 8e8, which fits in a 32-bit int.
        int dx = px - xCenter;
        int dy = py - yCenter;

        // Touching counts as overlapping, so the comparison is <=, not <.
        return dx * dx + dy * dy <= radius * radius;
    }
};