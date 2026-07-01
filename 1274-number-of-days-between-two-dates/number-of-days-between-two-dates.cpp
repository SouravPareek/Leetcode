class Solution {
private:
    int daysInSameYear(int year, int mth1, int day1){
        vector<int> months={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int cnt = 0;
        int mth2 = 12, day2 = 31;
        bool isLeap = false;
        if(year%4 == 0 && year!= 2100)//leap year
            isLeap = true;
        
        for(int i = mth1; i <= mth2; i++){
            cnt += months[i];
            if(isLeap && i == 2)
                cnt += 1;
        }
        cnt -= day1;
        cnt -= (months[mth2] - day2);

        return cnt;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        int year1 = stoi(date1.substr(0, 4));
        int year2 = stoi(date2.substr(0, 4));
        int mth1 = stoi( date1.substr(5, 7));
        int mth2 = stoi( date2.substr(5, 7));
        int day1 = stoi(date1.substr(8, 10));
        int day2 = stoi(date2.substr(8, 10));

        if(year1 > year2){
            swap(year1, year2);
            swap(mth1, mth2);
            swap(day1, day2);
        }else if(year1 == year2){
            if(mth1 > mth2){
                swap(mth1, mth2);
                swap(day1, day2);
            }else if(mth1 == mth2){
                return abs(day1-day2);
            }
        }

        //year2 > year1
        

        int cnt = 0;

        //year equal(mth2 > mth1)
        if(year1 == year2){
            cnt += (daysInSameYear(year1, mth1, day1) - daysInSameYear(year2, mth2, day2));
            return cnt;
        }

        //diff year
        for(int i = year1+1; i <= year2; i++){
            cnt += 365;
            if(i%4 == 0 && i != 2100)
                cnt += 1;
        }
        cnt += daysInSameYear(year1, mth1, day1);
        cnt -= daysInSameYear(year2, mth2, day2);

        return cnt;
    }
};