#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
 * 视野总和。
 * 能看到最远的那个人的下标。
*/
class Solution{
public:
    int SeeFarthest(int N, vector<int> height)
    {
        if(N == 1)return 0;
        stack<int> single_stack;
        vector<int> people_who_higher(N);
        // 1第一步。第一个人push进去
        single_stack.push(0);
        for(int i=1; i<N; i++){
            if(height[single_stack.top()] > height[i]){
                single_stack.push(i);
            }
            else{
                while(!single_stack.empty() && height[single_stack.top()] <= height[i]){
                    people_who_higher[single_stack.top()] = i;
                    single_stack.pop();
                }
                single_stack.push(i);
            }
        }
        while(!single_stack.empty()){
            people_who_higher[single_stack.top()] = N-1;
            single_stack.pop();
        }
        int max_see = 0;
        int max_count_see = 0;
        for(int i=0; i<N; i++){
            max_see = max(max_see, people_who_higher[i]-i);
            max_count_see += people_who_higher[i]-i;
        }
        for_each(people_who_higher.begin(), people_who_higher.end(), [](int a){ cout << "\t" << a;});
        cout << endl;
        cout <<"max_count see : " << max_count_see << endl;;
        return max_see;
    }
};
int main()
{
    Solution s;
    // int N = 5;
    // vector<int> height = {167, 168, 165, 162, 161};
    int N = 4;
    vector<int> height = {4, 3, 7, 1};
    
    cout << s.SeeFarthest(N, height);
    return 0;
}
