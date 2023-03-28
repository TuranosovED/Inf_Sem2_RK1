#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Defines.h"
#include "Structs.h"

char * TxtFormat(char **path,char* copy);
MassiveMemoryNeed FileLen(char*FileName);
void InputFromFile(MassiveMemoryNeed necessity,obj **mas, char *path);