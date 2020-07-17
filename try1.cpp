#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int GetNumOfBits1(int x)
{
    int count1 = 0;
    while(x>0){
        if(x & 1){
            count1++;
        }
        x = x >> 1;
    }
    return count1;
}

int main()
{
    // 本质上是考察x可以用的1的个数。
    int T;
    cin >> T;
    long int x;
    for(int i=0; i<T; i++)
    {
        cin >> x;
        long int temp = 1;
        int my_count1 = GetNumOfBits1(x);
        if(my_count1 > 0 && my_count1 < 31){
            cout << ((temp << my_count1)*2) << endl;
        }else if(my_count1 == 31){
            cout << (temp << 31) << endl;
        }
        else{
            cout << 2 << endl;
        }
    }

    return 0;
}
