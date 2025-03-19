### PROGRAM NAME ###

NAME		:= philo


### UTILS ###

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf


### COLORS ###

DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
DRED		:= \033[0;31;5m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K


### DIRECTORIES ###

SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs


### FILES ###

define INCLUDES	:=
	$(INCLD_DIR)
endef
INCLD_FLAG 	:= ${addprefix -I , ${INCLUDES}}

define INCLD_FILES :=
	philo.h
endef


### SRCS ###

define SRC 	:=
	error_checks.c \
	ft_usleep.c \
	init.c \
	main.c \
	utils.c
endef

SRC 		:= ${strip ${SRC}}
OBJS 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRC}}
DEPS		:= ${patsubst %.c,${OBJS_DIR}/%.d,${SRC}}

### PROJECT ###

all: ${NAME}

${NAME}: ${OBJS}
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Compiling :${DEFAULT}${BWHITE} $@${DEFAULT}"
	@${CC} ${CFLAGS} ${OBJS} ${INCLD_FLAG} -o $@ ${LDFLAGS}
	@printf "\n"

-include ${DEPS}
${OBJS_DIR}/%.o: ${SRC_DIR}/%.c
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Compiling :${DEFAULT} $<"
	@mkdir -p ${OBJS_DIR}
	@${CC} ${DEP_FLAGS} ${CFLAGS} ${INCLD_FLAG} -c $< -o $@

clean:
	@printf "${PURPLE}[${NAME}] ${RED}Cleaning ${DEFAULT}${OBJS_DIR} files.\n"
	@${RM} ${OBJS_DIR} ${OBJS_BONUS_DIR}

fclean: clean
	@printf "${PURPLE}[${NAME}] ${RED}Cleaning ${DEFAULT}${NAME}.\n"
	@${RM} ${NAME}

re: fclean all


### NORM ###

norm:
	@norminette ${SRC_DIR} ${INCLD_DIR}

watch:
	watch norminette ${SRC_DIR} ${INCLD_DIR}

format:
	@for file in $(SRC); do \
		c_formatter_42 $(SRC_DIR)/$$file; \
	done
	@for file in $(INCLD_FILES); do \
		c_formatter_42 $(INCLD_DIR)/$$file; \
	done


### RUN ###

run: $(NAME)
	./$(NAME)

test: $(NAME) $(IGNORE_RDLN)
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=$(IGNORE_RDLN) ./$(NAME)

.PHONY: all clean fclean re cleanlib fcleanlib relib norm watch format run test
