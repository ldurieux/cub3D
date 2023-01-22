NAME		= libft.a

SRCS		= \
			  srcs/chr/ft_isalnum.c \
			  srcs/chr/ft_isalpha.c \
			  srcs/chr/ft_isascii.c \
			  srcs/chr/ft_isdigit.c \
			  srcs/chr/ft_isprint.c \
			  srcs/chr/ft_tolower.c \
			  srcs/chr/ft_toupper.c \
			  srcs/frwlist/at.c \
			  srcs/frwlist/delete.c \
			  srcs/frwlist/insert.c \
			  srcs/frwlist/iter.c \
			  srcs/frwlist/new.c \
			  srcs/frwlist/remove.c \
			  srcs/ft_stack/delete.c \
			  srcs/ft_stack/iter.c \
			  srcs/ft_stack/new.c \
			  srcs/ft_stack/pop.c \
			  srcs/ft_stack/push.c \
			  srcs/list/at.c \
			  srcs/list/delete.c \
			  srcs/list/insert.c \
			  srcs/list/iter.c \
			  srcs/list/new.c \
			  srcs/list/remove.c \
			  srcs/map/delete.c \
			  srcs/map/find.c \
			  srcs/map/insert.c \
			  srcs/map/iter.c \
			  srcs/map/new.c \
			  srcs/map/remove.c \
			  srcs/map/to_array.c \
			  srcs/math/ft_factorial.c \
			  srcs/math/ft_power.c \
			  srcs/mem/ft_bzero.c \
			  srcs/mem/ft_calloc.c \
			  srcs/mem/ft_memchr.c \
			  srcs/mem/ft_memcmp.c \
			  srcs/mem/ft_memcpy.c \
			  srcs/mem/ft_memmem.c \
			  srcs/mem/ft_memmove.c \
			  srcs/mem/ft_memset.c \
			  srcs/mem/ft_swap.c \
			  srcs/printf/ft_asprintf.c \
			  srcs/printf/ft_printf.c \
			  srcs/printf/ft_printf_getarg.c \
			  srcs/printf/ft_printf_getwritten.c \
			  srcs/printf/ft_printf_lltoa.c \
			  srcs/printf/ft_printf_parse.c \
			  srcs/printf/ft_printf_putarg.c \
			  srcs/printf/ft_printf_putchar.c \
			  srcs/printf/ft_printf_putint.c \
			  srcs/printf/ft_printf_putptr.c \
			  srcs/printf/ft_printf_putstr.c \
			  srcs/printf/ft_printf_putuint.c \
			  srcs/printf/ft_printf_sanitize.c \
			  srcs/printf/ft_printf_utils.c \
			  srcs/printf/ft_vprintf.c \
			  srcs/put/ft_putchar_fd.c \
			  srcs/put/ft_putendl_fd.c \
			  srcs/put/ft_putnbr_fd.c \
			  srcs/put/ft_putstr_fd.c \
			  srcs/queue/delete.c \
			  srcs/queue/iter.c \
			  srcs/queue/new.c \
			  srcs/queue/pop.c \
			  srcs/queue/push.c \
			  srcs/str/ft_atoi.c \
			  srcs/str/ft_itoa.c \
			  srcs/str/ft_split.c \
			  srcs/str/ft_str_is.c \
			  srcs/str/ft_str_tocase.c \
			  srcs/str/ft_strcat.c \
			  srcs/str/ft_strchr.c \
			  srcs/str/ft_strcmp.c \
			  srcs/str/ft_strcpy.c \
			  srcs/str/ft_strdup.c \
			  srcs/str/ft_striteri.c \
			  srcs/str/ft_strjoin.c \
			  srcs/str/ft_strlcat.c \
			  srcs/str/ft_strlcpy.c \
			  srcs/str/ft_strlen.c \
			  srcs/str/ft_strmapi.c \
			  srcs/str/ft_strncmp.c \
			  srcs/str/ft_strnstr.c \
			  srcs/str/ft_strpbrk.c \
			  srcs/str/ft_strrchr.c \
			  srcs/str/ft_strrev.c \
			  srcs/str/ft_strsmp.c \
			  srcs/str/ft_strsplit.c \
			  srcs/str/ft_strspn.c \
			  srcs/str/ft_strstr.c \
			  srcs/str/ft_strtoi.c \
			  srcs/str/ft_strtok.c \
			  srcs/str/ft_strtrim.c \
			  srcs/str/ft_strtrm.c \
			  srcs/str/ft_substr.c \
			  srcs/vector/delete.c \
			  srcs/vector/new.c \
			  srcs/vector/pop_back.c \
			  srcs/vector/push_back.c \
			  srcs/vector/reserve.c \


HEADERS		= \
			  includes \

BUILDDIR	= .build
OBJS		= ${SRCS:%.c=$(BUILDDIR)/%.o}
DEPS		= ${SRCS:%.c=$(BUILDDIR)/%.d}
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror
DEPSFLAGS	= -MMD -MP
RM			= rm -Rf
AR			= ar
ARFLAGS		= rcs

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile
		@mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(DEPSFLAGS) -I$(HEADERS) -c $< -o $@

.PHONY: all clean fclean re
