#include "pch.h"
#include "DBManager.h"
DBManager *DBManager::INSTANCE = nullptr;
std::mutex DBManager::mutex;

DBManager* DBManager::GetInstance()
{
    if (INSTANCE == nullptr)
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (INSTANCE == nullptr)
        {
            INSTANCE = new DBManager();
        }
    }
    return INSTANCE;
}

void DBManager::DeleteInstance()
{
    std::unique_lock<std::mutex> lock(mutex);
    if (INSTANCE)
    {
        delete INSTANCE;
        INSTANCE = nullptr;
    }
}

bool DBManager::loadDB(const char* name)
{
    try
    {
        std::string connectUrl = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
        connectUrl.append(name);
        connection->Open(connectUrl.data(), "", "", adModeUnknown);
    }catch (_com_error &e)
    {
        return false;
    }
    return true;
}

_RecordsetPtr DBManager::ExecuteSql(std::string sql)
{
    _RecordsetPtr rs;
    rs.CreateInstance(_uuidof(Recordset));
    rs->Open(sql.data(),
        connection.GetInterfacePtr(), 
        adOpenDynamic,
        adLockOptimistic,
        adCmdText);
    return rs;
}

_RecordsetPtr DBManager::GetWritter(std::string tableName)
{
    // 不考虑高并发
    if (writterMap[tableName] == nullptr)
    {
        _RecordsetPtr rs;
        rs.CreateInstance(_uuidof(Recordset));
        rs->Open(("select * from " + tableName).c_str(),
                 connection.GetInterfacePtr(), 
                 adOpenDynamic,
                 adLockOptimistic,
                 adCmdText);
        writterMap[tableName] = rs;
        return rs;
    }
    return writterMap[tableName];
}

DBManager::DBManager()
{
    connection.CreateInstance(__uuidof(Connection));
}



