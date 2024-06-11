/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:22:55 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/11 12:26:27 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h> // for strdup

//int mem_cmp(const void *ptr1, const void *ptr2, size_t n) {
//    const unsigned char *p1 = ptr1;
//    const unsigned char *p2 = ptr2;
//    for (size_t i = 0; i < n; i++) {
//        if (p1[i] != p2[i]) return 0;
//    }
//    return 1;
//}

//// Function to print memory content
//void print_memory(const void *ptr, size_t size) {
//    const unsigned char *p = ptr;
//    for (size_t i = 0; i < size; i++) {
//        printf("%02X ", p[i]);
//    }
//    printf("\n");
//}

//int main() {
//    const char *test_string = "Hello, world!";

//    // Testing ft_strdup
//    printf("\nTesting ft_strdup:\n");
//    char *ft_ptr = ft_strdup(test_string);
//    if (ft_ptr == NULL) {
//        printf("\033[0;31mft_strdup failed\033[0m\n");
//        return 1;
//    }
//    printf("ft_strdup succeeded\n");
//    printf("Memory content:\n");
//    print_memory(ft_ptr, strlen(test_string) + 1);
//    printf("String content: %s\n", ft_ptr);

//    // Testing strdup
//    printf("\nTesting strdup:\n");
//    char *strdup_ptr = strdup(test_string);
//    if (strdup_ptr == NULL) {
//        printf("\033[0;31mstrdup failed\033[0m\n");
//        free(ft_ptr); // Freeing ft_strdup allocated memory
//        return 1;
//    }
//    printf("strdup succeeded\n");
//    printf("Memory content:\n");
//    print_memory(strdup_ptr, strlen(test_string) + 1);
//    printf("String content: %s\n", strdup_ptr);

//    // Comparing results
//    printf("\nComparing results:\n");
//    if (mem_cmp(ft_ptr, strdup_ptr, strlen(test_string) + 1)) {
//        printf("\033[0;32mResults match\033[0m\n");
//    } else {
//        printf("\033[0;31mResults don't match\033[0m\n");
//    }

//    // Freeing allocated memory
//    free(ft_ptr);
//    free(strdup_ptr);

//    return 0;
//}