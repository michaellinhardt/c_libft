# PATH VAR 
PATH_ROOT		=	~/42
PATH_GITHUB		=	https://github.com/nesthub

# COLOR VAR aaa
C_RED				=	\033[0;31m
C_GREEN				=	\033[0;32m
C_YELLOW			=	\033[0;33m
C_BLUE				=	\033[0;34m
C_BLANK				=	\033[0;38m
C_OK				= $(C_BLANK)[ $(C_GREEN)OK $(C_BLANK)]
C_FAIL				= $(C_BLANK)[ $(C_RED)FAIL $(C_BLANK)]

all:
	@echo "$(C_BLUE)*** [$(C_YELLOW)MAKEFILE COMMAND$(C_BLUE)] $(C_BLANK)"
	@echo "$(C_RED)- maj-makefile"
	@echo "$(C_YELLOW)- \tCopy Makefile from ~/42 to ./"
	@echo "$(C_RED)- clone LOCAL=\"/folder\" GIT=\"/folder\""
	@echo "$(C_YELLOW)- \tClear LOCAL folder and clone GIT depo inside"
	@echo "$(C_RED)- init-projet LOCAL=\"/folder\""
	@echo "$(C_YELLOW)- \tCopy all default files for new project inside LOCAL folder"

maj-makefile:
	@echo "$(C_BLUE)*** [$(C_YELLOW)COPY FROM$(C_BLUE)] ~/42/Makefile$(C_BLANK)"
	@cp ~/42/Makefile ./Makefile

init-projet:
ifeq ($(LOCAL), )
	$(error Syntaxe ex: init-projet LOCAL=\"/projets/libft\")
endif
	@echo "$(C_BLUE)*** [$(C_YELLOW)PATH VAR$(C_BLUE)] $(C_BLANK)"
	@echo "$(C_OK) LOCAL = $(PATH_ROOT)$(LOCAL)"
	@echo "$(C_BLUE)*** [$(C_YELLOW)MKDIR$(C_BLUE)] inc, src, lib $(C_BLANK)"
	@mkdir -p $(PATH_ROOT)$(LOCAL)/inc
	@echo "$(C_OK) mkdir $(PATH_ROOT)$(LOCAL)/inc"
	@mkdir -p $(PATH_ROOT)$(LOCAL)/src
	@echo "$(C_OK) mkdir $(PATH_ROOT)$(LOCAL)/src"
	@mkdir -p $(PATH_ROOT)$(LOCAL)/lib
	@echo "$(C_OK) mkdir $(PATH_ROOT)$(LOCAL)/lib"
	@echo "$(C_BLUE)*** [$(C_YELLOW)COPY$(C_BLUE)] $(C_BLANK)"
	@cp $(PATH_ROOT)/Makefile $(PATH_ROOT)$(LOCAL)/Makefile
	@echo "$(C_OK) cp $(PATH_ROOT)/Makefile $(PATH_ROOT)$(LOCAL)/Makefile"


clone:
ifeq ($(LOCAL), )
	$(error Syntaxe ex: clone LOCAL=\"/projets/libft\" GIT=\"/projet_libft\")
endif
ifeq ($(GIT), )
	$(error Syntaxe ex: clone LOCAL=\"/projets/libft\" GIT=\"/projet_libft\")
endif
	@echo "$(C_BLUE)*** [$(C_YELLOW)PATH VAR$(C_BLUE)] $(C_BLANK)"
	@echo "$(C_OK) LOCAL = $(PATH_ROOT)$(LOCAL)"
	@echo "$(C_OK) GIT = $(PATH_GITHUB)$(GIT).git"
	@echo "$(C_BLUE)*** [$(C_YELLOW)REMOVE$(C_BLUE)] $(PATH_ROOT)$(LOCAL)$(C_BLANK)"
	@rm -rf $(PATH_ROOT)$(LOCAL)	
	@echo "$(C_BLUE)*** [$(C_YELLOW)CLONE$(C_BLUE)] $(PATH_GITHUB)$(GIT).git$(C_BLANK)"
	@git clone $(PATH_GITHUB)$(GIT).git $(PATH_ROOT)$(LOCAL)
	@echo "$(C_BLUE)*** [$(C_YELLOW)DONE$(C_BLUE)] LS $(PATH_ROOT)$(LOCAL)$(C_BLUE)"
	@ls -la $(PATH_ROOT)$(LOCAL)
	@echo -n "$(C_BLANK)"
	@pwd
