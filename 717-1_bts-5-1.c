    #include "stdio.h"
    #include "stdlib.h"

    typedef struct nd
    {
        int value;
        struct nd* prev;
        struct nd* left;
        struct nd* right;
    }nd;
    typedef struct tree
    {
      struct nd* root;
      int count;
    }tree;
    typedef struct l_nd
    {
        struct nd *value;
        struct l_nd *next;
    }l_nd;
    typedef struct list
    {
        l_nd *tail;
        l_nd *head;
    }list;

void listInit(list* l){
        l->head = NULL;
        l->tail = NULL;
    }
       int listEmpty(list *l)
    {
      int flag = (l->tail==NULL);
      return flag;
    }

        int push_back(list *l,nd *value)
    {
        l_nd *tmp_l = malloc(sizeof(l_nd));
        tmp_l->value = value;
        tmp_l->next = NULL;

        if(!listEmpty(l))
        {
          l->tail->next = tmp_l;
          l->tail = tmp_l;
        }else
        {
          l->head = l->tail = tmp_l;
        }
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
      push_back(l,rootptr);
      while(!listEmpty(l))
      {
        nd *tmp = removeFirst(l);
        count ++;
        if(count!=t->count) printf("%d ",tmp->value);
        else printf("%d\n",tmp->value);

        if(tmp->left)push_back(l,tmp->left);
        if(tmp->right)push_back(l,tmp->right);
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