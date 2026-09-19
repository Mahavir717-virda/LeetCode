class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xn, yn;

        if (x1 > xCenter) {
            xn = x1;
        } else if (x2 < xCenter) {
            xn = x2;
        } else {
            xn = xCenter;
        }

        if (y1 > yCenter) {
            yn = y1;
        } else if (y2 < yCenter) {
            yn = y2;
        } else {
            yn = yCenter;
        }



        return (pow((xCenter - xn), 2) + pow((yCenter - yn), 2)) <= radius * radius;
    }
};