    #include "stdio.h"
    #include "stdlib.h"
    #define true 1
    #define false 0

typedef struct nd {
        int value;
        struct nd* prev;
        struct nd* left;
        struct nd* right;
        int visit;
    }nd;
typedef struct tree {
      struct nd* root;
      int count;
    }tree;
typedef struct l_nd {
        struct nd *value;
        struct l_nd *next;
    }l_nd;
typedef struct list {
        l_nd *tail;
        l_nd *head;
    }list;

void listInit(list* l){
        l->head = NULL;
        l->tail = NULL;
    }
int listEmpty(list *l){
      int visit = (l->tail==NULL);
      return visit;
    }
int push_front(list *l,nd* value){
    l_nd *temp = malloc(sizeof(nd));
    temp->value = value;
    if(l->head==NULL && l->tail==NULL)
    {
        l->tail=temp;
        l->head=temp;
        temp->next = NULL;
        return 0;
    }
    else
    {
       l_nd *ptr = l->head;
       temp->next = ptr;
       l->head = temp;
       return 0;
    }
    return 1;
 }
nd* removeFirst(list *l){
      l_nd *headptr = l->head;
      nd *tmp = l->head->value;

      l->head = l->head->next;

      if(l->head==NULL)
          l->tail=NULL;

      free(headptr);

      return tmp;
  }
void init(tree *t){ 
        t->count = 0;
        t->root = NULL;
    }

int find(tree *t,int value,nd *n){
       nd *ndptr = t->root;
       if(!ndptr){return 1;}
       else
       {
           while(ndptr!=NULL)
           {

               if(value > ndptr->value)
               {
                 ndptr = ndptr->right;continue;
               }
               if(value < ndptr->value)
               {
                 ndptr = ndptr->left; continue;
               }
               if (value == ndptr->value)
               {
                   if(n == NULL){return 0;}
                   else {
                     n = ndptr;
                       return 0;}
               }               
           }
       }
       return 1;
   }
int insert(tree *t,int value){
            if(!t->root)
            {
                nd *tmp = malloc(sizeof(nd));if(!tmp){return 2;}
                tmp->value = value;
                tmp->right = NULL;
                tmp->left = NULL;
                tmp->prev = NULL; 
                t->root = tmp;
                (t->count)++;
                /* printf("1st \n");
                printf(" root %p\n\n",t->root); */
                return 0;   
            }
            if(!find(t,value,NULL)){return 1;} 
            else
            {
              nd *prevptr;
              nd *ptr = t->root;
            while(ptr)
              {
                 prevptr = ptr;
                  if( value < ptr->value) 
                  {
                   // printf("child : %p ",ptr->left);
                    if(!ptr->left) 
                    {
                      nd *tmp = malloc(sizeof(nd));
                      if(!tmp){return 2;}
                    tmp->value = value;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->left = tmp;

                    t->count ++;
                   // printf("\nparent: %p, my: %p ",tmp->prev,prevptr->left);
                    return 0; 
                    }
                    else {ptr = ptr->left; continue;}
                  }
                  else
                  {
                    if(!ptr->right) 
                    {
                    nd *tmp = malloc(sizeof(nd));
                    tmp->value = value;
                    tmp->left =NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->right = tmp;
                    t->count ++;
                    return 0; 
                    }
                    else {ptr = ptr->right; continue;}
                  }      
              }
      
            }
                        return 1;
    }

void printTree(tree *t, list *l){
      nd *rootptr = t->root;
      int count = 0;
      push_front(l,t->root);
      while(!listEmpty(l))
      {
        nd *tmp = removeFirst(l);
        count ++;
        if(count!= t->count)
        printf("%d ",tmp->value);
        else printf("%d\n",tmp->value);
        if(tmp->right){push_front(l,tmp->right);}
        if(tmp->left){push_front(l,tmp->left);}
        
      }
    }
int main(){
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      listInit(l);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     printTree(t,l);
    }