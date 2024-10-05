#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// ENCAPSULATION
class animal
{
private: // perfect encapsulation = all data members are private
    int age;
    int weight;

public:
    void eat()
    {
        cout << "eating" << endl;
    }

    int getAge()
    {
        return this->age;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{

    return 0;
}