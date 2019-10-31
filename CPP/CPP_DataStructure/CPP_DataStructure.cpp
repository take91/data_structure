
#include <iostream>

typedef struct ListNode {
	int Data;
	struct ListNode* Prev;
	struct ListNode* Next;
} Node;

// node creation
Node* createNode(int data) {
	Node* newNode = new Node();

	// variable initialization
	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}


void deleteNode(Node* node) {
	delete node;
}


Node* getNodeAt(Node* head, int index) {
	Node* horse = head;
	int count = 0;

	while (horse != NULL) {
		if (count++ == index) {
			return horse;
		}
		horse = horse->Next;
	}

	return NULL;
}

int countNode(Node* head) {
	int count = 0;
	Node* horse = head;

	while (horse != NULL) {
		horse = horse->Next;
		count++;
	}
	return count;
}

void addNode(Node** head, Node* newNode) {

	// no list exists

	if (*(head) == NULL) {
		*head = newNode;
	}

	// list exists
	else {
		Node* horse = (*head);

		while (horse->Next != NULL) {
			horse = horse->Next;
		}

		horse->Next = newNode;
		newNode->Prev = horse;
	}
}

void insertAfter(Node* current, Node* newNode) {

	// head
	if (current->Prev == NULL && current->Next == NULL) {
		current->Next = newNode;
		newNode->Prev = current;
	}

	// not head

		// if tail
	if (current->Next == NULL) {
		current->Next = newNode;
		newNode->Prev = current;
	}


	// in the middle of 2 nodes
	else {
		current->Next->Prev = newNode;
		newNode->Prev = current;
		newNode->Next = current->Next;
		current->Next = newNode;
	}
}

void removeNode(Node** head, Node* remove) {

	// head
	if ((*head) == remove) {
		*head = remove->Next;
	}


	// when remove has next lint to go
	if (remove->Next != NULL) {
		remove->Next->Prev = remove->Prev;
	}


	// when remove has prev link to go
	if (remove->Prev != NULL) {
		remove->Prev->Next = remove->Next;
	}

	deleteNode(remove);

}

int main() {
	int i = 0;
	int count = 0;

	Node* List = NULL;

	Node* newNode = NULL;

	Node* Curr = NULL;

	for (i = 0; i < 5; i++) {
		newNode = createNode(i);
		addNode(&List, newNode);
	}

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}

	printf("----------- 5 Nodes Created ------------\n");

	newNode = createNode(99);
	Curr = getNodeAt(List, 0);
	insertAfter(Curr, newNode);

	newNode = createNode(444);
	Curr = getNodeAt(List, 4);
	insertAfter(Curr, newNode);

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}

	printf("----------- 2 Nodes inserted ------------\n");

	newNode = getNodeAt(List, 1);
	removeNode(&List, newNode);

	newNode = getNodeAt(List, 0);
	removeNode(&List, newNode);

	count = countNode(List);
	for (i = 0; i < count; i++) {
		Curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, Curr->Data);
	}

	printf("----------- After Node with index 1 removed ------------\n");


	return 0;
}