
/*
// varint 编码方式

char final_result[10000];
char i32buf[100];
void writeVarint32(int n){
    int idx = 0;
    while(true){
        if((n & ~0x7F) == 0){ // 没有超过7位
            i32buf[idx++] = reinterpret_cast<char> n;
        }else{ // 超过7位
            i32buf[idx++] = reinterpret_cast<char> ((n & 0x7F) | 0x80); // 最高位置1
        }
        n >>= 7;
    }
    
    // 0~idx为最后所有的字节。
    i32buf[0~idx]为编码的结果。
}
*/


// Zigzag编码方式
int int_to_zigzag(int n)
{
    return (n << 1) ^ (n >> 31);
    // 左移一位-->低位补0.
    // 右移31位-->符号位平铺
    // -->如果正数-->左移一位，最低位0.
    // -->如果负数-->左移一位，

    // 解码方式 (n >> 1) ^ -(n & 1); 后面是取得原来的111111111111
    // 异或性质。
}
