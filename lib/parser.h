#ifndef parser_h__
#define parser_h__

typedef enum { ARG_STRING, ARG_BOOL } ARG_TYPE;

typedef struct {
  char *flag;
  char *description;
  char *value;
  ARG_TYPE type;
  int is_present;
} ARG;

typedef struct {
  ARG *args;
  int length; // DO NOT CHANGE!!!
} PARSER;

PARSER parser_init();
void parser_add_arg(PARSER *p, char *flag, char *description, ARG_TYPE type);
void parser_parse_args(PARSER *p, int argc, char **argv);
void parser_print_help(PARSER *p);
void parser_free(PARSER *p);

#endif