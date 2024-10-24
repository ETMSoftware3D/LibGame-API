/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_LINKED_LIST_H
#define LG_LINKED_LIST_H

typedef struct LinkedList {
	void			*data;
	size_t			size;
	struct LinkedList	*prev;
	struct LinkedList	*next;
} LG_LinkedList;

LG_LinkedList	*lg_list_new(void *, size_t);
LG_LinkedList	*lg_list_add(LG_LinkedList *, void *, size_t);
LG_LinkedList	*lg_list_remove(LG_LinkedList *);
void		lg_list_free(LG_LinkedList *);
void		lg_list_free_all(LG_LinkedList *);
LG_LinkedList	*lg_list_first(LG_LinkedList *);
LG_LinkedList	*lg_list_last(LG_LinkedList *);
LG_LinkedList	*lg_list_prev(LG_LinkedList *);
LG_LinkedList	*lg_list_next(LG_LinkedList *);
LG_LinkedList	*lg_list_nth(LG_LinkedList *, int);
int		lg_list_index(LG_LinkedList *);
int		lg_list_count(LG_LinkedList *);

#endif /* LG_LINKED_LIST_H */
