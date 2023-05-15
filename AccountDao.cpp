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

list<TAccount*>* AccountDao::selectAll()
{
    string sql = "select * from t_account";
    auto rs = DBManager::GetInstance()->ExecuteSql(sql);
    auto accounts = new list<TAccount*>;
    while (!rs->adoEOF)
    {
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
        rs->MoveNext();
        accounts->push_back(result);
    }
    return accounts;
}

void AccountDao::deleteByPrimaryKey(int id)
{
    DBManager::GetInstance()->ExecuteSql("delete from t_account where ID = " + std::to_string(id));
}

void AccountDao::updateByPrimaryKey(TAccount& account)
{
    auto rs = DBManager::GetInstance()->GetWritter("t_account");
    rs->MoveFirst();
    while(!rs->adoEOF)
    {
        string strID;
        _variant_t var;
        var = rs->GetCollect("ID");
        strID = _bstr_t(var);
        int id = stoi(strID);
        if (id == account.id)
        {
         // 如果找到了
            rs->PutCollect("mail_name", account.mailName.c_str());
            rs->PutCollect("password", account.password.c_str());
            rs->Update();
            break;
        }
        rs->MoveNext();
    }
    rs->MoveLast();
}
