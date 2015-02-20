#pragma once
#include "stdafx.h"

void SearchString(FILE *F, const char * search_str, const char * replace_str, void(*replacement)(int id, char name[len], int count));