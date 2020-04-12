#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef struct _ACNode{
    _ACNode *child[26] = {NULL};//字典树
    _ACNode *fail = NULL;     //fail指针
    vector<int> exist;
}ACNode;
void insertTrie(ACNode &root, string &str, int index);
void build(ACNode &root);
void query(ACNode &root, string &str);
//假设是小写的字典树

int main()
{
    vector<string> str_set = {"his", "her", "hers", "he", "she"};
    string T = "hisishersgirlsherls";
    ACNode root;
    for(int i=0; i<str_set.size(); i++){
        insertTrie(root, str_set[i], 0);//从头开始插入
    }
    //已经建立了一棵字典树
    //开始建立fail指针，及exist扩充
    build(root);
    query(root, T);
}

void build(ACNode &root){
    //如何来建立相应的fail指针呢？使用BFS算法
    //1.初始化-->root的fail指向空root的孩子，指向root
    queue<ACNode*> q;
    for(int i=0; i<26; i++){
        if(root.child[i] != NULL){
            q.push(root.child[i]);
            root.child[i]->fail = &root;
        }
    }
    //2.对队列中每一个元素，更新fail，由其父节点的fail查看是否有 fa-->child的这字母
    while(!q.empty()){
        //父亲节点
        ACNode *x = q.front();
        ACNode *temp_x = x;
        q.pop();
        for(int i=0; i<26; i++){
            if(x->child[i]){
                ACNode *y = x->child[i];
                ACNode *fafail = x->fail;
                while(fafail && NULL == fafail->child[i]){
                    //递归获得可匹配的失败结点
                    fafail = fafail->fail;
                }
                if(fafail == NULL){//root没这个节点
                    y->fail = &root;
                }else{//fafail存在这个节点
                    y->fail = fafail->child[i];
                    //同时还要更新exist
                    if(y->fail->exist.size()){//放在外面是一样的
                        for(int j=0; j<y->fail->exist.size(); j++){
                            y->exist.push_back(y->fail->exist[j]);
                        }
                    }
                }
                q.push(x->child[i]);
            }
        }
    }
    q.push(&root);
}

void query(ACNode &root, string &str){
    ACNode *temp = &root;
    //temp代表查找树当前状态
    cout << str << endl;//输出该字符
    for(int i=0; i<str.length(); i++){
        //先查找
        int c = str[i]-'a';//字符所代表下标
        while(NULL == temp->child[c] && temp->fail){
            //没有root节点，可寻father
            temp = temp->fail;
        }
        //!! if和else不可调换顺序，因为temp为root时可能同时不满足两个条件
        //   temp为root-->不判断第一个条件是否满足
        if(temp->child[c]){
            temp = temp->child[c];
        }else{//有两种情况，一种是temp->fail==NULL且
            continue;
        }
        //再状态
        if(temp->exist.size()){//当前状态有单词出现
            for(int j=0; j<temp->exist.size(); j++){
                int len = temp->exist[j];
                for(int k=0; k<i-len+1; k++){cout << " ";}//输出空白对齐
                cout << string(str.begin()+(i-len+1), str.begin()+i+1) << endl;
            }
        }
    }
}

void insertTrie(ACNode &root, string &str, int index){//当前指向的str中字符位置
    //判断是否越界
    if(index == str.length()){
        root.exist.push_back(index);//即长度
        return;
    }
    //将一个字符插入
    int pos = str[index] - 'a';
    if(root.child[pos] == NULL){//不存在这个结点
        ACNode *temp = NULL;
        temp = new ACNode;
        root.child[pos] = temp; //建立这条边
    }
    // //插入下一个字符
    insertTrie(*root.child[pos], str, index+1);
}