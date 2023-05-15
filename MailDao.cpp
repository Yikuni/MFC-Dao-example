#include "pch.h"
#include "MailDao.h"

#include "DBManager.h"

void MailDao::insert(int mailId, string title, string content, string from)
{
    auto rs = DBManager::GetInstance()->GetWritter("t_mail");
    rs->AddNew();
    rs->PutCollect("mail_id", mailId);
    rs->PutCollect("title", title.c_str());
    rs->PutCollect("content", content.c_str());
    rs->PutCollect("from", from.c_str());
    rs->Update( );
}

void MailDao::deleteByPrimaryKey(int id)
{
    DBManager::GetInstance()->ExecuteSql("delete from t_mail where ID = " + std::to_string(id));
}

list<TMail*>* MailDao::selectByMailId(int id)
{
    string sql = "select * from t_mail where mail_id = " + std::to_string(id);
    auto rs = DBManager::GetInstance()->ExecuteSql(sql);
    auto mails = new list<TMail*>;
    while (!rs->adoEOF)
    {
        TMail* result = new TMail();
        string strID, strMailID;
        _variant_t var;
        var = rs->GetCollect("ID");
        strID = _bstr_t(var);
        result->id = stoi(strID);
        var = rs->GetCollect("mail_id");
        strMailID = _bstr_t(var);
        result->mail_id = stoi(strMailID);
        var = rs->GetCollect("title");
        result->title = _bstr_t(var);
        var = rs->GetCollect("content");
        result->content = _bstr_t(var);
        var = rs->GetCollect("from");
        result->from = _bstr_t(var);
        rs->MoveNext();
        mails->push_back(result);
    }
    return mails;
}
