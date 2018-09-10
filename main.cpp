#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Queens8 {
    int a[9] = {0}; // 这个地方，好巧妙！
    // 巧妙地利用数字来代替所表示的行数，极大的节约了内存。
    int n = 8, cnt = 0;
public:
    void queen8(int k) {
        int i = 0;
        if (k > this->n) {
            cout << "the" << ++this->cnt << "condition" << endl;
            for (int i = 1; i < this->n; i++) {
                cout << this->a[i];
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n; i++) {
                a[k] = i;
                if (this->isConfict(a, k)) {
                    queen8(k + 1);//不冲突
                }
            }
        }
        return;
    }

private:
    bool isConfict(int a[], int n) {
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if ((a[i] == a[j]) || (abs(a[i] - a[j] == i - j)))
                    return false;
            }
        }
        return true;
    }
};

class AllNum {

    int n = 10;
    int last = 6;

    vector<int> v;
    vector<string> result;
    int mins = 0, hours = 0;
    string ans = "";

public:
    int allCount = 0;

    void backTrace(int k, int start) {
        int i = 0;
        if (k < this->last) {
            if (start < n && (this->last - k) <= (n - start)) {
                v.push_back(start);
                backTrace(k + 1, start + 1);
                v.pop_back();
                backTrace(k, start + 1);
            } else {
                return;
            }
        } else {
//            for (int i = 0; i < v.size(); i++) {
//                cout << v[i];
//            }
            for (int i = 0; i < v.size(); i++) {
                if (v[i] < 6)
                    mins += (1 << v[i]);
                else hours += (1 << v[i] - 6);
            }
            if (mins > 59 || hours > 11) {
                mins = 0;
                hours = 0;
                return;

            }
            ans = "";
            ans += to_string(hours);
            ans += ":";
            ans += to_string(mins / 10) + to_string(mins % 10);
            mins = 0;
            hours = 0;

            allCount++;

            cout << ans << endl;
        }
        return;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
//    Queens8 q;
//    q.queen8(1);
    AllNum a;
    a.backTrace(0, 0);
    cout << a.allCount << endl;
    return 0;
}