#include "friendmodel.hpp"
#include "db.hpp"
bool FriendModel::insert(int userid, int friendid)
{
    char sql[1024];
    sprintf(sql, "insert into Friend(userid, friendid) values(%d, %d);",
            userid, friendid);
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

vector<User> FriendModel::query(int id)
{
    char sql[1024];
    sprintf(sql, "select a.id, a.name, a.state from User a inner join Friend b on b.friendid = a.id where b.userid = %d", id);
    MySQL mysql;
    vector<User> vec;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))!= nullptr)
            {
                User user;
                user.setid(atoi(row[0]));
                user.setname(row[1]);
                user.setstate(row[2]);
                vec.push_back(user);
            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}