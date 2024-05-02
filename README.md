# Argument Parser

A simple argument parser library written for C.

# Usage

### Initialize a parser
As shown in [example code](https://github.com/MaxV906/Argument-Parser/blob/main/example.c), a parser can be initialized as following:
```C
PARSER p = parser_init();
```
### Adding arguments
Once you have your parser initialized, you can start adding arguments. You can do this as following:
```C
parser_add_arg(&p, "-t", "test argument", ARG_STRING);
```
This function requires a pointer to the parser object, a argument flag, argument description, and a **argument type**.

Avaliable **argument types** are:
* ARG_STRING
* ARG_BOOL
```C
typedef enum argument_type { ARG_STRING, ARG_BOOL } ARG_TYPE;
```

**ARG_STRING** stores the argument vulue while **ARG_BOOL** doesn't.

## Parsing arguments

Once you're done adding your arguments, you can start parsing them. To parse the arguments, you can use the following function:

```C
parser_parse_args(&p);
```

This function only requires a pointer to the parser structure.

Once the arguments are parsed, you can check their values, descriptions and if the argument has been used.

This is a argument structure:
```C
typedef struct argument {
  char *flag;
  char *description;
  char *value;
  ARG_TYPE type;
  uint is_present;
} ARG;
```

ARG.is_present will return **1** if it's **been used** as an argument.

The following function will print out all the argument flags and their descriptions.
```C
parser_print_help(&p);
```

Once you're done using the parser, use the following function:
```C
parser_free(&p);
```
This will free the allocated space and set PARSER.args to NULL.

## Important!!!
Don't change the **length** of the parser, as this will cause bugs.
PARSER.length **is not** supposed to be changed, it's meant to be automatically ised by parser functions.

# Installation

You can install the parser library by running the following commands:
```bash
make
sudo make install
```