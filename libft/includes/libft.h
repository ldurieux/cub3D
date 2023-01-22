/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:23 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/12 14:33:35 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>

/* --- PRINT --- */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* --- STRING --- */
/* return the length of str
 * see man strlen(3) */
size_t		ft_strlen(const char *str);
size_t		ft_strnlen(const char *str, size_t n);

/* compare 2 strings and return 0 if they are equal
 * a negative value if s1 < s2
 * a positive value otherwise
 * see man strcmp(3) */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/* same but ignore case */
int			ft_stricmp(const char *s1, const char *s2);
int			ft_strnicmp(const char *s1, const char *s2, size_t n);

/* find first or last occurence of chr in str
 * see man strchr(3) */
char		*ft_strchr(const char *str, int chr);
char		*ft_strrchr(const char *str, int chr);

/* find first or last offcurence of needle in haystack
 * if nothing is found return NULL
 * if needle is empty return haystack
 * see man strstr(3) */
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strrstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* copy a string, see man strcpy(3) */
char		*ft_strcpy(char	*dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/* duplicate a string, see man strdup(3) */
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);

/* concatenate a string, see man strcat(3) */
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t size);

/* to lowercase */
char		*ft_strlwr(char *str);

/* to uppercase */
char		*ft_strupr(char *str);

/* make any word start by an uppercase
 * and any following letters a lowercase */
char		*ft_strcap(char *str);

/* reverse the string */
char		*ft_strrev(char *str);

int			ft_str_iswhitespace(const char *str);
int			ft_str_isalphanum(const char *str);
int			ft_str_isalpha(const char *str);
int			ft_str_isdigit(const char *str);
int			ft_str_isprintable(const char *str);

int			ft_isalpha(int chr);
int			ft_isdigit(int chr);
int			ft_isalnum(int chr);
int			ft_isascii(int chr);
int			ft_isprint(int chr);

int			ft_toupper(int chr);
int			ft_tolower(int chr);

/* trim str of leading whitespaces */
char		*ft_strtrm_lead(char *str);

/* trim str of trailling whitespaces */
char		*ft_strtrm_trail(char *str);

/* trim str of leading and trailling whitespaces */
char		*ft_strtrm(char *str);

/* make a copy of s1 and trim it of any character in set */
char		*ft_strtrim(char const *s1, char const *set);

/* trim str whitespaces
 * then replace any whitespace by a space inside the string
 * if there are successive space characters in str
 * replace them by a single space */
char		*ft_strsmp(char *str);

/* count until a character in str is not
 * contained in accept and return the count
 * see man strspn(3) */
size_t		ft_strspn(const char *str, const char *accept);
size_t		ft_strrspn(const char *str, const char *accept);

/* count until a character in str is
 * contained in reject and return the count */
size_t		ft_strcspn(const char *str, const char *reject);

/* return the first occurence of any chrs in str
 * see man strpbrk(3) */
char		*ft_strpbrk(const char *str, const char *chrs);

/* return a string starting from after any delims
 * and ending before any delims
 * if nothing is found return NULL
 * see man strtok(3) */
char		*ft_strtok_r(const char *str, const char *delims,
				const char **save_ptr);

/* returns a substring of s that is allocated */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* concatenate s1 and s2 in a new string */
char		*ft_strjoin(char const *s1, char const *s2);

/* return a string containing every string in strs
 * delimited by delim */
char		*ft_strjoin_r(char **strs, const char *delim);

/* return an array of string contained in str
 * delimited by any character contained in delims */
char		**ft_strsplit(const char *str, const char *delims);

/* same as ft_strplit but for only one character c
 * and why is it not prefixed by str you ask
 * ¯\_(ツ)_/¯ your guess is as good as mine */
char		**ft_split(char const *s, char c);

/* call function f on each characters of s */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* create a new string and fill it with
 * applications of function f */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* --- MEM ---*/
/* swap 2 values of size size */
void		ft_swap(void *a, void *b, size_t size);

/* copy a bloc of memory
 * dst and src MUST NOT overlap
 * see man memcpy(3) */
void		*ft_memcpy(void *dst, const void *src, size_t len);

/* same as memcpy but dst and src may overlap
 * see man memmove(3) */
void		*ft_memmove(void *dst, const void *src, size_t len);

/* fill a bloc of memory
 * see man memset(3) */
void		*ft_memset(void *dst, int value, size_t len);

/* erase a bloc of memory
 * see man bzero(3) */
void		ft_bzero(void *dst, size_t len);

/* same as strstr but ignores '\0'
 * see man memmem(3) */
void		*ft_memmem(const void *haystack, size_t haystack_len,
				const void *needle, size_t needle_len);
void		*ft_memrmem(const void *haystack, size_t haystack_len,
				const void *needle, size_t needle_len);

/* same as strchr but ignores '\0'
 * see man memchr(3) */
void		*ft_memchr(const void *data, int chr, size_t len);

/* same as strncmp but ignores '\0'
 * see man memcmp(3) */
int			ft_memcmp(const void *s1, const void *s2, size_t len);

/* allocate memory and fill it with 0
 * see man calloc(3) */
void		*ft_calloc(size_t count, size_t size);

/* --- INT STRING CONVERSION --- */
/* ascii to integer
 * see man atoi(3) */
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);

/* same as atoi but specify base */
int			ft_atoi_base(const char *str, const char *base);
long		ft_atol_base(const char *str, const char *base);
long long	ft_atoll_base(const char *str, const char *base);

/* ascii to integer with a better handling of overflow
 * and end_ptr becomes the next character after the number
 * see man strtoi(3) */
int			ft_strtoi(const char *str, char **end_ptr);
long		ft_strtol(const char *str, char **end_ptr);
long long	ft_strtoll(const char *str, char **end_ptr);

/* interger to ascii
 * see man itoa(3) */
char		*ft_itoa(int value);
char		*ft_ltoa(long value);
char		*ft_lltoa(long long value);

/* same as itoa but specify base */
char		*ft_itoa_base(int value, const char *base);
char		*ft_ltoa_base(long value, const char *base);
char		*ft_lltoa_base(long long value, const char *base);

/* --- MATH --- */
uint64_t	ft_factorial(int64_t value);
int64_t		ft_power(int64_t value, int64_t power);

/* --- INLINES --- */
/* --- CHARACTER TYPE --- */
static inline int	ft_is_whitespace(const char chr)
{
	return (chr == ' ' || chr == '\f' || chr == '\n'
		|| chr == '\r' || chr == '\t' || chr == '\v');
}

/* --- SIMPLE MATH --- */
static inline uint64_t	ft_abs(int64_t value)
{
	return (
		(uint64_t)(value * ((value > 0) * 2 - 1))
	);
}

static inline int64_t	ft_min(int64_t v1, int64_t v2)
{
	if (v1 > v2)
		return (v2);
	return (v1);
}

static inline int64_t	ft_max(int64_t v1, int64_t v2)
{
	if (v1 < v2)
		return (v2);
	return (v1);
}

#endif
