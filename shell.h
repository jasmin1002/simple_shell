#ifndef _SHELL_H_
#define _SHELL_H_

/** environ var */

extern char **environ;

/** MACROS */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/** LIBS USED */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/** STRING FUNCTION */

char *_strtok(char *, const char *);
unsigned int check_delim(char, const char *);
char *_strncpy(char *, char *, int);
int _strlen(char *);
int _putchar(char);
int _atoi(char *);
void _puts(char *);
int _strcmp(char *, char *);
int _isalpha(int);
void array_rev(char *, int);
int intlen(int);
char *_itoa(unsigned int);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strchr(char *, char);
int _strncmp(const char *, const char *, size_t);
char *_strdup(char *);

/** MEMORIE  MANGMENT */

void free_env(char **);
void *fill_an_array(void *, int, unsigned int);
char *_memcpy(char *, char *, unsigned int);
void *_calloc(unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void free_all(char **, char *);

/** INPUT Function */

void prompt(void);
void signal_to_handel(int);
char *_getline(void);

/** Command parser and extractor*/

int path_cmd(char **);
char *_getenv(char *);
char **parse_cmd(char *);
int handle_builtin(char **, int);
void read_file(char *, char **);
char *build(char *, char *);
int check_builtin(char **);
void creat_envi(char **);
int check_cmd(char **, char *, int, char **);
void treat_file(char *, int, FILE *, char **);
void exit_bul_for_file(char **, char *, FILE *);

/** BUL FUNC*/

void hashtag_handle(char *);
int history(char *);
int history_dis(char **, int);
int dis_env(char **, int);
int change_dir(char **, int);
int display_help(char **, int);
int echo_bul(char **, int);
void  exit_bul(char **, char *, char **, int);
int print_echo(char **);

/** error handle and Printer */
void print_number(unsigned int);
void print_number_in(int);
void print_error(char *, int, char **);
void _prerror(char **, int, char **);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
char *command;
int (*fun)(char **line, int er);
} bul_t;

#endif
