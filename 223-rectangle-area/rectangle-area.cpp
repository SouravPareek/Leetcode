class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area = 0;

        area += (ax2-ax1) * (ay2-ay1);
        area += (bx2-bx1) * (by2-by1);

        int intersectionLength = 0;
        int intersectionBreadth = 0;

        if((((ax2 < bx1) && (ax1 < bx1) && (ax2 < bx2) && (ax1 < bx2)) || ((ay2 < by1) && (ay1 < by1) && (ay2 < by2) && (ay1 < by2))) || (((ax2 > bx1) && (ax1 > bx1) && (ax2 > bx2) && (ax1 > bx2)) || ((ay2 > by1) && (ay1 > by1) && (ay2 > by2) && (ay1 > by2)))){

        }else{
            intersectionLength = (min(ax2, bx2) - max(ax1, bx1));
            intersectionBreadth = (min(ay2, by2) - max(ay1, by1));
        }

        area -= (intersectionLength*intersectionBreadth);

        return area;
    }
};