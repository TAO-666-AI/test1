#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 100
#define ERROR -1
#define OK 1
typedef int ElemType;
typedef struct {
    ElemType elem[MAX];
    int last;
} SeqList;

int CreateList(SeqList* L, int n) {
    if (n < 0) {
        return(ERROR);
    }
    L->last = n - 1;
    printf("请输入顺序表的值：\n");
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &(L->elem[i - 1])) != 1) {
            printf("输入格式错误，请重新输入！\n");
            return ERROR;
        }
    }
    return(OK);
}

int LocateList(SeqList* L, ElemType e) {
    int i = 1;
    while ((i <= L->last + 1) && (L->elem[i - 1] != e))
        i++;
    if (i <= L->last + 1)
        return i;
    else
        return ERROR;
}
int InsList(SeqList* L, int i, ElemType e) {
    int k;
    if (L->last + 1 >= MAX) {
        return (ERROR + 1);
    }
    if ((i < 1) || (i > L->last + 2)) {
        return ERROR;
    }
    for (k = L->last + 1; k >= i; k--) {
        L->elem[k] = L->elem[k - 1];
    }
    L->elem[i - 1] = e;
    L->last++;
    return(OK);
}

int DelList(SeqList* L, int i, ElemType* e) {
    int k;
    if ((i < 1) || (i > L->last + 1)) {
        return(ERROR);
    }
    *e = L->elem[i - 1];
    for (k = i; k <= L->last; k++) {
        L->elem[k - 1] = L->elem[k];
    }
    L->last--;
    return(OK);
}

void PrintfList(SeqList* L) {
    int i;
    for (i = 1; i <= L->last + 1; i++) {
        printf("%d ", L->elem[i - 1]);
    }
    printf("\n");
}

int LenList(SeqList* L) {
    int  num = 0;
    num = L->last + 1;
    return num;
}

void RevList(SeqList* L) {
    int i, tmp;
    for (i = 0; i < LenList(L) / 2; i++) {
        tmp = L->elem[i];
        L->elem[i] = L->elem[LenList(L) - 1 - i];
        L->elem[LenList(L) - 1 - i] = tmp;
    }
}
void SortList(SeqList* L) {
    int i, j, tmp;
    for (i = L->last; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (L->elem[j] > L->elem[j + 1]) {
                tmp = L->elem[j];
                L->elem[j] = L->elem[j + 1];
                L->elem[j + 1] = tmp;
            }
        }
    }
}

SeqList SelList(SeqList  L1, SeqList  L2) {
    printf("请选择顺序表1还是顺序表2,若是表1，输入数字1；表2则输入数字2\n");
    int order;
    while (scanf("%d", &order) != 1 || (order != 1 && order != 2)) {
        printf("输入错误，请重新输入！\n");
        while (getchar() != '\n'); // 清除输入缓冲区
    }
    SeqList L;
    if (order == 1)
        L = L1;
    else if (order == 2)
        L = L2;
    return L;
}

int MergeList(SeqList* LA, SeqList* LB, SeqList* LC) {
    if (LA->last + LB->last + 1 >= MAX) {
        return ERROR; 
    }
    int i = 0, j = 0;
    LC->last = -1;
    while (i <= LA->last && j <= LB->last) {
        if (LA->elem[i] <= LB->elem[j]) {
            LC->elem[++(LC->last)] = LA->elem[i];
            i++;
        }
        else {
            LC->elem[++(LC->last)] = LB->elem[j];
            j++;
        }
    }
    while (i <= LA->last) {
        LC->elem[++(LC->last)] = LA->elem[i];
        i++;
    }
    while (j <= LB->last) {
        LC->elem[++(LC->last)] = LB->elem[j];
        j++;
    }
    return OK;
}

