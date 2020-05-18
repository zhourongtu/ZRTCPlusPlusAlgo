#include "head.h"
#include <stack>

/*
利用栈的优先级建树
*/
using namespace std;
typedef enum
{
    MY_OPERATOR,
    MY_OPERAND
} DataTag;

typedef struct node
{
    DataTag Tag;
    union {
        int my_operand;
        char my_operator;
    } data;
    struct node *Left, *Right;
} TreeNode, *NodePtr;

/*
栈内优先级，引入优先级
lparen, rparen, plus, minus, times, divide, mod, eos
*/
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0}; //in_stack_precedence
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int GetValueFromTree(NodePtr T);
void PostTraverse(TreeNode *T);
void PreTraverse(TreeNode *T);
void InTraverse(TreeNode *T);
int getISP(char c);
int getICP(char c);

NodePtr CreateNode(DataTag T, void *data)
{
    NodePtr temp;
    temp = (NodePtr)malloc(sizeof(struct node));
    temp->Tag = T;
    temp->Left = NULL;
    temp->Right = NULL;
    if (temp->Tag == MY_OPERAND)
    {
        temp->data.my_operand = *(int *)(data);
    }
    else
    {
        temp->data.my_operator = *(char *)(data);
    }
    return temp;
}

int main()
{
    //文件：存了一个表达式。
    // freopen("GetValueFromTree.txt", "r", stdin);
    std::stack<NodePtr> NodeS;
    std::stack<char> operatorS;
    operatorS.push('#'); //作为结束标识符
    string str;
    // str = "5+6*8+(9+3*3)";
    std::cin >> str;
    int i = 0;
    while (!operatorS.empty() && i < str.length())
    {
        char c = str[i];
        int num; //相当于switch
        if (isdigit(c))
        { //是操作数
            int j = i;
            while (isdigit(str[j]))
            {
                j++;
            }
            num = atoi(str.substr(i, (j - i + 1)).c_str());
            i = j - 1; //处理下一个操作数或者操作符的前，代码简洁
            NodePtr temp;
            temp = CreateNode(MY_OPERAND, (void *)(&num));
            NodeS.push(temp);
        }
        else
        {                                 //操作符
            int currentPrior = getICP(c); //引入优先级即外部优先级
            int interiorPrior = getISP(operatorS.top());
            if (c == ')')
            { //右括号，疯狂建结点，至左括号
                char token = operatorS.top();
                operatorS.pop();
                for (; token != '(';)
                {
                    NodePtr temp = CreateNode(MY_OPERATOR, (void *)(&token)); //得到操作符，建立结点
                    NodePtr Right = NodeS.top();                              //得到右结点
                    NodeS.pop();
                    NodePtr Left = NodeS.top(); //得到左结点
                    NodeS.pop();
                    temp->Left = Left;
                    temp->Right = Right;
                    NodeS.push(temp);
                    //
                    token = operatorS.top();
                    operatorS.pop();
                }
            }
            else if (currentPrior > interiorPrior)
            { //外部优先级更高，操作符入栈
                operatorS.push(c);
            }
            else
            { //内部的优先级>=外部的优先级
                //先处理内部优先级更高的
                while (currentPrior <= interiorPrior)
                { //循环
                    char token = operatorS.top();
                    operatorS.pop();
                    interiorPrior = getISP(operatorS.top()); //修改内部优先级情况,下次使用
                    //利用token建立结点，左括号的
                    NodePtr temp = CreateNode(MY_OPERATOR, (void *)(&token));
                    NodePtr Right = NodeS.top();
                    NodeS.pop();
                    NodePtr Left = NodeS.top();
                    NodeS.pop();
                    temp->Left = Left;
                    temp->Right = Right;
                    NodeS.push(temp);
                }
                operatorS.push(c);
            }
        }
        i = i + 1; //处理下一个数
    }
    while (!operatorS.empty())
    {
        char token = operatorS.top();
        operatorS.pop();
        if (token == '#')
        { //结束
            break;
        }
        else
        {
            NodePtr temp = CreateNode(MY_OPERATOR, (void *)(&token));
            NodePtr Right = NodeS.top();
            NodeS.pop();
            NodePtr Left = NodeS.top();
            NodeS.pop();
            temp->Left = Left;
            temp->Right = Right;
            NodeS.push(temp);
        }
    }
    NodePtr T = NodeS.top(); //结果树
    NodeS.pop();
    // InTraverse(T);
    PostTraverse(T);
    printf("\n");
    int a = GetValueFromTree(T);
    printf("%d", a);
}

int getICP(char c)
{
    switch (c)
    {
    case '(':
        return icp[0];
    case ')':
        return icp[1];
    case '+':
        return icp[2];
    case '-':
        return icp[3];
    case '*':
        return icp[4];
    case '/':
        return icp[5];
    case '%':
        return icp[6];
    case '#':
        return icp[7]; //结束标识符
    }
}

int getISP(char c)
{
    switch (c)
    {
    case '(':
        return isp[0];
    case ')':
        return isp[1];
    case '+':
        return isp[2];
    case '-':
        return isp[3];
    case '*':
        return isp[4];
    case '/':
        return isp[5];
    case '%':
        return isp[6];
    case '#':
        return isp[7]; //结束标识符
    }
}

void InTraverse(TreeNode *T)
{
    if (T == NULL)
        return;
    else
    {
        InTraverse(T->Left);
        if (T->Tag == MY_OPERAND)
        {
            printf("%d", T->data.my_operand);
        }
        else
        {
            printf("%c", T->data.my_operator);
        }
        InTraverse(T->Right);
    }
}

void PreTraverse(TreeNode *T)
{
    if (T == NULL)
        return;
    else
    {
        if (T->Tag == MY_OPERAND)
        {
            printf("%d", T->data.my_operand);
        }
        else
        {
            printf("%c", T->data.my_operator);
        }
        PreTraverse(T->Left);
        PreTraverse(T->Right);
    }
}

void PostTraverse(TreeNode *T)
{
    if (T == NULL)
        return;
    else
    {
        PostTraverse(T->Left);
        PostTraverse(T->Right);
        if (T->Tag == MY_OPERAND)
        {
            printf("%d", T->data.my_operand);
        }
        else
        {
            printf("%c", T->data.my_operator);
        }
    }
}

int GetValueFromTree(NodePtr T)
{
    if (T->Tag == MY_OPERAND)
    {
        return T->data.my_operand;
    }
    else
    { //操作符
        int left = GetValueFromTree(T->Left);
        int right = GetValueFromTree(T->Right);
        int result = 0;
        switch (T->data.my_operator)
        {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        }
        return result;
    }
}
