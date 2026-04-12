class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());

        vector<double> ans;
        double a = sides[0], b = sides[1], c = sides[2];
        
        if(a+b > c && b+c > a && a+c > b && a!=0 && b!=0 && c!= 0){
            double alpha = acos((a*a + b*b -c*c)/(2*a*b));
            double beta = acos((b*b + c*c - a*a)/(2*b*c));
            double gamma = acos((c*c + a*a - b*b)/(2*c*a));
            
            alpha *= 180.0/acos(-1.0);
            beta *= 180.0/acos(-1.0);
            gamma *= 180.0/acos(-1.0);

            ans = {alpha, beta, gamma};
            sort(ans.begin(), ans.end());
        }

        return ans;
    }
};