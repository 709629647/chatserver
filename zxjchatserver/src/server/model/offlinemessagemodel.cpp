#include "offlinemessagemodel.hpp"
#include "db.hpp"
bool OfflineMessageModel::insert(OfflineMessage &offlinemessage)
{
    char sql[1024];
    sprintf(sql, "insert into OfflineMessage(userid, message) values(%d, '%s')",
            offlinemessage.getuserid(), offlinemessage.getmessage().c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}

vector<string> OfflineMessageModel::query(int id)
{
    char sql[1024];
    vector<string> vec;
    sprintf(sql, "select message from OfflineMessage where userid = %d", id);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row ;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                vec.push_back(*row);
            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}

bool OfflineMessageModel::remove(int id)
{
    char sql[1024];
    sprintf(sql, "delete from OfflineMessage  where userid = %d",
             id);
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}