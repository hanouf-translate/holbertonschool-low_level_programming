#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_create - Allocates and initializes a new session store instance.
 *
 * Return: Pointer to initialized store_t, or NULL on allocation failure.
 */
store_t *store_create(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (store == NULL)
		return (NULL);

	store->head = NULL;
	store->count = 0;

	return (store);
}

/**
 * store_find - Searches for a session by ID string in the store.
 * @store: Pointer to store instance.
 * @id: Target session ID string.
 *
 * Return: Pointer to matching session_t, or NULL if not found.
 */
session_t *store_find(const store_t *store, const char *id)
{
	store_node_t *current;

	if (store == NULL || id == NULL)
		return (NULL);

	current = store->head;
	while (current != NULL)
	{
		if (current->session != NULL && current->session->id != NULL)
		{
			if (strcmp(current->session->id, id) == 0)
				return (current->session);
		}
		current = current->next;
	}

	return (NULL);
}

/**
 * store_insert - Inserts session into store, rejecting duplicate session IDs.
 * @store: Pointer to store instance.
 * @session: Pointer to session instance to insert.
 *
 * Return: 1 on success, 0 on failure or duplicate ID.
 */
int store_insert(store_t *store, session_t *session)
{
	store_node_t *node;

	if (store == NULL || session == NULL || session->id == NULL)
		return (0);

	if (store_find(store, session->id) != NULL)
		return (0);

	node = malloc(sizeof(store_node_t));
	if (node == NULL)
		return (0);

	node->session = session;
	node->next = store->head;
	store->head = node;
	store->count++;

	return (1);
}

/**
 * store_delete - Removes session by ID and frees associated node and session memory.
 * @store: Pointer to store instance.
 * @id: Target session ID string to delete.
 *
 * Return: 1 on success, 0 if ID is missing or invalid.
 */
int store_delete(store_t *store, const char *id)
{
	store_node_t *current, *prev = NULL;

	if (store == NULL || id == NULL)
		return (0);

	current = store->head;
	while (current != NULL)
	{
		if (current->session != NULL && current->session->id != NULL &&
		    strcmp(current->session->id, id) == 0)
		{
			if (prev == NULL)
				store->head = current->next;
			else
				prev->next = current->next;

			session_destroy(current->session);
			free(current);
			store->count--;
			return (1);
		}
		prev = current;
		current = current->next;
	}

	return (0);
}

/**
 * store_clear - Clears all sessions, returning store to reusable empty state.
 * @store: Pointer to store instance.
 */
void store_clear(store_t *store)
{
	store_node_t *current, *next;

	if (store == NULL)
		return;

	current = store->head;
	while (current != NULL)
	{
		next = current->next;
		session_destroy(current->session);
		free(current);
		current = next;
	}

	store->head = NULL;
	store->count = 0;
}

/**
 * store_destroy - Clears all store nodes and frees the store instance itself.
 * @store: Pointer to store instance.
 */
void store_destroy(store_t *store)
{
	if (store == NULL)
		return;

	store_clear(store);
	free(store);
}
