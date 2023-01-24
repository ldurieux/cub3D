NAME		= cub3D

SRCS		= \
			  main.c \
			  srcs/map/eat_chrs.c \
			  srcs/map/load.c \
			  srcs/map/parse.c \
			  srcs/map/parse_metadata.c \
			  srcs/map/parse_map.c \
			  srcs/map/read.c \
			  srcs/llx/exec.c \
			  srcs/llx/init.c \
			  srcs/llx/win/event_handler_1.c \
			  srcs/llx/win/event_handler_2.c \
			  srcs/llx/win/init.c \
			  srcs/llx/win/is_key_down.c \
			  srcs/llx/paint/init.c \
			  srcs/llx/paint/paint.c \
			  srcs/llx/paint/types.c \

HEADERS		= \
			  includes \

LIB_NAMES	= \
			  libft \
			  libmlx \
			  
DYN_LIBS	= \
			  m \
			  #Xext \
			  #X11 \

FRAMEWORKS	= \
			  OpenGL \
			  AppKit \

DYN_LIBS	:= $(addprefix -l, $(DYN_LIBS))
FRAMEWORKS	:= $(addprefix -framework , $(FRAMEWORKS))

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
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(DYN_LIBS) $(FRAMEWORKS)

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
