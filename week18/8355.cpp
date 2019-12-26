/*
Description
链表是使用指针把一系列结点连接起来的数据结构。它由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。每个结点里的指针指向下一个结点，而链表的入口（head指针）指向第一个结点

现在请你实现一个简单的链表，具体请看头文件

Input
第一行是整数 n

接下来有n行，每行两个整数，代表插入的位置和插入的数据

Output
输入每次插入后的结果

Sample Input
3
0 1
1 2
-1 3
Sample Output
1
1 2
position is not valid
Hint
插入的position是以0计数的，比如当前是 1 2 3

如果输入0 4，则在0号位置插入4，变为 4 1 2 3
如果输入3 5，则在3号位置插入5，变为 1 2 3 5
如果输入不在 [0, size] 区间（size为当前个数），则位置不合法
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
 int value;
 struct node* next;
} node ;

int size; // the size of linked list
node* head; // the head of linkedlist

//insert the value to the right position
//if the position is not valid, return false
//if insert successfully, return true
bool insert(int position, int value){
    if(position>=0 && position<=size){
        node *temp = (node *)malloc(sizeof(node));
        temp->value = value;
        if(position == 0 && size==0){
            head = temp;
            head->next = NULL;
        }
        else if(position == size){
            node *t=head;
            while(t->next !=NULL){
                t=t->next;
            }
            t->next = temp;
            temp->next = NULL;
        }
        else if(position==0){
            temp->next = head;
            head = temp;
        }
        else{
            node *t = head;
            for (int i = 0; i < position-1;i++){
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }
        size++;
        return true;
    }
    else{
        return false;
    }
}

// return the value in the given position
int get(int position){
    node *t = head;
    for (int i = 0; i < position;i++){
        t = t->next;
    }
    return t->value;
}

//clear the linkedlist, remember to free the memory you allocated
void clear(){

}

void print() {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", get(i));
	}
	printf("\n");
}


int main() {
	head = NULL;
	size = 0;
	int n, i, position, value;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &position, &value);
		if (insert(position, value)) {
			print();
		} else {
			printf("position is not valid\n");
		}
	}
	clear();
	return 0;
}