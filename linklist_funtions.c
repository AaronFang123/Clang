#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *next;
};

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(0);
	}
	new_node -> value = n;
	new_node -> next = list;
}

struct node *read_numbers(void)                    
{
	struct node *first = NULL;
	int n;
	
	printf("Enter a series of ints (0 to end): ");
	for (;;) {
		scanf("%d", &n);
		if(n == 0)  return first;
		first = add_to_list(first, n);
	}
}

struct node *search_list(struct node *list, int n)  
{
	struct node *p;
	
	for(p = list; p != NULL; p = p->next)
	  if  (p -> value == n)
	    return p;
    return NULL;
}


struct node *delete_from_list(struct node *list, int n)
{
	struct node *cur, *prev;
	
	for(cur = list, prev = NULL;
	    cur != NULL && cur ->value != n;
		prev = cur , cur = cur -> next)
		;                                   //n is located now by "for"
		
		if(cur == NULL)
		  return list;                      //n is not found
  		if(prev == NULL)
  		  list = list ->next;               //n is in the first node
		else 
		  prev ->next = cur ->next;         //n is in some other node
		  
	free (cur);
	return list;
} 
 