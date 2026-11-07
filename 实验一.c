#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INIT_SIZE 5
#define INCREMENT 2
typedef int ElemType;
typedef struct{
	ElemType*elem;
	int length;
	int listsize;
}SqList;
int InitList_Sq(SqList *L)
{   L->elem=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L->elem) return -1;
    L->length=0;
    L->listsize=INIT_SIZE;
    return 1;
}
//2.创建顺序表 
void CreateList_Sq(SqList*L,int n){
	if(n>L->length){
		ElemType*newbase=(ElemType*)realloc(L->elem,n*sizeof(ElemType));
		if(!newbase){
			printf("内存分配失败\n");
			return;
		}
		L->elem=newbase;
		L->listsize=n;
	}
	printf("请输入%d个整数：\n",n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&L->elem[i]);
	} 
	L->length=n;
	printf("顺序表创建成功\n");
}
//3.判断顺序表是否为空
bool IsEmpty_Sq(SqList*L){
	return L->length==0;
} 
//4.计算顺序表长度
int GetLength_Sq(SqList*L){
	return L->length;
} 
//5.输出顺序表的内容
void PrintList_Sq(SqList*L){
	if(IsEmpty_Sq(L)){
		printf("顺序表为空\n");
		return;
	}
	printf("当前顺序表：");
	int i;
	for(i=0;i<L->length;i++){
		printf("%d",L->elem[i]);
	}
	printf("\n");
}
//6.获取位置为position的元素值 
bool GetElem_Sq(SqList*L,int position,ElemType *e){
	if(position<1||position>L->length){
		return false;
	}
	*e=L->elem[position-1];
	return true;
}
//7.顺序查找
int SearchSeq_Sq(SqList*L,ElemType value){
	int i;
	for(i=0;i<L->length;i++){
		if(L->elem[i]==value){
			return i+1;
		}
	}
	return 0;
}
void SortList_Sq(SqList*L){
	int i,j;
	for(i=0;i<L->length-1;i++){
		for(j=0;j<L->length-1-i;j++){
			if(L->elem[j]>L->elem[j+1]){
				ElemType temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;
			}
		}
	}
}
int SearchBinary_Sq(SqList*L,ElemType value){
	int low=0,high=L->length-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(L->elem[mid]==value) return mid+1;
		else if(L->elem[mid]<value) low=mid+1;
		else high=mid-1;
	}
	return 0;
}
//8.在指定位置前插入新元素x
bool InsertElem_Sq(SqList*L,int position,ElemType x){
	if(position<1||position>L->length+1) return false;
	if(L->length>=L->listsize){
		ElemType*newbase=(ElemType*)realloc(L->elem,(L->listsize+INCREMENT)*sizeof(ElemType));
		if(!newbase){
			return false;
		}
		L->elem=newbase;
		L->listsize+=INCREMENT;
	}
	int i;
	for(i=L->length;i>=position;i--){
		L->elem[i]=L->elem[i-1];
	}
	L->elem[position-1]=x;
	L->length++;
	return true;
} 
//9.删除指定位置position的元素
bool DeleteElemByPos_Sq(SqList *L, int position) {
    if (position < 1 || position > L->length) return false; // 位置不合法

    // 从前往后移动元素覆盖
    int i;
    for (i = position; i < L->length; i++) {
        L->elem[i - 1] = L->elem[i];
    }
    L->length--;
    return true;
}

// 10. 删除指定元素值 (删除所有相同元素)
void DeleteElemByValue_Sq(SqList *L, ElemType value) {
    int k = 0;
    int i;
    for (i = 0; i < L->length; i++) {
        if (L->elem[i] != value) {
            L->elem[k] = L->elem[i];
            k++;
        }
    }
    L->length = k; 
}
int main() {
    SqList L;
    
    // 1. 初始化
    if (InitList_Sq(&L) == 1) {
        printf("1. 初始化成功！初始容量: %d\n\n", L.listsize);
    }

    // 2. 创建
    printf("2. 创建顺序表\n");
    CreateList_Sq(&L, 5);
    PrintList_Sq(&L);
    printf("\n");

    // 3 & 4. 判空与长度
    printf("3 & 4. 判空与长度\n");
    printf("是否为空: %s, 当前长度: %d\n\n", IsEmpty_Sq(&L) ? "是" : "否", GetLength_Sq(&L));

    // 6. 获取元素
    printf("6. 获取指定位置元素\n");
    ElemType e;
    if (GetElem_Sq(&L, 3, &e)) {
        printf("第 3 个位置的元素是: %d\n\n", e);
    }

    // 7. 查找 (顺序与二分)
    printf("7. 查找元素\n");
    ElemType findVal;
    printf("请输入要查找的值: ");
    scanf("%d", &findVal);
    int pos1 = SearchSeq_Sq(&L, findVal);
    if (pos1) printf("顺序查找: 元素 %d 在位置 %d\n", findVal, pos1);
    else printf("顺序查找: 未找到 %d\n", findVal);
    
    SortList_Sq(&L); // 二分查找前先排序
    printf("(已排序) ");
    PrintList_Sq(&L);
    int pos2 = SearchBinary_Sq(&L, findVal);
    if (pos2) printf("二分查找: 元素 %d 在排序后位置 %d\n\n", findVal, pos2);
    else printf("二分查找: 未找到 %d\n\n", findVal);

    // 8. 插入
    printf("8. 插入元素\n");
    int insPos, insVal;
    printf("请输入插入位置(1-%d)和值(空格隔开): ", L.length + 1);
    scanf("%d %d", &insPos, &insVal);
    if (InsertElem_Sq(&L, insPos, insVal)) {
        printf("插入成功！\n");
        PrintList_Sq(&L);
    } else printf("插入失败！\n");
    printf("\n");

    // 9. 删除指定位置
    printf("9. 删除指定位置元素\n");
    int delPos;
    printf("请输入要删除的位置: ");
    scanf("%d", &delPos);
    if (DeleteElemByPos_Sq(&L, delPos)) {
        printf("删除成功！\n");
        PrintList_Sq(&L);
    } else printf("删除失败！\n");
    printf("\n");

    // 10. 删除指定值
    printf("10. 删除指定值元素\n");
    int delVal;
    printf("请输入要删除的值: ");
    scanf("%d", &delVal);
    DeleteElemByValue_Sq(&L, delVal);
    printf("删除值为 %d 的元素后：\n", delVal);
    PrintList_Sq(&L);
    free(L.elem);
    
    return 0;
}
