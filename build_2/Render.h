#pragma once 
#include <Windows.h>
#include <stdio.h>

#include "Structs.h"
#include "Defines.h"

void ListRender(obj **mas,MassiveMemoryNeed necessity,int ListCounter,HANDLE ConsoleHandle);
void Render(obj mas,HANDLE ConsoleHandle,int ListCounter, int ShiftX , int ShiftY);