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


    void init(tree *t){
      
        t->count = 0;
        t->root = NULL;
    }
    int flag = 0;

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
void print(nd* root,tree *t) {
    if (root) {
       
        if(root->left)print(root->left,t);
        if(root->right)print(root->right,t);
        
        flag++;
        if(flag != t->count) printf("%d ", root->value);
        else printf("%d\n",root->value);
         
    }
}
int main(){
      tree *t = malloc(sizeof(tree));
      init(t);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
      print(t->root,t);
    }