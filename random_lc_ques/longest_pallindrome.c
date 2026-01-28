#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main()
{
    const char *str = "abba";
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    int mid = left + (right - left) / 2;

    int flag = 0;
    while (left <= right)
    {
        if (str[left++] != str[right])
        {
            flag = 1;
            break;
        }
        left++;
        right--;
    }

    if (flag)
    {
        printf("Not a pallindrome");
    }

    else
    {
        printf("is a pallindrome");
    }
    return 0;
}