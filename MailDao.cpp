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
}
