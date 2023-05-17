#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}arraylist;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(arraylist* L) {
	L->size = 0;
}
int is_empty(arraylist* L) {
	return L->size == 0;
}

int is_full(arraylist* L) {

	return L->size == MAX_LIST_SIZE;
}


element get_entry(arraylist* L, int pos) {

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(arraylist* L) {

	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(arraylist* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(arraylist* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

element delete(arraylist* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1);i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;

}

int main(void) {
    arraylist L;
    int num, item, pos, count = 0;

    init(&L);

    while (1) {
        printf("*** MENU ****\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. PRINT\n");
        printf("0. EXIT\n\n");
        printf("Enter the menu: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            printf("Enter the number and position: ");
            scanf("%d %d", &item, &pos);
            if (pos == 0) {
                insert(&L, 0, item);
                count++;
            }
            else if (pos > 0 && pos <= L.size) {
                count = 0;
                insert(&L, pos, item, &count);
                count++;
            }
            else {
                printf("Invalid position\n");
                continue;
            }
            printf("MOVE: %d.\n", count);
            break;
        case 2:
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos >= 0 && pos < L.size) {
                count = 0;
                item = delete(&L, pos, count);
                count++;
                printf("Deleted item: %d\n", item);
                printf("MOVE: %d.\n", count);
            }
            else {
                printf("Invalid position\n");
                continue;
            }
            break;
        case 3:
            print_list(&L);
            break;
        case 0:
            printf("Exit the program\n");
            exit(0);
        default:
            printf("Invalid menu option\n");
            break;
        }
    }
}
























