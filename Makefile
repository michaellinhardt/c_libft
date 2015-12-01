# https://github.com/nesthub/
# PATH VAR & VERSION 
VERSION 		= v0.9
PATH_ROOT		= ~/42/
PATH_CURR		= $(shell pwd)
ifneq ($(wildcard $(PATH_CURR)/.path_root), )
	PATH_PROJET = $(PATH_CURR)
else
ifneq ($(wildcard $(PATH_CURR)/../.path_root), )
	PATH_PROJET = $(PATH_CURR)/..
else
	PATH_PROJET = 0
endif
endif

# COLOR VAR
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
BLANK			= \033[0;38m
OK				= $(BLANK)[ $(GREEN)OK $(BLANK)]
FAIL			= $(BLANK)[ $(RED)FAIL $(BLANK)]

#COMPILATION VAR
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

#FOLDER PATH
FOLDER_SRC		= ./src/
FOLDER_OBJ		= ./obj/
FOLDER_INC		= ./inc/
FOLDER_LIB		= ./lib/

#PROJET VAR
NAME			= libft.a
LIST_HEADER		= libft.h
LIST_SRC		= ft_strlen.c ft_strcmp.c \
				  ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c \
				  ft_putnbr_fd.c ft_putnbr.c \
				  ft_islower.c ft_isupper.c ft_toupper.c ft_tolower.c \
				  ft_isalpha.c \
				  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				  ft_memchr.c ft_memcmp.c

#BUILD LIST
LIST_OBJ		= $(subst .c,.o,$(LIST_SRC))
SRCS			= $(addprefix $(FOLDER_SRC), $(LIST_SRC))
OBJS			= $(addprefix $(FOLDER_OBJ), $(LIST_OBJ))

all: $(NAME)

#TRANSFORM .c FILE INTO .o
$(FOLDER_OBJ)%.o: $(FOLDER_SRC)%.c
	@mkdir -p $(FOLDER_OBJ)
	$(CC) $(CFLAGS) -I$(FOLDER_INC) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(FOLDER_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear:
	clear

.PHONY: clean fclean re help push clone

vardump:
	@echo PATH_CURR: $(PATH_CURR)
	@echo PATH_PROJET: $(PATH_PROJET)

test: clear re
	rm -f a.out
	mkdir -p lib
	cp ./libft.a ./lib/libft.a
	$(CC) $(CFLAGS) -I$(FOLDER_INC) -L$(FOLDER_LIB) main.c -lft
	./a.out

# display status for both git42 and github in the current project
status: -is-project-folder save-dev -status
-status:
ifeq ($(wildcard $(PATH_PROJET)/git42/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/git42/ is not a git repository.$(BLANK)"
else
	@cd $(PATH_PROJET)/git42 && echo "$(OK) $(YELLOW)$(PATH_PROJET)/git42/ git status $(BLANK)" && git status -s
endif
ifeq ($(wildcard $(PATH_PROJET)/github/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/github/ is not a git repository.$(BLANK)"
else
	@cd $(PATH_PROJET)/github && echo "$(OK) $(YELLOW)$(PATH_PROJET)/github/ git status$(BLANK)" && git status -s
endif

#VERIF IS THE CURRENT VAR PATH_PROJET RETURN TO A PROJECT FOLDER
-is-project-folder:
ifeq ($(PATH_PROJET),0)
	$(error Cant find .path_root file to define folder project)
endif

#PUSH TO BOTH GIT42 AND GItHUB
push: -is-project-folder -push-var-verif push-git42 push-github -status

#PUSH TO GITHUB
push-github: -is-project-folder -push-var-verif
ifeq ($(wildcard $(PATH_PROJET)/github/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/github/ is not a git repository.$(BLANK)"
else
	@echo "$(OK)$(YELLOW) $(PATH_PROJET)/github/ push$(BLANK)"
	@cd $(PATH_PROJET)/github && git add $(ADD) && git commit -m "$(COMMIT)" && git push
endif

#PUSH TO GIT42
push-git42: -is-project-folder -push-var-verif
ifeq ($(wildcard $(PATH_PROJET)/git42/.git), )
	@echo "$(FAIL)$(YELLOW) $(PATH_PROJET)/git42/ is not a git repository.$(BLANK)"
else
	@echo "$(OK)$(YELLOW) $(PATH_PROJET)/git42/ push$(BLANK)"
	@cd $(PATH_PROJET)/git42 && git add $(ADD) && git commit -m "$(COMMIT)" && git push
endif

#VERIF IF CORRECT VAR ARE GIVIN TO THE PUSH RULE
-push-var-verif:
ifeq ($(ADD), )
	$(error Syntaxe ex: push ADD="main.c" COMMIT="commit message")
endif
ifeq ($(COMMIT), )
	$(error Syntaxe ex: push ADD="main.c" COMMIT="commit message")
endif

#SAVE CONTENT OF DEV FOLDER TO GIT42 AND GITHUB FOLDER
save-dev: -is-project-folder
	@echo "$(OK)$(YELLOW) Reseting swap folder..$(BLANK)"
	@rm -rf $(PATH_PROJET)/swap
	@mkdir -p $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Clear git42 folder..$(BLANK)"
	@touch $(PATH_PROJET)/git42/prevent_mv_bug
	@mv $(PATH_PROJET)/git42/* $(PATH_PROJET)/swap/
	@rm -rf $(PATH_PROJET)/swap
	@mkdir -p $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Clear github folder..$(BLANK)"
	@touch $(PATH_PROJET)/github/prevent_mv_bug
	@mv $(PATH_PROJET)/github/* $(PATH_PROJET)/swap/
	@rm -rf $(PATH_PROJET)/swap
	@echo "$(OK)$(YELLOW) Copy dev folder to both git42 and github..$(BLANK)"
	@cp -r $(PATH_PROJET)/dev/* $(PATH_PROJET)/git42/
	@cp -r $(PATH_PROJET)/dev/* $(PATH_PROJET)/github/

#DOCS
help:
	@echo "$(RED)* $(YELLOWW) Comming soon..."

#DISPLAY GIT STATUS ON config_workspace FOLDER
-status-workspace:
	@echo "$(BLUE)*** [$(YELLOW)STATUS$(BLUE)] ~/42/config_workspace$(BLANK)"
	@cd ~/42/config_workspace/ && git status -s

#ROUTINE FOR SAVE ENV CONFIG
save-workspace: -save-workspace -save-makefile -status-workspace
-save-workspace:
	@mkdir -p ~/42/config_workspace/conf_file
	@echo "$(BLUE)*** [$(YELLOW)SAVE$(BLUE)] ~/.zshrc$(BLANK)"
	cp ~/.zshrc ~/42/config_workspace/conf_file/zshrc
	@echo "$(BLUE)*** [$(YELLOW)SAVE$(BLUE)] ~/.vimrc$(BLANK)"
	cp ~/.vimrc ~/42/config_workspace/conf_file/vimrc
#ROUTINE FOR SAVE MAKEFILE
save-makefile: -save-makefile
-save-makefile:
	@echo "$(BLUE)*** [$(YELLOW)SAVE$(BLUE)] ~/42/Makefile$(BLANK)"
	cp ~/42/Makefile ~/42/config_workspace/Makefile
#LOAD ENV CONFIG FILE FROM config_workspace
load-workspace:
	@echo "$(BLUE)*** [$(YELLOW)LOAD$(BLUE)] conf_file/zshrc$(BLANK)"
	cp ~/42/config_workspace/conf_file/zshrc ~/.zshrc
	@echo "$(BLUE)*** [$(YELLOW)LOAD$(BLUE)] conf_file/vimrc$(BLANK)"
	cp ~/42/config_workspace/conf_file/vimrc ~/.vimrc


