#pragma once
#include <mutex>
#include <unordered_map>

#include "stdafx.h"

class DBManager
{
public:
	static DBManager* GetInstance();
	static void DeleteInstance();

	bool loadDB(const char* name);
	_ConnectionPtr connection;
	_RecordsetPtr ExecuteSql(std::string sql);
	_RecordsetPtr GetWritter(std::string tableName);
	
	
private:
	DBManager();
	~DBManager() = default;
	DBManager(const DBManager &manager) = default;

	static DBManager *INSTANCE;
	static std::mutex mutex;
	std::unordered_map<std::string, _RecordsetPtr> writterMap;
};