int main() {
    SeqList L1, L2, L3;
    int n1, n2;
    printf("请输入第一个顺序表的初始长度:\n");
    while (scanf("%d", &n1) != 1 || CreateList(&L1, n1) == ERROR) {
        printf("顺序表的长度不得小于0，请重新输入：\n");
        while (getchar() != '\n'); // 清除输入缓冲区
    }
    printf("请输入第二个顺序表的初始长度:\n");
    while (scanf("%d", &n2) != 1 || CreateList(&L2, n2) == ERROR) {
        printf("顺序表的长度不得小于0，请重新输入：\n");
        while (getchar() != '\n'); // 清除输入缓冲区
    }
    int choice;
    do {
        SeqList L;
        int num;
        ElemType e;
        printf("插入元素--1，删除元素--2，查找元素--3，求顺序表长度--4，逆置--5，从小到大排序--6，合并两个有序顺序表--7，退出--0\n");
        while (scanf("%d", &choice) != 1) {
            printf("输入错误，请重新输入！\n");
            while (getchar() != '\n'); // 清除输入缓冲区
        }
        switch (choice) {
        case 1:
            L = SelList(L1, L2);
            int i, _e;
            printf("请输入要插入的位置：\n");
            while (scanf("%d", &i) != 1) {
                printf("输入错误，请重新输入！\n");
                while (getchar() != '\n'); // 清除输入缓冲区
            }
            printf("请输入要插入的值：\n");
            while (scanf("%d", &_e) != 1) {
                printf("输入错误，请重新输入！\n");
                while (getchar() != '\n'); // 清除输入缓冲区
            }
            num = InsList(&L, i, _e);
            while (num == ERROR + 1 || num == ERROR) {
                if (num == ERROR + 1) {
                    printf("表已满，无法插入！\n");
                    break;
                }
                else {
                    printf("插入的位置错误，请重新输入：\n");
                    printf("请输入要插入的位置：\n");
                    while (scanf("%d", &i) != 1) {
                        printf("输入错误，请重新输入！\n");
                        while (getchar() != '\n'); // 清除输入缓冲区
                    }
                    printf("请输入要插入的值：\n");
                    while (scanf("%d", &_e) != 1) {
                        printf("输入错误，请重新输入！\n");
                        while (getchar() != '\n'); // 清除输入缓冲区
                    }
                }
            }
            PrintfList(&L);
            break;
        case 2:
            L = SelList(L1, L2);
            printf("请输入要删除的位置：\n");
            while (scanf("%d", &i) != 1) {
                printf("输入错误，请重新输入！\n");
                while (getchar() != '\n'); // 清除输入缓冲区
            }
            while (DelList(&L, i, &e) == ERROR) {
                printf("要删除的位置非法，请重新输入：\n");
                while (scanf("%d", &i) != 1) {
                    printf("输入错误，请重新输入！\n");
                    while (getchar() != '\n'); // 清除输入缓冲区
                }
            }
            PrintfList(&L);
            break;
        case 3:
            L = SelList(L1, L2);
            printf("请输入要找的元素的值：\n");
            while (scanf("%d", &e) != 1) {
                printf("输入错误，请重新输入！\n");
                while (getchar() != '\n'); // 清除输入缓冲区
            }
            if (LocateList(&L, e) == ERROR) {
                printf("找不到这个元素！\n");
            }
            else {
                printf("这个元素在顺序表中的位置为%d\n", LocateList(&L, e));
            }
            break;
        case 4:
            L = SelList(L1, L2);
            printf("顺序表的长度为:%d\n", LenList(&L));
            break;
        case 5:
            L = SelList(L1, L2);
            RevList(&L);
            PrintfList(&L);
            break;
        case 6:
            L = SelList(L1, L2);
            SortList(&L);
            PrintfList(&L);
            break;
        case 7:
            SortList(&L1);
            SortList(&L2);
            if (MergeList(&L1, &L2, &L3) == OK) {
                PrintfList(&L3);
            }
            else {
                printf("合并失败，合并后顺序表元素数量超过最大容量！\n");
            }
            break;
        case 0:
            printf("退出循环\n");
            break;
        default:
            printf("输入错误\n");
            break;
        }
    } while (choice);
    return 0;
}