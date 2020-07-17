#include <stdio.h>
#include <stdlib.h>

#define ZSKIPLIST_MAXLEVEL 32
#define ZSKIPLIST_P 0.25
#include <math.h>

// Redis的跳表
// 保存了key，value的键值对。定义最大层级32
typedef struct zskiplistNode{
    int key;
    int value;
    struct zskiplistLevel{
        struct zskiplistNode *forward;
    }level[1];
} zskiplistNode;

typedef struct zskiplist{
    struct zskiplistNode *header;
    int level;
} zskiplist;

zskiplistNode *zslCreateNode(int level, int key, int value)
{
    zskiplistNode *zn = (zskiplistNode*)malloc(sizeof(*zn) + level*sizeof(zn->level));
    zn->key = key;
    zn->value = value;
    return zn;
}

zskiplist *zslCreateNode(void){
    int j;
    zskiplist *zsl;
    zsl = (zskiplist *)malloc(sizeof(*zsl));
    zsl->level = 1;
    zsl->header = zslCreateNode(ZSKIPLIST_MAXLEVEL, NULL, NULL);
    for(j = 0; j<ZSKIPLIST_MAXLEVEL; j++){
        zsl->header->level[j].forward = NULL;
    }
    return zsl;
}
