#include "list.h"

void list_init(List *list, void (*destroy)(void *data)){
// Sert a initialiser tous les parametres d'une liste
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
	list->match = NULL;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *newElement = malloc(sizeof(ListElmt));
	if(newElement == NULL)
		{ return -1;}
	newElement->data = data;


	if (element == NULL){
		if(list_size(list) == 0){
			list->tail = newElement;}
		newElement->next = list->head;
		list->head = newElement;
	}
	else{
		if(list_is_tail(element)){
			list->tail = newElement;}
		newElement->next = element->next;
		element->next = newElement;
		
	}

	list->size ++;
	return 0;
}


