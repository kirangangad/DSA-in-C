#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;

int hashCode(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    if (item == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    item->data = data;
    item->key = key;

    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
    printf("Inserted: Key=%d, Data=%d\n", key, data);
}

struct DataItem* search(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void deleteItem(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
            printf("Deleted: Key=%d, Data=%d\n", temp->key, temp->data);
            free(temp);
            return;
        }

        hashIndex++;
        hashIndex %= SIZE;
    }

    printf("Key %d not found for deletion.\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL && hashArray[i]->key != -1)
            printf(" (%d, %d) ", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }
    printf("\n");
}

int main() {
    dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    if (dummyItem == NULL) {
        printf("Memory allocation failed for dummy item.\n");
        return 1;
    }
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);

    display();

    struct DataItem* item = search(42);
    if (item != NULL)
        printf("Found: Key=%d, Data=%d\n", item->key, item->data);
    else
        printf("Element not found.\n");

    deleteItem(42);

    item = search(42);
    if (item != NULL)
        printf("Found: Key=%d, Data=%d\n", item->key, item->data);
    else
        printf("Element not found.\n");

    display();

    free(dummyItem);
    return 0;
}
