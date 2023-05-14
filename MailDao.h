#pragma once
#include <list>
#include <string>
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

    
};
