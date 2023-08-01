#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_items, num_groups;
    cin >> num_items >> num_groups;

    vector<int> items(num_items);
    for (int i = 0; i < num_items; ++i) {
        cin >> items[i];
    }

    vector<int> group_sizes(num_groups);
    for (int i = 0; i < num_groups; ++i) {
        cin >> group_sizes[i];
    }

    sort(items.rbegin(), items.rend());

    int max_profit = 0;
    int idx = 0;
    for (int i = 0; i < num_groups; ++i) {
        int group_size = group_sizes[i];
        while (idx < num_items && group_size > 0) {
            max_profit += items[idx];
            idx++;
            group_size--;
        }
    }

    cout << max_profit << endl;

    return 0;
}
 