//2491. Divide Players Into Teams of Equal Skill
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
#define ll long long

ll dividePlayers(vector<int> &skill)
{
    sort(skill.begin(), skill.end());
    int i = 1;
    int j = skill.size() - 2;
    ll sum = skill[0] + skill[skill.size() - 1];
    ll count = 0;
    ll mul = skill[0] * skill[skill.size() - 1];
    while (i < j)
    {
        if (skill[i] + skill[j] == sum)
        {
            mul += skill[i] * skill[j];
            count++;
        }
        ++i, --j;
    }
    if (count + 1 == skill.size() / 2)
    {
        return mul;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << dividePlayers(arr);
    return 0;
}