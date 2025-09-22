ALL_GOALS := all run re gdb clean fclean
EXTRA_GOALS := $(filter-out $(ALL_GOALS),$(MAKECMDGOALS))
$(EXTRA_GOALS): ;

# default
PROG_LANG ?= c
PROBLEM   ?= _maketest
SCRIPT    ?= hello.c
ASAN      = -fsanitize=address,undefined

IGNORE_GOALS := all re run gdb
ARGS = $(filter-out $(IGNORE_GOALS),$(MAKECMDGOALS))

ifeq ($(words $(ARGS)),1)
  PROG_LANG := $(word 1,$(ARGS))
endif
ifeq ($(words $(ARGS)),2)
  PROG_LANG := $(word 1,$(ARGS))
  PROBLEM   := $(word 2,$(ARGS))
endif
ifeq ($(words $(ARGS)),3)
  PROG_LANG := $(word 1,$(ARGS))
  PROBLEM   := $(word 2,$(ARGS))
  SCRIPT    := $(word 3,$(ARGS))
endif

.DEFAULT_GOAL := all

all: run

run:
	@echo "PROG_LANG = $(PROG_LANG)"
	@echo "PROBLEM   = $(PROBLEM)"
	@echo "SCRIPT    = $(SCRIPT)"
	@bash ./run.sh $(PROG_LANG) $(PROBLEM) $(SCRIPT)
	valgrind --track-origins=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./a.out

gdb:
	@bash ./run.sh $(PROG_LANG) $(PROBLEM) $(SCRIPT) $(ASAN)
	gdb ./a.out

clean:
	rm -rf ./*.o

fclean: clean
	rm -rf ./a.out

re: fclean all

%:
	@:

.PHONY: all run gdb clean fclean re