#include "groupmodel.hpp"

#include "db.hpp"
bool GroupModel::createGroup(Group &group)
{
    char sql[1024];
    sprintf(sql, "insert into ALLGroup(groupname, groupdesc) values('%s', '%s');",
            group.getgroupname().c_str(), group.getgroupdesc().c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            group.setgroupid(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}

vector<Group> GroupModel::queryGroup(int id)
{
    char sql[1024];
    sprintf(sql, "select b.* from GroupUser a inner join ALLGroup b on a.groupid = b.groupid where a.userid = %d", id);
    MySQL mysql;
    vector<Group> vec;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                Group group(atoi(row[0]), row[1], row[2]);
                vec.push_back(group);
            }
            mysql_free_result(res);
        }
    
    for (auto &group : vec)
    {
        sprintf(sql, "select a.id, a.name, a.state, b.grouprole from User a inner join GroupUser b \
    on a.id=b.userid and b.groupid = %d",
                group.getgroupid());

        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {

            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                GroupUser user(atoi(row[0]), row[1], "", row[2], row[3]);
                group.getgroupuser().push_back(user);
            }
            mysql_free_result(res);
        }
    }
    }
    return vec;
}
bool GroupModel::addGroup(int id, string role, int groupid)
{
    char sql[1024];
    sprintf(sql, "insert into GroupUser(groupid, userid, grouprole) values(%d, %d, '%s')",
            groupid, id, role.c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
        return true;
    }
    return false;
}

vector<int> GroupModel::queryGroupUser(int userid, int groupid)
{
    char sql[1024];
    sprintf(sql, "select userid from GroupUser where groupid = %d and userid != %d", groupid, userid);
    MySQL mysql;
    vector<int> vec;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {

            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                vec.push_back(atoi(*row));
            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}

Group GroupModel::queryGroupdesc(int groupid)
{
    char sql[1024];
    sprintf(sql, "select groupname, groupdesc from ALLGroup where groupid = %d", groupid);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {

            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                Group group(groupid, row[0], row[1]);
                mysql_free_result(res);
                return group;
            }
            
        }
    }
    return Group();
}