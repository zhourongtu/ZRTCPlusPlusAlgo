// 方法1：桶数-->两次遍历。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_1 = 0, count_2 = 0, count_0 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                count_0++;
            }else if(nums[i] == 1){
                count_1++;
            }else if(nums[i] == 2){
                count_2++;
            }
        }
        int i=0;
        while(count_0 > 0 || count_1 > 0 || count_2 > 0){
            if(count_0){
                count_0--;
                nums[i++] = 0;
            }else if(count_1){
                count_1--;
                nums[i++] = 1;
            }else if(count_2){
                count_2--;
                nums[i++] = 2;
            }
        }
        return;
    }
};

// 方法2：
//  ·p0指向0（cur碰到0交换）
//  ·p2指向2（cur碰到2交换）
class Solution {
  public:
  /*
  荷兰三色旗问题解
  */
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};