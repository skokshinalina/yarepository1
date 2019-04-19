#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>

typedef struct node
{
  int data;
  struct node * left;
  struct node * right;
  struct node * parent;
} node;
typedef struct tree
{
  struct node * root;  
  int count;            
} tree;
void init(tree * t)
{
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}
int find(tree* t, int value, node* no1)
{
  struct node * no2;
  no2 = t->root;

  if (t->root == NULL){
    return 1;
  }

  while (1){
    if (no2 == NULL) {
      return 1;
    } else if (no2->data == value){
      no1->data = no2->data;
      no1->left = no2->left;
      no1->right = no2->right;
      no1->parent = no2->parent;
      return 0;
    } else if (value > no2->data){
      no2 = no2->right;
    } else {
      no2 = no2->left;
    }
  }
  return 1;
}
int insert(tree* t, int value)
{
  struct node * no1, ** no1no1, * last_no1 = NULL;

  struct node * e_n;
  e_n = malloc(sizeof * e_n);

  int err = find(t, value, e_n);
  if (err == 0){
    return 1;
  }
  no1no1 = &t->root;
  no1 = t->root;
  while (1){
    if (no1 == NULL) {
      no1 = *no1no1 = malloc(sizeof * no1);
      if (no1 != NULL){
        no1->data = value;
        no1->left = NULL;
        no1->right = NULL;
        no1->parent = last_no1;
        t->count++;
        return 0;
      } else {
        return 2; 
      }
    }
    last_no1 = no1; 
    if (value > no1->data){
      no1no1 = &no1->right;
      no1 = no1->right;
    } else {
      no1no1 = &no1->left;
      no1 = no1->left;
    }
  }
  return 0;
}
int _remove(tree* t, int value){
  node * no1 = t->root;
  if (t->root == NULL){
    return 1;
  }
  while (1){
    if (no1 == NULL) {
      break;
      return 1;
    } else if (no1->data == value){
      break;
    } else if (value > no1->data){
      no1 = no1->right;
    } else {
      no1 = no1->left;
    }
  }
  if ((no1->left == NULL) && (no1->right == NULL)){
    if (no1->parent->right->data == no1->data){
      no1->parent->right = NULL;
    } else {
      no1->parent->left = NULL;
    }
  } else if (no1->right == NULL){
    *no1 = *no1->left;
  } else if (no1->left == NULL){
    *no1 = *no1->right;
  } else {
    node * search = no1->right;
    int min_value;
    node *min;
    while (1)
   {
      if (search == NULL) {
        break;
      } else {
        min = search;
        min_value = search->data;
        search = search->left;
      }
    }
    no1->data = min->data;
    no1 = min;
    if ((no1->left == NULL) && (no1->right == NULL)){
      if (no1->parent->right->data == no1->data){
        no1->parent->right = NULL;
      } else {
        no1->parent->left = NULL;
      }
    } else if (no1->right == NULL){
      *no1 = *no1->left;
    } else {
      *no1 = *no1->right;
    }
  }


  t->count--;
  return 0;
}
int deepness(struct node * no1, int deep){
  if (no1 == NULL){
    return deep;
  }
  int d1 = deepness(no1->left, deep + 1);
  int d2 = deepness(no1->right, deep + 1);
  return (d1 > d2) ? d1 : d2;
}
void printNode(struct node * no1, int current, int deep, int first){
  if (current == deep){
      if (first > 0){
        printf(" ");
      }
    if (no1 == NULL){
      printf("_");
    } else{
      printf("%d", no1->data);
    } 
  } else if (no1 != NULL){
    printNode(no1->left, current + 1, deep, first);
    printNode(no1->right, current + 1, deep, first + 1);
  } else {
    printNode(no1, current + 1, deep, first);
    printNode(no1, current + 1, deep, first + 1);
  }
}
void print(struct node * no1)
{
  int m = deepness(no1, 0);
  for (int i = 1; i <= m; i++){
    printNode(no1, 1, i, 0);
    printf("\n");
  }
}   
void printTree(struct tree * t)
{
    print(t->root);
}
void dump(struct node * no1){
  if (no1 != NULL){
    printf("%d ", no1->data);
    dump(no1->left);
    dump(no1->right);
  } else {
  }
}
int removeMin(node* no1){

  if (no1->left == NULL){
    no1 = no1->right;
  }
  while(1)
 {
    if (no1->left == NULL){
      if ((no1->left == NULL) && (no1->right == NULL)){
        if (no1->parent->right->data == no1->data){
          no1->parent->right = NULL;
        } else {
          no1->parent->left = NULL;
        }
      } else if (no1->right == NULL){
        *no1 = *no1->left;
      } else {
        *no1 = *no1->right;
      }
      return no1->data;
    } else {
      no1 = no1->left;
    }

  }
}
int rotateRight(tree * t, node *x){
  node * y = x->left;
  if ((y != NULL) && (x != NULL)){
    x->left = y->right;
  
    if (y->right != NULL){
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL){
      if (x->parent->left == x){
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    }
    t->root = y;
    y->right = x;
    x->parent = y;
    return 0;
  } else {
    return 1;
  }
}

int rotateLeft(tree * t, node *x){
  node * y = x->right;
  if ((y != NULL) && (x != NULL)){
    x->right = y->left;
    if (y->left != NULL){
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL){
      if (x->parent->right == x){
        x->parent->right = y;
      } else {
        x->parent->left = y;
      }
    }
    t->root = y;
    y->left = x;
    x->parent = y;

    return 0;
  } else {
    return 1;
  }
}

int main(){

  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 4; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  for (int i = 0; i < 3; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);

  int m1;
  scanf("%d", &m1);
  struct node * no1;
  no1 = malloc(sizeof * no1);
  find(t, m1, no1);
  if (no1->parent != NULL){
    printf("%d ", no1->parent->data);
  } else {
    printf("_ ");
  }
  if (no1->left != NULL){
    printf("%d ", no1->left->data);
  } else {
    printf("_ ");
  }
  if (no1->right != NULL){
    printf("%d\n", no1->right->data);
  } else {
    printf("_\n");
  }
  int m2;
  scanf("%d", &m2);
  int err = find(t, m2, no1);
  if (err == 1){
    printf("-\n");
  } else {
    if (no1->parent != NULL){
      printf("%d ", no1->parent->data);
    } else {
      printf("_ ");
    }
    if (no1->left != NULL){
      printf("%d ", no1->left->data);
    } else {
      printf("_ ");
    }
    if (no1->right != NULL){
      printf("%d\n", no1->right->data);
    } else {
      printf("_\n");
    }
  }
  int m3;
  scanf("%d", &m3);

  _remove(t, m3);
  printTree(t);
  while (rotateLeft(t, t->root) != 1);
  printTree(t);
  while (rotateRight(t, t->root) != 1);
  printTree(t);
  printf("%d\n", t->count);
  printf("-\n");
  return 0;
}
