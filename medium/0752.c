
// 你有一个带有四个圆形拨轮的转盘锁。
// 每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
// 每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
// 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。


// 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// 输出：6
// 解释：
// 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
// 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
// 因为当拨动到 "0102" 时这个锁就会被锁定。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//封装一个字符串用来放密码
const int Slth = 4;

// 入队列
void enQueue(char** q, int* q_rear, char* value){
    char* _tmpValue = (char*)calloc(Slth, sizeof(char));
    memcpy(_tmpValue, value, Slth*sizeof(char));
    q[++(*q_rear)] = _tmpValue;
}

// 出队列
char* deQueue(char** q, int* q_rear){
    if (q_rear < 0) return "\0";

    char* _front = q[0];
    char* value = (char*)calloc(Slth, sizeof(char));
    memcpy(value, _front, Slth*sizeof(char));

    // 元素依次前移
    for (int i=0; i< (*q_rear); i++){
        char* _tmpValue = (char*)calloc(Slth, sizeof(char));
        memcpy(_tmpValue, q[i+1], Slth*sizeof(char));
        q[i] = _tmpValue;
    }
    // 标记减一
    (*q_rear)--;
    return value;
}

void printQueue(char** q, int lth){
    // 打印
    for (int i=0;i<=lth;i++){
        char* value = q[i];
        for (int j=0;j<Slth;j++){
            printf("%c_", value[j]);
        }
        printf("\n");
    }
}

int isEquals(char* a, char* b){
    for (int i=0;i<Slth;i++){
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

int search(char** list/*待搜索列表*/, int listLth/*列表长度*/, char* value/*待查找元素*/){
    for (int i=0;i<listLth;i++){
        if (isEquals(list[i], value)) return 1;
    }
    return 0;
}

char* plusOne(char* value, int j){
    char* _tmpValue = (char*)calloc(Slth, sizeof(char));
    memcpy(_tmpValue, value, Slth*sizeof(char));

    if (_tmpValue[j]=='9'){
        _tmpValue[j]='0';
    }else{
        _tmpValue[j]++;
    }

    return _tmpValue;
}

char* minusOne(char* value, int j){
    char* _tmpValue = (char*)calloc(Slth, sizeof(char));
    memcpy(_tmpValue, value, Slth*sizeof(char));

    if (_tmpValue[j]=='0'){
        _tmpValue[j]='9';
    }else{
        _tmpValue[j]--;
    }

    return _tmpValue;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    int maxLth = 1;
    for(int i=1;i<=deadendsSize;++i) maxLth*=i;

    // 记录穷举过的密码
    char** visited = (char**)calloc(maxLth, sizeof(char*));
    // memset(visited, '\n', maxLth*sizeof(char*));
    int visitedRear = -1;
    // 将deadends 加入已访问的列表，表示不能继续了
    for (int i=0;i<deadendsSize;i++) enQueue(visited, &visitedRear, deadends[i]);

    // 虚拟一个队列
    char** q = (char**)calloc(maxLth, sizeof(char*));
    // memset(q, '\n', maxLth*sizeof(char*));

    int q_rear = -1;

    // 初始状态入队列
    int step = 0;
    enQueue(q, &q_rear, "0000");

    while (q_rear!=-1)
    {

        int size = q_rear;
        for (int i=0;i<=size;i++){
            char* cur = deQueue(q, &q_rear);

            // 跳过已经走过的
            if (search(visited, visitedRear+1, cur)) continue;
            enQueue(visited, &visitedRear, cur);

            // 判断是否结束
            if (isEquals(cur, target)) return step;
            // 将该节点的相邻节点加入队列
            for (int j=0; j<4; j++){
                char* up = plusOne(cur, j);
                if (!search(visited, visitedRear+1, up)) enQueue(q, &q_rear, up);

                char* down = minusOne(cur, j);
                if (!search(visited, visitedRear+1, down)) enQueue(q, &q_rear, down);
            }
        }
        step++;
    }

    return -1;
}


int main(int argc, char const *argv[])
{
    char** deadends = (char**)malloc(5*sizeof(char*));
    deadends[0] = "0201";
    deadends[1] = "0101";
    deadends[2] = "0102";
    deadends[3] = "1212";
    deadends[4] = "2002";

    int deadendsSize = 5;
    char* target = "0001";
    int aa = openLock(deadends, deadendsSize, target);

    printf(">>>: %d\n", aa);
    return 0;
}

// 检查不通过
// gcc -O -g -fsanitize=address 0752.c && ./a.out
