#pragma once
#include <list>

#include "TAccount.h"
using namespace std;
#include<string>
class AccountDao
{
public:
    /**
     * 插入账号, 插入前需要检查账号是否重复
     * @param mailName 邮箱名, 比如yikuni@qq.com 则mailName = yikuni
     * @param password 密码明文
     */
    static void insert(string mailName, string password);

    /**
     * 通过邮箱名查找账号
     * @param mailName 邮箱名
     * @return 查找到, 返回该邮箱数据, 没有查找到, 返回nullptr
     */
    static TAccount* selectByMailName(string mailName);

    /**
     * 查找所有账号
     * @return 所有账号的list
     */
    static list<TAccount*>* selectAll();

    /**
     * 删除账号, 不会自动清空邮件
     * @param id 账号id
     */
     static void deleteByPrimaryKey(int id);

     /**
      * 根据主键修改账号信息
      * @param account 账号实体, 所有字段都不能为空
      */
     static void updateByPrimaryKey(TAccount& account);
};
