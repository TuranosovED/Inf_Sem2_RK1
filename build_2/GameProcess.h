#pragma once
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#include "Render.h"
#include "Structs.h"
#include "Defines.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"

void Typing(MassiveMemoryNeed necessity,obj**mas,stats *statistic,HANDLE ConsoleOutputHandle,int ListCounter,int MaxMistakes,int DeadTime);