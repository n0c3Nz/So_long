#include "libft.h"
void
	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}