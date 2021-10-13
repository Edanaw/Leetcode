/*
 * @Author: your name
 * @Date: 2020-12-12 22:08:13
 * @LastEditTime: 2021-04-29 21:43:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\bigNumber.c
 */
#ifndef __BIGNUMBER__H__
#define __BIGNUMBER__H__

#include <stdio.h>
#include <string.h>

char *stdin_get_str(char *str);
void BigNumberMul(char a[], char b[]);

#define U_MAX 220
#define ADD_MAX 240
#define MUL_MAX 440

char a[U_MAX], b[U_MAX];
int c[U_MAX], d[U_MAX];
int result[MUL_MAX];

char *stdin_get_str(char *str);
void BigNumberMul(char a[], char b[]);
/*
    fgets() 不能直接使用代替gets() , 因为他会把 '/n' 也接收了，
    所以需要重新封装一下，当fgtes接收的字符串的结束是 '/n' 将其改为
    字符串结束标志 '\0', 所以封装了一个实现gets()功能的函数stdin_get_str()
*/

char *stdin_get_str(char *str)
{
    fgets(str, U_MAX, stdin);
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    return str;
}

void BigNumberMul(char *a, char *b)
{
    int i = 0, j = 0, lena, lenb, n;

    memset(c, 0, sizeof(c)); //对数组进行初始化
    memset(d, 0, sizeof(d));
    memset(result, 0, sizeof(result));
    lena = strlen(a);
    lenb = strlen(b);
    n = lena > lenb ? lena : lenb;

    for (j = 0, i = lena - 1; i >= 0; i--) // 把字符数组倒序转换到数字数组中（满足我们的计算习惯）
        c[j++] = a[i] - '0';

    for (j = 0, i = lenb - 1; i >= 0; i--)
        d[j++] = b[i] - '0';

    for (i = 0; i < lena; i++)
        for (j = 0; j < lenb; j++)
            result[i + j] += c[i] * d[j]; // i * j的结果要保存在i + j的位置
    
    for (i = 0; i < n * 2; i++) {
        // 处理进位
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    i = n * 2 - 1;
    while (result[i] == 0)
        i--; //处理前端零
    while (i >= 0) {
        printf("%d", result[i]);
        i--;
    }

    printf("\n");
}

#endif //!__BIGNUMBER__H__