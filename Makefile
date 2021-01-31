##
## EPITECH PROJECT, 2020
## 106bombyx_2019
## File description:
## Makefile
##

## ========================================================================== ##
ERROR_PATH		=	source/error/
ERROR_SRC		=	error_handling.c

## ========================================================================== ##
INIT_PATH		=	source/init/
INIT_SRC		=	init.c

## ========================================================================== ##
PROCESS_PATH	=	source/process/
PROCESS_SRC		=	process.c	\
					get.c

## ========================================================================== ##
DISPLAY_PATH	=	source/display/
DISPLAY_SRC		=	display.c

## ========================================================================== ##
FREE_PATH		=	source/free/
FREE_SRC		=	free.c

SRC				=	$(addprefix $(ERROR_PATH), $(ERROR_SRC))	\
					$(addprefix $(INIT_PATH), $(INIT_SRC))	\
					$(addprefix $(PROCESS_PATH), $(PROCESS_SRC))	\
					$(addprefix $(DISPLAY_PATH), $(DISPLAY_SRC))	\
					$(addprefix $(FREE_PATH), $(FREE_SRC))	\
					source/main.c

BIN				= 	108trigo

CC				= 	gcc

OBJ 			= 	$(SRC:.c=.o)

RM				=	rm

CFLAGS			=	-W -Wall -Werror

LDFLAGS			=	-lm -Llibrary -lopenf -Iinclude/

DFLAGS			=	-g -Wfatal-errors -Wpedantic -Wextra \
					-Wnonnull -Wmain -Wmissing-attributes -Wsequence-point -pg

LIBPATH			=	library

all:			$(BIN)

debug:			$(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(DFLAGS) -DDEBUG

$(BIN):			$(OBJ)
				@$(MAKE) -C library/_open/
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
				@$(RM) $(OBJ)
				@$(MAKE) -C library/_open/ clean

fclean:			clean
				$(RM) $(BIN)
				@$(MAKE) -C library/_open/ fclean

re:				fclean all

.PHONY:			 all, fclean, re, library

## ========================================================================== ##
%.o:	%.c
	@gcc $(LDFLAGS) -g -o $@ -c $<