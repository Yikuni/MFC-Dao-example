#include "pch.h"
#include "DebugUtil.h"

void DebugUtil::print(std::string str)
{
    CString strC;
    strC = CA2T(str.c_str());
    AfxMessageBox(strC);
}
