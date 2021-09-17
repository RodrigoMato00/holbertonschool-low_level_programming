#include "lists.h"

/**
 *get_dnodeint_at_index - lkdmlakmsdlkamsdlamksdmkla
 *@head: sdkfspdmffosdmsd
 *index: sdkñfmlkdmclskdmckslmdc
 *Return: dcm,lñ,cpsdmc,sñld,cslñd
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if(!head)
		return(0);

	while (index)
	{
		head = head->next;
		if (!head)
			return (0);
		index--;
	}

	return (head);
}
