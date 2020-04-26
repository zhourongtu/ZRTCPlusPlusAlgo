#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
/*
用两个栈实现一个队列。
插入到尾部，拿出头部
思路：一个栈用于加入数据。另一个栈用于出数据。
1.加入数据到stack1尾部。
2.出数据时，先出stack2，若为空，则将stack1倒入。
*/
template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
int main(){
    ;
}
