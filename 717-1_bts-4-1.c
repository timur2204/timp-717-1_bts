#include "stdio.h"
#include "stdlib.h"

typedef struct node {
	int value;
	struct node* prev;
	struct node* left;
	struct node* right;
}node;

typedef struct tree {
	struct node* root;
	int count;
}tree;

typedef struct list_node {
	struct node *value;
	struct list_node *next;
}list_node;

typedef struct list {
	list_node *tail;
	list_node *head;
}list;

void list_init(list* l) {
	l->head = NULL;
	l->tail = NULL;
}

int list_isEmpty(list *l) {
	int flag = (l->tail == NULL);
	return flag;
}

int push_back(list *l, node *value) {
	list_node *temp_l = malloc(sizeof(list_node));
	temp_l->value = value;
	temp_l->next = NULL;

	if (!list_isEmpty(l)) {
		l->tail->next = temp_l;
		l->tail = temp_l;
	}
	else {
		l->head = l->tail = temp_l;
	}
}

node* removeFirst(list *l) {
	list_node *headptr = l->head;
	node *temp = l->head->value;

	l->head = l->head->next;

	if (l->head == NULL) {
		l->tail = NULL;
	}
	free(headptr);
	return temp;
}

int flagEmpty(list *l) {
	list_node *headptr = l->head;
	while (headptr != NULL) {
		if (headptr->value != NULL) {
			return 0;
		}

		headptr = headptr->next;
	}
	return 1;
}

void listPrint(list *l) {
	list_node *headptr = l->head;
	while (headptr) {
		if (!headptr->value) {
			printf("_");
		}
		else printf("%d", headptr->value->value);

		if (headptr->next) {
			printf(" ");
		}

		headptr = headptr->next;
	}
	printf("\n");
}


void clear(tree *t, list *l) {
	node *rootptr = t->root;
	node *temp;
	push_back(l, rootptr);
	while (list_isEmpty(l)) {
		temp = rootptr;
		rootptr = removeFirst(l);
		free(temp);

		if (temp->left != NULL) {
			push_back(l, rootptr->left);
		}
		else if (temp->right != NULL) {
			push_back(l, temp->right);
		}
	}
	t->root = NULL;
}

void init(tree *t) {
	t->count = 0;
	t->root = NULL;
}

int find(tree *t, int value, node *n) {
	node *nodeptr = t->root;
	if (!nodeptr) {
		return 1;
	}
	else {
		while (nodeptr != NULL) {
			if (value > nodeptr->value) {
				nodeptr = nodeptr->right;
				continue;
			}
			if (value < nodeptr->value) {
				nodeptr = nodeptr->left;
				continue;
			}
			if (value == nodeptr->value) {
				if (n == NULL) {
					return 0;
				}
				else {
					printf("there");
					n = nodeptr;
					printf("in function find %p\n", n);
					return 0;
				}
			}
		}
	}
	return 1;
}

void find_and_print(tree *t, int value) {
	node *nodeptr = t->root;
	if (!nodeptr) {
		printf("_");
	}
	else {
		while (nodeptr != NULL) {
			if (value > nodeptr->value) {
				nodeptr = nodeptr->right;
				continue;
			}
			if (value < nodeptr->value) {
				nodeptr = nodeptr->left;
				continue;
			}
			if (value == nodeptr->value) {
				break;
			}
		}
		if (!nodeptr->prev) {
			printf("_ ");
		}
		else {
			printf("%d ", nodeptr->prev->value);
		}
		if (!nodeptr->left) {
			printf("_ ");
		}
		else {
			printf("%d ", nodeptr->left->value);
		}
		if (!nodeptr->right) {
			printf("_");
		}
		else {
			printf("%d", nodeptr->right->value);
		}
	}
	printf("\n");
}

void find1_and_print(tree *t, int value) {
	node *nodeptr = t->root;
	if (!nodeptr) {
		printf("-");
	}
	else {
		while (nodeptr != NULL) {
			if (value > nodeptr->value) {
				nodeptr = nodeptr->right;
				continue;
			}
			if (value < nodeptr->value) {
				nodeptr = nodeptr->left;
				continue;
			}
			if (value == nodeptr->value) {
				break;
			}
		}
		if (!nodeptr) {
			printf("-\n");
			return;
		}
		if (!nodeptr->prev) {
			printf("_ ");
		}
		else {
			printf("%d ", nodeptr->prev->value);
		}
		if (!nodeptr->left) {
			printf("_ ");
		}
		else {
			printf("%d ", nodeptr->left->value);
		}
		if (!nodeptr->right) {
			printf("_");
		}
		else {
			printf("%d", nodeptr->right->value);
		}
	}
	printf("\n");
}


int delete_tree(tree* t, int value) {
	node* temp = t->root;
	node* n_ptr;
	node* m_ptr;

	while (temp != NULL) {
		if (temp->value == value) {
			break;
		}

		if (value > temp->value) {
			if (temp->right == NULL) {
				return 1;
			}
			temp = temp->right;
		}
		else {
			if (temp->left == NULL) {
				return 1;
			}
			temp = temp->left;
		}
	}
	if (temp->value == t->root->value) {
		n_ptr = temp;
		if (temp->right != NULL) {
			n_ptr = temp->right;

			while (n_ptr->left != NULL) {
				n_ptr = n_ptr->left;
			}

			n_ptr->prev = NULL;
			n_ptr->left = temp->left;
			m_ptr = temp;
			m_ptr = m_ptr->left;
			m_ptr->prev = n_ptr;

			t->root = n_ptr;
			free(temp);
			t->count--;
			return 1;
		}

		return 0;
	}
}

