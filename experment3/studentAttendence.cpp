#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int,int> mp;
    mp[0] = -1;

    int sum = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        char x;
        cin >> x;

        if(x == 'P') sum++;
        else sum--;

        if(mp.count(sum))
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }

    cout << ans;
}
