#include<stack>
#include<assert.h>
/*
定义栈的数据结构。实现一个能得到栈的最小元素min。该栈中，调用min、push和pop时间复杂度都是
O(1)
*/
template <typename T> class StackWithMin{
public:
	StackWithMin(){};
	virtual ~StackWithMin(void){};
 
	T& top();
	const T& top() const;
	void push(const T& e);
	void pop();
	const T& min() const;
private:
	std::stack<T> m_data;
	std::stack<T> min_data;
};
template <typename T> void StackWithMin<T>::push(const T& value){
	m_data.push(value);
	if(min_data.size()==0 || value<min_data.top())
		min_data.push(value);
	else min_data.push(min_data.top());
}
template <typename T> void StackWithMin<T>::pop(){
	assert(m_data.size()>0 && min_data.size()>0);
	m_data.pop();
	min_data.pop();
}
template <typename T> const T& StackWithMin<T>::min() const{
	assert(m_data.size()>0 && min_data.size()>0);
	return min_data.top();
}

int main()
{
    
}