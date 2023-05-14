#include "pch.h"
#include "AccountDao.h"

#include <iostream>

#include "DBManager.h"
#include "DebugUtil.h"

void AccountDao::insert(string mailName, string password)
{
    auto rs = DBManager::GetInstance()->GetWritter("t_account");
    rs->AddNew();
    rs->PutCollect("mail_name", mailName.c_str());
    rs->PutCollect("password", password.c_str());
    rs->Update( );
}

TAccount* AccountDao::selectByMailName(string mailName)
{
    string sql = "select * from t_account where mail_name = '" + mailName + "'";
    TRACE(sql.c_str());
    auto rs = DBManager::GetInstance()->ExecuteSql(sql);
    if(rs->BOF)
    {
        // 没有查找到
        return nullptr;
    }
    TAccount* result = new TAccount();
    string strID;
    _variant_t var;
    var = rs->GetCollect("ID");
    strID = _bstr_t(var);
    result->id = stoi(strID);
    var = rs->GetCollect("mail_name");
    result->mailName = _bstr_t(var);
    var = rs->GetCollect("password");
    result->password = _bstr_t(var);
    return result;
}

list<TAccount>* AccountDao::selectAll()
{
    return nullptr;
}

void AccountDao::deleteByPrimaryKey(int id)
{
    DBManager::GetInstance()->ExecuteSql("delete from t_account where ID = " + std::to_string(id));
}

void AccountDao::updateByPrimaryKey(TAccount& account)
{
}
