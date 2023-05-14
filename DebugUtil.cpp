#include "pch.h"
#include "DebugUtil.h"

CAccessTest4Dlg* DebugUtil::dlg = nullptr;
void DebugUtil::print(std::string str)
{
    CString strC;
    strC = CA2T(str.c_str());
    SetDlgItemTextW(*dlg, IDC_STATIC, strC);
}