int insert(tree *t, int value) {
	if (!t->root) {
		node *temp = malloc(sizeof(node)); if (!temp) { return 2; }
		temp->value = value;
		temp->right = NULL;
		temp->left = NULL;
		temp->prev = NULL;
		t->root = temp;
		(t->count)++;
		return 0;
	}

	if (!find(t, value, NULL)) {
		return 1;
	}
	else {
		node *prevptr;
		node *ptr = t->root;
		while (ptr) {
			prevptr = ptr;

			if (value < ptr->value) {
				if (!ptr->left) {
					node *temp = malloc(sizeof(node));
					if (!temp) {
						return 2;
					}
					temp->value = value;
					temp->left = NULL;
					temp->right = NULL;
					temp->prev = prevptr;
					prevptr->left = temp;

					t->count++;
					return 0;
				}
				else {
					ptr = ptr->left;
					continue;
				}
			}
			else {
				if (!ptr->right) {
					node *temp = malloc(sizeof(node));
					temp->value = value;
					temp->left = NULL;
					temp->right = NULL;
					temp->prev = prevptr;
					prevptr->right = temp;
					t->count++;
					return 0;
				}
				else {
					ptr = ptr->right;
					continue;
				}
			}
		}

	}
	return 1;
}

void print(node *n, list *l)
{
	node *rootptr = n;
	list *l_temp = malloc(sizeof(list));

	if (!rootptr) {
		printf("-\n");
		return;
	}

	push_back(l, rootptr);
	listPrint(l);

	while (1) {
		while (!list_isEmpty(l)) {
			rootptr = removeFirst(l);
			push_back(l_temp, rootptr);
		}

		while (!list_isEmpty(l_temp)) {
			rootptr = removeFirst(l_temp);
			if (rootptr == NULL) {
				push_back(l, NULL);
				push_back(l, NULL);
			}
			else {
				push_back(l, rootptr->left);
				push_back(l, rootptr->right);
			}

		}
		if (flagEmpty(l)) {
			while (!list_isEmpty(l)) {
				removeFirst(l);
			}
			break;
		}
		listPrint(l);
	}
}

void printTree(tree *t, list *l) {
	node *rootptr = t->root;
	list *l_temp = malloc(sizeof(list));
	list_init(l_temp);

	if (!rootptr) {
		printf("-\n");
		return;
	}

	push_back(l, rootptr);
	listPrint(l);

	while (1) {
		while (!list_isEmpty(l)) {
			rootptr = removeFirst(l);
			push_back(l_temp, rootptr);
		}

		while (!list_isEmpty(l_temp)) {
			rootptr = removeFirst(l_temp);
			if (!rootptr) {
				push_back(l, NULL);
				push_back(l, NULL);
			}
			else {
				push_back(l, rootptr->left);
				push_back(l, rootptr->right);
			}

		}

		if (flagEmpty(l)) {
			while (!list_isEmpty(l)) {
				removeFirst(l);
			}
			break;
		}
		listPrint(l);
	}

}

int rotateLeft(tree *t) {
	node *parent = NULL, *C = NULL, *a = NULL, *b = NULL;
	if (!t->root->right) {
		return 1;
	}

	while (t->root->right) {
		a = t->root;
		parent = a->prev;
		b = a->right;

		if (b == NULL) {
			return 1;
		}

		C = b->left;
		b->left = a;
		a->right = C;

		if (C) {
			C->prev = a;
		}

		b->prev = parent;

		if (parent) {
			if (parent->left == a) {
				parent->left = b;
			}
			else {
				parent->right = b;
			}
		}

		a->prev = b;

		if (!parent) {
			t->root = (t->root)->prev;
		}
	}
	return 0;
}

int rotareRight(tree *t) {
	node *parent = NULL, *C = NULL, *a = NULL, *b = NULL;
	if (!t->root->left) {
		return 1;
	}

	while (t->root->left) {
		b = (t->root);
		parent = b->prev;
		a = b->left;

		if (a == NULL) {
			return 1;
		}

		C = a->right;
		a->right = b;
		b->left = C;

		if (C) {
			C->prev = b;
		}

		a->prev = parent;

		if (parent) {
			if (parent->left == b) {
				parent->left = a;
			}
			else {
				parent->right = a;
			}
		}

		b->prev = a;
		t->root = (t->root)->prev;
	}
	return 0;
}

int main() {
	tree *t = malloc(sizeof(tree));
	list *l = malloc(sizeof(list));

	init(t);
	list_init(l);

	for (int i = 0; i < 4; ++i) {
		int a;
		scanf("%d", &a);
		insert(t, a);
	}
	printTree(t, l);

	for (int i = 0; i < 3; ++i) {
		int a;
		scanf("%d", &a);
		insert(t, a);
	}
	printTree(t, l);

	int x;
	scanf("%d", &x);
	find_and_print(t, x);

	int y;
	scanf("%d", &y);
	find1_and_print(t, y);

	int z;
	scanf("%d", &z);
	delete_tree(t, z);
	printTree(t, l);

	rotateLeft(t);
	printTree(t, l);

	rotareRight(t);
	printTree(t, l);

	printf("%d\n", t->count);

	clear(t, l);
	printTree(t, l);
}
