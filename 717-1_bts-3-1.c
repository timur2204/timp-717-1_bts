#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;

typedef struct list {
	struct node *head;
	struct node *tail;
} list;

void init(list* l) {
	l->head = NULL;
	l->tail = NULL;
}

int find(list* l, int value) {
	node*  tmp;
	tmp = l->head;
	while (tmp != NULL) {
		if (tmp->value == value) {
			return 1;
		}
		tmp = tmp->next;
	}

	return 0;
}

int insertAfter(list* l, int t, int value) {
	node* tmp = l->head;

	for (int i = 0; i < t; i++) {
		tmp = tmp->next;
		if (tmp == NULL)
			return 1;
	}

	node* tmp2 = malloc(sizeof(node));
	tmp2->value = value;
	tmp2->next = tmp->next;

	tmp->next = tmp2;
	return 0;
}

int push_back(list* l, int value) {
	node* tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;

	if (l->head == NULL) {
		l->head = tmp;
		l->tail = tmp;
		return 0;
	}
	else {
		l->tail->next = tmp;
		l->tail = tmp;
		return 0;
	}
	return 1;
}

int push_front(list* l, int value)
{
	node* tmp = malloc(sizeof(node));
	tmp->value = value;

	if (l->tail == NULL) {
		l->head = tmp;
		l->tail = tmp;
		return 0;
	}
	else {
		tmp->next = l->head;
		l->head = tmp;
		return 0;
	}
	return 1;
}

int isEmpty(list* l) {
	if ((l->head == NULL) && (l->tail == NULL)) {
		return 0;
	}
	return 1;
}

int rmv(list* l, int value) {
	node* tmp1;
	node* tmp2;
	tmp1 = l->head;

	while (tmp1->value != value) {
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	if (tmp1 == NULL) {
		return 1;
	}
	tmp2->next = tmp1->next;
	free(tmp1);

	return 0;
}

void clear(list *l) {
	node* tmp = l->head;
	node* tmp1;

	while (tmp != NULL) {
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	l->head = NULL;
	l->tail = NULL;
}

void print(list* l) {
	node*  tmp;
	tmp = l->head;

	while (tmp != NULL) {
		printf("%d", tmp->value);
		tmp = tmp->next;
		if (tmp != NULL)
			printf(" ");
	}
	printf("\n");
}

int main() {
	int n, m, t;
	list* x;

	init(x);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &n);
		push_back(x, n);
	}
	print(x);

	for (int i = 1; i <= 3; ++i) {
		scanf("%d", &t);
		printf("%d", find(x, t));
	}
	printf("\n");

	scanf("%d", &n);
	push_back(x, n);
	print(x);

	scanf("%d", &n);
	push_front(x, n);
	print(x);

	scanf("%d %d", &n, &t);
	insertAfter(x, n - 1, t);
	print(x);

	scanf("%d", &n);
	rmv(x, n);
	print(x);

	clear(x);

	return 0;
}