# Leetcode
Leetcode刷题
## 1. 大数乘法问题
   #### 思路:  char a[],char b[],int c[],int d[],int res[];
   #### (1) 使用两个字符数组去存储两个整数，然后用两个整型数组去接这个数据的每位的数据;
   #### (2) 最后再用一个整型数组去接这两个整形数组每个位置的计算结果, 具体的实现方式看代码;
   #### (3) 遍历结果判断, 如果第i位的结果 >= 10, res[i+1] += res[i] / 10; res[i] %= 10;
   #### (4) 否则就遍历下一位数据，直到所有的数据全部遍历完;
   #### (5) 最后的得到的结果进行一个前端0的处理工作，然后从后向前的打印出每一个位置的值;

   #### 具体细节的实现请参考源代码 bigNumber.c



  
