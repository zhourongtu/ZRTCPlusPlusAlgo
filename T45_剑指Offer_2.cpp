#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    int LastRemaining(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
            return -1;
        list<int> numbers;
        for(int i=0; i<n; ++i)
            numbers.push_back(i);
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            for(int i=1; i<m; ++i){
                current++;
                if(current == numbers.end())
                    current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if(next==numbers.end())
                next = numbers.begin();
            --current;
            numbers.erase(current);
            current = next;
        }
        return *(current);
    }
};
int main()
{
    Solution s;
    cout << s.LastRemaining(5, 3);
    return 0;
}
