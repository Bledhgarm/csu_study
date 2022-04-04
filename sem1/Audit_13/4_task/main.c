#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *next;
} node_n;
void push(node_n *head, int value);
void remove_element(node_n *head, int tmp_value);
void find_size(node_n *head);
void out_list(node_n *head);
void find_element(node_n *head, int element);
int main(void) {
	node_n *head = NULL;
	head = malloc(sizeof(node_n));
	if (head == NULL) return 1;
	head->value = 1;
	head->next = malloc(sizeof(node_n));
	head->next->value = 4;
	head->next->next = NULL;
	push(head, 10);
	push(head, 8);
	remove_element(head, 4);
	out_list(head);
	find_element(head, 4);
	find_size(head);
	return 0;
}

void out_list(node_n *head) {
	node_n *current = head;
	while (current != NULL) {
		printf_s("%d ", current->value);
		current = current->next;
	}
}

void push(node_n *head, int value) {
	node_n *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(node_n));
	current->next->value = value;
	current->next->next = NULL;
}

void remove_element(node_n *head, int tmp_value) {
	node_n *current = head;
	while (current->next != NULL) {
		if (current->next->value == tmp_value) {
			node_n *tmp = current->next;
			current->next = tmp->next;
			free(tmp);
		}
		else {
			current = current->next;
		}
	}
}

void find_size(node_n *head) {
	node_n *current = head;
	int counter = 0;
	while (current != NULL) {
		counter++;
		current = current->next;
	}
	printf_s("\nSize of list: %d", counter);
}

void find_element(node_n *head, int value) {
	int counter = 0;
	node_n *current = head;
	while (current != NULL) {
		counter++;
		if (current->value == value) {
			printf_s("\nIndex of this element %d\n", counter);
			break;
		}
		current = current->next;
	}
}

