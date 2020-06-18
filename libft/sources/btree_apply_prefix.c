#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree *temp;

	if (!root)
		return ;
	temp = root;
	applyf(temp->item);
	btree_apply_prefix(temp->left, applyf);
	btree_apply_prefix(temp->right, applyf);
}
