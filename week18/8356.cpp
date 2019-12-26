#include <stdio.h>

typedef struct node{
    int num;
    struct node *next;
}node;

struct node* createList(struct node list[],int n){//改成struct node list*没过
    for (int i = 0; i < n-1;i++){
        list[i].next = &(list[i + 1]);
    }
    return list;
}
int array[100100] = {0};

struct node list[1010];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &list[i].num);
    list[i].next = NULL;
  }

  node* head = createList(list, n);

  while (head != NULL) {
    printf("%d ", head->num);
    head = head->next;
  }
  printf("\n");

  return 0;
}