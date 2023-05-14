#pragma once
#include <string>

#include "AccessTest4Dlg.h"

class DebugUtil
{
public:
    static CAccessTest4Dlg* dlg;
    static void print(std::string str);
};
