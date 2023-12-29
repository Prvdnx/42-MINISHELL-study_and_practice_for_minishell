
#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// for source file ----------
#define EOF             (-1)
#define ERRCHAR         ( 0)

#define INIT_SRC_POS    (-2)
//---------------------------


void print_prompt1(void);
void print_prompt2(void);

char *read_cmd(void);


// for source.c (scanning input) -------------------------------
struct source_s
{   
    char *buffer;       /* the input text */
    long bufsize;       /* size of the input text */
    long  curpos;       /* absolute char position in source */
};

char next_char(struct source_s *src);
void unget_char(struct source_s *src);
char peek_char(struct source_s *src);
void skip_white_spaces(struct source_s *src);
//--------------------------------------------------------------


// for scanner.c (tokenizing input) ----------------------------
struct token_s
{
    struct source_s *src;       /* source of input */
    int    text_len;            /* length of token text */
    char   *text;               /* token text */
};

/* the special EOF token, which indicates the end of input */
extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);
//--------------------------------------------------------------






#endif
