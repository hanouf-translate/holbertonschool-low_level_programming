#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a new secure session instance.
 * @id: Unique identifier string for the session.
 * @data: Pointer to raw session data buffer.
 * @data_len: Length of session data in bytes.
 *
 * Return: Pointer to created session_t, or NULL on failure.
 */
session_t *session_create(const char *id, const void *data, size_t data_len)
{
	session_t *session;

	if (id == NULL)
		return (NULL);

	session = malloc(sizeof(session_t));
	if (session == NULL)
		return (NULL);

	session->id = strdup(id);
	if (session->id == NULL)
	{
		free(session);
		return (NULL);
	}

	session->data = NULL;
	session->data_len = 0;

	if (data != NULL && data_len > 0)
	{
		if (session_update_data(session, data, data_len) == 0)
		{
			free(session->id);
			free(session);
			return (NULL);
		}
	}

	return (session);
}

/**
 * session_clear_data - Wipes and frees session data securely.
 * @session: Pointer to the session instance.
 */
void session_clear_data(session_t *session)
{
	if (session == NULL || session->data == NULL)
		return;

	memset(session->data, 0, session->data_len);
	free(session->data);
	session->data = NULL;
	session->data_len = 0;
}

/**
 * session_update_data - Updates payload without leaking or corrupting memory.
 * @session: Pointer to session instance.
 * @data: Pointer to new data buffer.
 * @data_len: Length of new data buffer.
 *
 * Return: 1 on success, 0 on allocation failure.
 */
int session_update_data(session_t *session, const void *data, size_t data_len)
{
	void *new_data;

	if (session == NULL)
		return (0);

	if (data == NULL || data_len == 0)
	{
		session_clear_data(session);
		return (1);
	}

	new_data = malloc(data_len);
	if (new_data == NULL)
		return (0);

	memcpy(new_data, data, data_len);
	session_clear_data(session);

	session->data = new_data;
	session->data_len = data_len;

	return (1);
}

/**
 * session_destroy - Destroys session, zeroing payload and freeing resources.
 * @session: Pointer to session instance to free.
 */
void session_destroy(session_t *session)
{
	if (session == NULL)
		return;

	session_clear_data(session);
	if (session->id != NULL)
		free(session->id);

	free(session);
}
