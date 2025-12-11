#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort algorithm (by swapping nodes)
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *prev;

	// 1. Clauses de garde (Sécurité)
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next; // SAUVEGARDE de l'élément suivant

		// Boucle interne : tant qu'on a un précédent et qu'il est plus petit
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev; // Le nœud juste avant current

			// a. Déconnecter 'prev' du côté droit
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			// b. Insérer 'current' devant 'prev' et relier les deux
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			// c. Mettre à jour le voisin de GAUCHE (ou la tête de liste)
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			// d. Imprimer après l'échange
			print_list(*list);

			// NOTE IMPORTANTE : current NE bouge PAS vers next_node ICI
		}

		// 2. AVANCER : On passe à l'élément non trié suivant.
		current = next_node;
	}
}
