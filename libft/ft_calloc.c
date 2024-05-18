/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:30:24 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/06 13:53:09 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*ptr;
	char		*ptr1;

	if (count >= 2147483647)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ptr1 = (char *)ptr;
	i = 0;
	while (i < count * size)
	{
		ptr1[i] = 0;
		i++;
	}
	return (ptr);
}

//#include <stdio.h> // For printf
//#include <stdio.h> // For printf

//// Function to compare two memory regions for equality
//int mem_cmp(const void *ptr1, const void *ptr2, size_t n) {
//    const unsigned char *p1 = ptr1;
//    const unsigned char *p2 = ptr2;
//    for (size_t i = 0; i < n; i++) {
//        if (p1[i] != p2[i]) return 0;
//    }
//    return 1;
//}

//// Function to print memory content
//void print_memory(const void *ptr, size_t count, size_t size) {
//    const unsigned char *p = ptr;
//    for (size_t i = 0; i < count * size; i++) {
//        printf("%02X ", p[i]);
//        if ((i + 1) % size == 0) printf("| ");
//    }
//    printf("\n");
//}

//int main() {
//    size_t size = 4;
//    size_t count = 5;

//    // Testing ft_calloc
//    printf("\nTesting ft_calloc:\n");
//    void *ft_ptr = ft_calloc(count, size);
//    if (ft_ptr == NULL) {
//        printf("\033[0;31mft_calloc failed\033[0m\n");
//        return 1;
//    }
//    printf("ft_calloc succeeded\n");
//    printf("Memory content:\n");
//    print_memory(ft_ptr, count, size);

//    // Testing calloc
//    printf("\nTesting calloc:\n");
//    void *calloc_ptr = calloc(count, size);
//    if (calloc_ptr == NULL) {
//        printf("\033[0;31mcalloc failed\033[0m\n");
//        free(ft_ptr); // Freeing ft_calloc allocated memory
//        return 1;
//    }
//    printf("calloc succeeded\n");
//    printf("Memory content:\n");
//    print_memory(calloc_ptr, count, size);

//    // Comparing results
//    printf("\nComparing results:\n");
//    if (mem_cmp(ft_ptr, calloc_ptr, size * count)) {
//        printf("\033[0;32mResults match\033[0m\n");
//    } else {
//        printf("\033[0;31mResults don't match\033[0m\n");
//    }

//    // Freeing allocated memory
//    free(ft_ptr);
//    free(calloc_ptr);

//    return 0;
//}