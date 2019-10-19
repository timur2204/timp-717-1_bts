#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef struct list {
	struct node *head;
	struct node *tail;
} list;
    
void init(list* l) {
	l->head = NULL;
	l->tail = NULL;
}

void clear(list* l) {
	node* tmp = l->head;
	node* tmp1;

	while(tmp != NULL) {
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	l->head = NULL;
	l->tail = NULL;
}

int isEmpty(list* l) {
	if((l->head == NULL) && (l->tail == NULL))
		return 0;
	return 1;
}

int find(list* l, int value) {
	node*  tmp;
	tmp = l->head;

	while(tmp != NULL) {
		if(tmp->value == value)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

int push_back(list* l, int value) {
	node* tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	
	if(!isEmpty(l)) {
		l->head = tmp;
		l->tail = tmp;
		return 0;
	}
	else {
		tmp->prev = l->tail;
		l->tail->next = tmp;
		l->tail = tmp;
		return 0;
	}
	return 1;
}

int push_front(list* l, int value) {
	node* tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	
	if(!isEmpty(l)) {
		l->head = tmp;
		l->tail = tmp;
		return 0;
	}
	else {
		tmp->next = l->head;
		l->head->prev = tmp;
		l->head = tmp;
		return 0;
	}
	return 1;
}

int insertAfter(list* l, int num, int value) {
	node* tmp = l->head;

	for(int i=0; i<num; ++i) {
		tmp = tmp->next;
		if(tmp == NULL)
			return 1;
	}

	node* tmp2 = malloc(sizeof(node));
	tmp2->value = value;

	if(tmp == l->tail) {
		tmp->next = tmp2;
		tmp2->prev = tmp;
		tmp2->next = NULL;
	}
	else {
		tmp2->next = tmp->next;
		tmp2->prev = tmp;
		tmp->next = tmp2;
		tmp = tmp->next;
		tmp = tmp->next;
		tmp->prev = tmp2;
		return 0;
	}
}

int insertBefore(list* l, int num, int value) {
	node* tmp = l->head;

	for(int i=0; i<num; ++i) {
		tmp = tmp->next;
		if(tmp == NULL)
			return 1;
	}

	node* tmp2 = malloc(sizeof(node));
	tmp2->value = value;

	if(tmp == l->head) {
		tmp->prev = tmp2;
		tmp2->next = tmp;
		tmp2->prev = NULL;
		l->head = tmp2;
	}
	else {
		tmp2->prev = tmp->prev;
		tmp2->next = tmp;
		tmp->prev = tmp2;
		tmp = tmp->prev;
		tmp = tmp->prev;
		tmp->next = tmp2;
		return 0;
	}
}

int removeFirst(list* l, int value) {
	node* tmp1 = l->head;
	node* tmp2;

	while(tmp1 != NULL) {
		tmp2 = tmp1;
		if(tmp1->value == value) {
			// Если это начало
			if(tmp1 == l->head) {
				tmp1 = tmp1->next;
				tmp1->prev = NULL;
				free(tmp2);
			}
			else if(tmp1 == l->tail) {
				tmp1 = tmp1->prev;
				tmp1->next = NULL;
				free(tmp2);
				l->tail = tmp1;
			}
			else {
				tmp1 = tmp2->next;
				tmp1->prev = tmp2->prev;
				tmp1 = tmp2->prev;
				tmp1->next = tmp2->next;
				free(tmp2);
			}
			return 0;
		}
		tmp1 = tmp1->next;
	}
	return 1;
}

int removeLast(list* l, int value) {
	node* tmp1 = l->tail;
	node* tmp2;

	while(tmp1 != NULL) {
		tmp2 = tmp1;
		if(tmp1->value == value) {
		    
			if(tmp1 == l->tail) {
				tmp1 = tmp1->prev;
				tmp1->next = NULL;
				free(tmp2);
			}
			else if(tmp1 == l->head) {
				tmp1 = tmp1->next;
				tmp1->prev = NULL;
				free(tmp2);
				l->head = tmp1;
			}
			else {
				tmp1 = tmp2->next;
				tmp1->prev = tmp2->prev;
				tmp1 = tmp2->prev;
				tmp1->next = tmp2->next;
				free(tmp2);
			}
			return 0;
		}
		tmp1 = tmp1->prev;
	}
	return 1;
}

void print(list* l) {
	node*  tmp;
	tmp = l->head;

	while(tmp != NULL) {
	    
		printf("%d", tmp->value);
		tmp = tmp->next;
		if(tmp != NULL)
			printf(" ");
	}
	printf("\n");
}

void print_invers(list* l) {
	node*  tmp;
	tmp = l->tail;

	while(tmp != NULL) {
		
		printf("%d", tmp->value);
		tmp = tmp->prev;
		if(tmp != NULL)
			printf(" ");
	}
	printf("\n");
}

int main() {
    
	int q, n, e;
	list* current;

	init(current);

	scanf("%d", &q);

	for(int i=0; i<q; ++i) {
		scanf("%d", &n);
		push_back(current, n);
	}

	print(current);

	for(int i=1; i<=3; ++i) {
		scanf("%d", &e);
		printf("%d", find(current, e));
	}
	printf("\n");

	scanf("%d", &n);
	push_back(current, n);

	print_invers(current);

	scanf("%d", &n);
	push_front(current, n);

	print(current);

	scanf("%d %d", &n, &e);
	insertAfter(current, n-1, e);

	print_invers(current);

	scanf("%d %d", &n, &e);
	insertBefore(current, n-1, e);

	print(current);

	scanf("%d", &n);
	removeFirst(current, n);

	print_invers(current);

	scanf("%d", &n);
	removeLast(current, n);

	print(current);
	clear(current);

	return 0;
}