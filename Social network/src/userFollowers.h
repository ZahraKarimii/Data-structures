#include <QMap>
#include <QFile>
#include <QList>
#include <QTextStream>
#include "user.h"
#include <algorithm>

class userFriends
{
public:
    QString username, friendsUsername;
};

class friends
{
public:
    QList<userFriends>friends;
    userInformation userInfo;
    void writeFriends()
    {
        QFile file("E:/QtProjects/finalProject/userFriends.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        for (userFriends &userFriend : friends)
        {
            out << "username: " << userFriend.username << ", " << "frineds: " << userFriend.friendsUsername << endl;
        }
        file.flush();
        file.close();
    }
    void deleteUser(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userFriends.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        if (file.open(QFile::ReadWrite | QFile::Text))
        {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd())
            {
                QString line = in.readLine();
                if (!line.contains("username: " + username) && !line.contains("frineds: " + username))
                {
                    lines.append(line);
                }
            }
            file.resize(0);
            QTextStream out(&file);
            for (const QString &line : lines)
            {
                out << line << endl;
            }
        }
            file.close();
    }
    QMap<QString, QList<QString>> readFriends(QString username)
    {
        QMap<QString, QList<QString>> usersFriends;
        QFile file("E:/QtProjects/finalProject/userFriends.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return usersFriends;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[0].split(": ")[1];
            if (Username == username)
            {
                QString UserFriend = parts[1].split(": ")[1];
                usersFriends[username].append(UserFriend);
            }
        }
        file.close();
        return usersFriends;
    }
    QMultiMap<double, QString> calculateRate(QString username)
    {
        QMap<QString, QList<QString>> usersFriends = readFriends(username);
        QList<QString> userFriends = usersFriends[username];
        QMultiMap<double, QString> similarityMap;
        for (const QString &friendName : userFriends)
        {
            QMap<QString, QList<QString>> friendFriends = readFriends(friendName);
            QList<QString> friendList = friendFriends[friendName];
            QList<QString> commonFriends;
            for (const QString &userFriend : userFriends)
            {
                if (friendList.contains(userFriend))
                {
                    commonFriends.append(userFriend);
                }
            }
            double commonFriendCount = commonFriends.size();
            QList<QString> totalUniqueFriends = userFriends;
            for (const QString &friends : friendList)
            {
                if (!totalUniqueFriends.contains(friends))
                {
                    totalUniqueFriends.append(friends);
                }
            }
            double totalUniqueFriendCount = totalUniqueFriends.size();
            double similarity = commonFriendCount / totalUniqueFriendCount;
            similarityMap.insert(similarity, friendName);
        }
        QList<double> sort = similarityMap.keys();
        std::sort(sort.begin(), sort.end(), std::greater<double>());
        QMultiMap<double, QString> sortedMap;
        for (const double &key : sort)
        {
            for (const QString &data : similarityMap.value(key))
            {
                sortedMap.insert(key, data);
            }
        }
        return sortedMap;
    }
    QList<QString> suggest(QString username)
    {
        QMap<QString, QList<QString>> usersFriends = readFriends(username);
        QList<QString> userFriends = usersFriends[username];
        QList<QString> suggestFriends;
        for (const QString &friendName : userFriends)
        {
            QMap<QString, QList<QString>> friendFriends = readFriends(friendName);
            QList<QString> friendList = friendFriends[friendName];
            for (const QString &suggestFriend : friendList)
            {
                if (!userFriends.contains(suggestFriend) && suggestFriend != username)
                {
                    suggestFriends.append(suggestFriend);
                }
            }
        }
        QMultiMap<double, QString> similarityMap = calculateRate(username);
        QList<QString> sortedSuggestFriends;
        for (const double &similarity : similarityMap.keys())
        {
            for (const QString &friendName : similarityMap.values(similarity))
            {
                if (suggestFriends.contains(friendName))
                {
                    sortedSuggestFriends.append(friendName);
                }
            }
        }
        return sortedSuggestFriends;
    }
    bool isFriend(QString username, QString friendUsername)
    {
        QMap<QString, QList<QString>> usersFriend = readFriends(username);
        if (usersFriend[username].contains(friendUsername))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    QList<QString> recentUsers(QString username)
    {
        QList<QString> newUsers;
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd())
            {
                lines.append(in.readLine());
            }
            for (int i = lines.size() - 1 ; i >= 0 && newUsers.size() < 6 ; i--)
            {
                QString line = lines[i];
                if (line.contains("username: "))
                {
                    QStringList parts = line.split(", ");
                    for (const QString &part : parts)
                    {
                        if (part.startsWith("username: "))
                        {
                            QString Username = part.split(": ")[1];
                            if (Username != username && !isFriend(username, Username) && !newUsers.contains(Username))
                            {
                                newUsers.append(Username);
                                break;
                            }
                        }
                    }
                }
            }
            file.close();
        }
        return newUsers;
    }
    QList<QString> suggestion(QString username)
    {
        QList<QString> suggestFriends = suggest(username);
        if (suggestFriends.size() < 6)
        {
            QList<QString> newRecentUsers = recentUsers(username);
            for (const QString &recent : newRecentUsers)
            {
                if (suggestFriends.size() < 6)
                {
                    suggestFriends.append(recent);
                }
                else
                {
                    break;
                }
            }
        }
        else if (suggestFriends.size() > 6)
        {
            suggestFriends = suggestFriends.mid(0, 6);
        }
        return suggestFriends;
   }
};
