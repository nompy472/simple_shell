#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;
void prompt_user(void);
int _eputchar(char);
void _eputs(char *);
int checker(char **cmd, char *buf);
char **tokenizer(char *line);
void handle_signal(int m);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int exit_cmd(char **command, char *line);
int handle_builtin(char **command, char *line);
void print_env(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
void execution(char *cp, char **cmd);
void execution(char *cp, char **cmd);
char *_strchr(char *s, char c);
char *find_path(void);
void free_buffers(char **buf);

/**
 * struct flags - count input line
 * @interactive: checks mode
 */

struct flags
{
	bool interactive;
} flags;

/**
 * struct builtin - builtin fuction
 * @env: builtin command
 * @exit: exit function
 */

struct builtin
{
	char *env, *exit;
} builtin;

/**
 * struct info - with arguments
 * @final_exit: exits the function
 * @ln_count: counts error lines
 */

struct info
{
	int ln_count;
	int final_exit;
	int err_num;
	int argc;
	int status;
} info;


#endif
