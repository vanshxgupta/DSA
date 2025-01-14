#include <vector>
#include <algorithm>

class Solution {
    struct meeting {
        int start;
        int end;
        int pos;
    };

    static bool comparator(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else return m1.pos < m2.pos;
    }

public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n) {
        std::vector<meeting> meet(n);
        for (int i = 0; i < n; i++) {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i + 1;
        }

        // Sorting the meetings based on end times and position
        std::sort(meet.begin(), meet.end(), comparator);

        int limit = meet[0].end;
        int cnt = 1;  // Start counting from the first meeting

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                cnt++;
            }
        }

        return cnt;
    }
};