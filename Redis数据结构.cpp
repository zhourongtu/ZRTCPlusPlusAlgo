struct sdshdr{
    // 
    int len;
    int free;
    char buf[];
};

/*
 * 1.获取字符串长度
 * 2.缓冲区溢出
 * 3.内存重分配-->分配方法（1M前后）
 * 4.SDS函数-->二进制方式处理数据
 * 5.使用C的API
*/

typedef struct listNode{
    struct listNode *prev;
    struct listNode *next;
    void *value;
}listNode;

typedef struct list{
    listNode *head;
    listNode *tail;
    unsigned long len;
    void *(*dup)(void *ptr);
    void (*free)(void *ptr);
    int (*match)(void *ptr, void *key);
}list;

/*
 * 双向
 * 无环
 * 双端
 * 长度计数
 * 多态：用特定的函数去表示
*/


typedef struct dictht{
    dictEntry **table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
} dictht;

typedef struct dictEntry{
    void *key;
    union{
        void *val;
        uint64_t u64;
        int64_t s64;
    }v;
    struct dictEntry *next;
} dictEntry;

typedef struct dict{
    dictType *type; // 
    void *privdata; // 传给那些类型特定函数的可选参数
    dictht ht[2];
    int trehashidx; // rehash索引 
}dict;

typedef struct dictType{
    // 计算哈希值的函数
    // 复制键的函数
    // 复制值的函数
    // 对比键的函数
    // 销毁键的函数
    // 销毁值的函数
} dictType;

hash = dict->type->hashFunction(key);
index = hash & dict->ht[x].sizemask;


跳跃表的实现
https://github.com/icetoggle/zskiplist

跳跃表
    头、尾巴、层数最大的结点层数、长度
    
    结点
        层（前进指针、跨度）、后退指针、分值、成员对象


整数集合
typedef struct intset{
    uint32_t encoding;
    uint32_t length;
    int8_t contents[];
};

压缩列表
zlbytes
zltail
zllen
entry1
entry...
zlend

压缩列表结点
previous_entry_length // 可1可5
encoding // 字节数组编码方式（字节）。整数编码方式
content // 根据编码。

对象
typedef struct redisObject{
    unsigned type:4; // 类型 --> 五种类型
    unsigned encoding:4; // 编码 --> 八种编码-->对应不同的底层数据结构
    void *ptr; //指向底层实现数据结构的指针
}robj;

string-->3。INT、
            EMBSTR、//直接顺序存储
            RAW
// SET、GET、APPEND、INCRBYFLOAT、DECRBY、STRLEN、SETRANGE、GETRANGE
list-->2。ZIPLIST、LINKEDLIST
HASH-->2。ZIPLIST、HT（字典实现的哈希对象）
SET-->2。INTSET、HT（字典实现的集合对象）
ZSET-->2。ZIPLIST、SKIPLIST(跳跃表+字典)


