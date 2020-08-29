#pragma once

#ifndef PARSER
#define PARSER
#include<string.h>
#include "Data_structures.h"
#include "Assertion.h"
#include "Errors.h"

BOOL is_legal_label(char label[]);

BOOL is_legal_symbol(char symbol[]);

BOOL is_undefine_label(char label[]);

BOOL is_legel_string_data(char str[]);

BOOL is_legal_number(char var[]);

#endif




