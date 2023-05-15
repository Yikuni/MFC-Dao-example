#pragma once
#include <list>
#include <string>

#include "TMail.h"
using namespace std;
class MailDao
{
public:
    /**
     * 插入邮件
     * @param mailId 邮件接收人在账号表的id
     * @param title 邮件标题
     * @param content 邮件内容
     * @param from 发送者
     */
    static void insert(int mailId, string title, string content, string from);

    /**
     * 根据主键删除邮件
     * @param id 邮件id
     */
    static void deleteByPrimaryKey(int id);

    /**
     * 通过邮箱id查找邮件
     * @param id 邮箱id
     * @return 该邮箱的所有邮件, 如果没有邮件, 则返回空的集合
     */
    static list<TMail*>* selectByMailId(int id);

    
};
