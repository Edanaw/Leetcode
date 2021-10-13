# Leetcode

## 1. 题目分类


## 2. 最简单易懂的贪心算法


## 3. 玩转双指针
### 3.1 算法解释

   (1) 双指针主要用于遍历数组, 两个指针指向不同的元素, 协同完成任务, 可以衍生到多个数组多个指针.
   (2) 当两个指针指向同一个数组且遍历方向是相同的且不会相交, 称为滑动窗口, (两个指针包住的范围就是就是当前的窗口), 经常用于区间搜索。
   (3) 两个指针执行同一个数组，遍历方向相反，可以用来搜索，待搜索的数组往往是排好序的。

#### 指针和常量
```cpp
int x;
int *p1 = &x;
const int *p2 = &x;
int* const p3 = &x;
const int* const p4 = &x;
```

#### 指针函数和函数指针

```cpp
// 指针函数, 一个返回值类型是指针的函数
int* addition(int a, int b) {
   int* sum = new int(a + b);
   return sum;
}

int substraction(int a, int b) {
   return a - b;
}

int operation(int x, int y, int (*func)(int, int)) {
   return (*func)(x, y);
}
// 函数指针, 指向函数的指针
int (*minus)(int, int) = subtraction;
int *m = addition(1, 2);
int n = operation(3, *m, minus);
```


### 3.2 TWO Sum question

#### 题目描述
      在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。

#### 题解

   因为数组已经是有序的了, 所以我们可以采用方向相反的双指针l,r来寻找这两个数字, 一个指向初始指向的最小值的位置
   一个指向末尾的位置, 判断两个指针指向的值的和结果与target值是否一致, 若一致, 则结正确, 返回相应的下标对应的vector
   若小于目标值的话++l, 否则--r

```cpp
// 针对有序的方案
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int counts = nums.size();
        int l = 0, r = counts - 1, sum;
        
        while (l < r) {
            sum = nums[l] + nums[r];
            if (sum == target) break;
            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return vector<int>{l, r};
    }
};

// 针对有序、无序均可的方案
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            /*
               unordered_map 这个无需容器的find方法,若查找到的话, 则返回key对应的迭代器
               否则返回 unordered_map::end()
            */ 
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

```

### 3.3 归并两个有序数组

#### 题目描述
      给定两个有序数组，把两个数组合并为一个。


   
