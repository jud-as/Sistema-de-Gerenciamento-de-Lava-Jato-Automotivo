#include "structs.h"

#define TABLE_SIZE 100


struct HashNode{
    int key;
    Servicos serv;
    struct HashNode* next;
};

struct HashTable{
    struct HashNode* array[TABLE_SIZE];
};

int hash(int key) {
	
	return key % TABLE_SIZE;
}

struct HashTable* createHashTable() {
	
	int i;
	
	struct HashTable* hashtable = (struct HashTable*)malloc(sizeof(struct HashTable));
	for (i = 0; i < TABLE_SIZE; i++){
		
		hashtable->array[i] = NULL;
		
	}
	
	return hashtable;
	
}