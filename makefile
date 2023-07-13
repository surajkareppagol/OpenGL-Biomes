CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = render_biomes.c cube_in_biomes.c objects.c
ICNS = opengl_constants.h render_biomes.h objects.h

main:	$(SRCS) $(INCS)
	@$(CC) $(SRCS) -o main -lglut -lGLU -lGL -lm
	@echo "Build is done.\nTry \"./make\" or \"make run\"."

.PHONY: run
run:
	@clear && ./main

.PHONY: clean
clean:
	@rm main