#include <stdlib.h>
#include <string.h>

typedef enum argument_type { ARG_STRING, ARG_BOOL } ARG_TYPE;

typedef struct argument {
  char *flag;
  char *description;
  char *value;
  ARG_TYPE type;
  uint is_present;
} ARG;

typedef struct parser {
  ARG *args;
  int length; // DO NOT CHANGE!!!
} PARSER;

PARSER parser_init() {

  PARSER p;
  p.length = 0;
  p.args = malloc(sizeof(ARG));

  return p;
}

void parser_add_arg(PARSER *p, char *flag, char *description, ARG_TYPE type) {

  p->length++;

  for (uint i = 1; i <= p->length; i *= 2) {
    if (i == p->length) {

      p->args = realloc(p->args, p->length * sizeof(ARG) * 2);
    }
  }

  if (p->args == NULL) {

    printf("Failed to allocate memory\n");
    exit(1);
  }

  p->args[p->length - 1] = (ARG){flag, description, NULL, type, 0};
}

void parser_parse_args(PARSER *p, int argc, char **argv) {

  for (uint i = 0; i < argc; i++) {

    for (uint j = 0; j < p->length; j++) {

      if (!strcmp(argv[i], p->args[j].flag)) {

        p->args[j].is_present = 1;
      }

      if (p->args[j].type == ARG_STRING) {

          p->args[j].value = argv[i + 1];
      }
    }
  }
}

void parser_print_help(PARSER *p) {
  for (uint i = 0; i < p->length; i++) {
    printf("\t%s - %s\n", p->args[i].flag, p->args[i].description);
  }
}

void parser_free(PARSER *p) {
  free(p->args);
  p->args = NULL;
}