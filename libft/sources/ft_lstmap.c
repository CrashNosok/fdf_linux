#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ch_elem;
	t_list	*new_lst;
	t_list	*temp_elem;

	if (!lst || !f)
		return (NULL);
	temp_elem = f(lst);
	if (!(ch_elem = ft_lstnew(temp_elem->content, temp_elem->content_size)))
		return (NULL);
	lst = lst->next;
	new_lst = ch_elem;
	while (lst)
	{
		temp_elem = f(lst);
		if (!(ch_elem->next = ft_lstnew(temp_elem->content,
			temp_elem->content_size)))
			return (NULL);
		ch_elem = ch_elem->next;
		lst = lst->next;
	}
	return (new_lst);
}
