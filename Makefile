NAME		= cub3D

SRCS		= \
			  main.c \
			  srcs/map/eat_chrs.c \
			  srcs/map/load.c \
			  srcs/map/parse.c \
			  srcs/map/parse_metadata.c \
			  srcs/map/parse_map.c \
			  srcs/map/read.c \

HEADERS		= \
			  includes \

LIB_NAMES	= \
			  libft \
			  libmlx \
			  
LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(addprefix -L,$(LIB_NAMES))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

BUILDDIR	= .build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) 
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d) 
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
CDEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir

all : libs
		$(MAKE) ./ $(NAME)

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS)

bonus : libs
		$(MAKE) ./ $(NAME)

libs :
		$(foreach lib, $(LIB_NAMES),$(MAKE) $(lib);)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach lib, $(LIB_NAMES),$(MAKE) $(lib) fclean;)
		-$(RM) $(NAME)

re : fclean
		$(MAKE) ./ all

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(CDEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

.PHONY: all clean fclean re bonus libs
