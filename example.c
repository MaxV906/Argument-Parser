#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int main(int argc, char **argv) {

  PARSER p = parser_init();

  if (p.args != NULL) {

    parser_add_arg(&p, "-t", "test string arg", ARG_STRING);
    parser_add_arg(&p, "-g", "test bool arg", ARG_BOOL);
    parser_parse_args(&p, argc, argv);

    for (uint i = 0; i < p.length; i++) {

      printf("%s: %s - %s (%d)\n", p.args[i].flag, p.args[i].value,
             p.args[i].description, p.args[i].is_present);
    }

    printf("\nParser Demo Usage:\n\n");

    parser_print_help(&p);
	parser_free(&p);

  }

  return 0;
}
