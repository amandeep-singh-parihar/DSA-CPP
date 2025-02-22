// fill the whole array with any one value

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  // const int SIZE = 5;
  int arr[10];

  // initialize the entire array with one value
  fill(arr, arr + 3, 9);

  // print the array
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
