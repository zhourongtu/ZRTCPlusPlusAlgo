#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>

#define BLACKLIST_FILE "...."

char *test = new char[512*1024*1024];
int main()
{

}


// 数据初始化
int init()
{
    FILE* fp = (fopen(BLACKLIST_FILE, "r"));
    if(fp == NULL){
        return -1;
    }
    fgets(test, strlen(test), fp);
    fclose(fp);
    return 0;
}

// 查询IP是否在黑名单。IP由32位无符号整数表示。
bool checkBlackList(uint32_t inputIP)
{
    // inputIP >> 3获取存储的位置。
    // 1左移相应的值，使得特定位置置1
    return test[inputIP >> 3] & (1 << (inputIP & (uint32_t) 7));
}

// 设置黑名单IP的值。找到IP对应的字节，然后使用掩码和位运算设置对应的二进制的值。
void setValue(uint32_t inputIP, bool inputValue)
{
    uint32_t byteIndex = inputIP >> 3;
    char maskByte = (char)(1 << inputIP & (uint32_t)7);
    // 根据input的值，对特定的值置0或者置1。
    test[byteIndex] = (inputValue ? (test[byteIndex] | maskByte) : (test[byteIndex] & (!maskByte)));
    return;
}