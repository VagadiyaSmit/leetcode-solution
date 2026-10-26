class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {    //T.C = O(1) S.C = O(1)
        // return  min of leave date - max of arrive date

        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        
        int prefix[13] = {0};       // prefix[m] = days elapsed before month m starts (m is 1-indexed)
        for (int i = 1; i <= 12; i++)
            prefix[i] = prefix[i - 1] + days[i - 1];


        auto toDay = [&](const string& s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            return prefix[m - 1] + d;
        };

        int aStart = toDay(arriveAlice), aEnd = toDay(leaveAlice);
        int bStart = toDay(arriveBob),   bEnd = toDay(leaveBob);

        int count = max(0,min(aEnd,bEnd) - max(aStart,bStart) + 1);
        return count;
    }
};