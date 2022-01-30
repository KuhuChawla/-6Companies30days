class Solution {
    double r,x,y;
public:
    Solution(double radius, double x_center, double y_center) : r(radius) , x(x_center), y(y_center) {
        
    }
    
    vector<double> randPoint() {
        double dist = sqrt((double)rand()/RAND_MAX)*r;
        double angle = (double)rand()/RAND_MAX *2 * M_PI;
        return {x+ dist*cos(angle), y+ dist*sin(angle)};
    }
};
