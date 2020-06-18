#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *temp;

	temp = malloc(sizeof(t_btree));
	if (temp)
	{
		temp->left = NULL;
		temp->right = NULL;
		temp->item = item;
	}
	return (temp);
}
