#include "usermodel.hpp"
#include "db.hpp"
bool UserModel::insert(User &user)
{
    char sql[1024];
    sprintf(sql, "insert into User(name, password, state) values('%s', '%s', '%s');",
            user.getname().c_str(), user.getpassword().c_str(), user.getstate().c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            user.setid(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}

User UserModel::query(int id)
{
    char sql[1024];
    sprintf(sql, "select * from User where id = %d", id);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                User user(atoi(row[0]), row[1], row[2], row[3]);
                mysql_free_result(res);
                return user;
            }
        }
    }
    return User();
}
void UserModel::resetState()
{
    char sql[1024] ="update User set state = 'offline'";
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

bool UserModel::updateState(User &user)
{
    char sql[1024];
    sprintf(sql, "update User set state = '%s' where id = %d",
            user.getstate().c_str(), user.getid());
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