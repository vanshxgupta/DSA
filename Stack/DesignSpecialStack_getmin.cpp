//METHOD 1:O(N)->S.C AND O(1)->T.C

// #include <stack>
// #include <limits.h>

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     std::stack<int> s;
//     std::stack<int> min;

//     MinStack() {
//         int mini = INT_MAX;
//         min.push(mini);
//     }

//     void push(int val) {
//         s.push(val);
//         if (val <= min.top()) {
//             min.push(val);
//         }
//     }

//     void pop() {
//         if (s.top() == min.top()) {//agar stack mai se jo pop kar rahe hai , vo minimum element ke barbar hai tooh mini wale ko bhi pop krdo kyunki vo ab minimum nahi reh payega 
//             min.pop();
//         }
//         s.pop();// if condition chle ya na chle , stack mai se tooh pop hoga hi 
//     }

//     int top() {
//         return s.top();
//     }

//     int getMin() {
//         return min.top();
//     }
// };



//METHOD 2:O(1)->S.C AND O(1)->T.C

class SpecialStack {
    stack<int> s;
    int mini;
public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else if (data < mini) {
            int val=2 * data - mini;
            mini = data;
            s.push(val);
        } else {
            s.push(data);
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        }

        int curr = s.top();
        s.pop();
        if (curr < mini) {
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        }

        return mini;
    }
};
