/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:31:32 by abtouait          #+#    #+#             */
/*   Updated: 2025/08/04 19:38:24 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define BUFFER_SIZE 4

char *ft_strdup(char *s1)
{
    int i;
    char *s2;
    
    i = 0;
    while (s1[i] != '\0')
        i++;
    s2 = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (s1[i] != '\0')
    {
       s2[i] = s1[i];
       i++;
    }
    s2[i] = '\0';
    return (s2);
}


char *gnl(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int buffer_pos;
    static int buffer_read;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd,buffer,BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
            if (buffer_read == '\n')
                break;
        }
        line[i] = buffer[buffer_pos++];
        i++;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}