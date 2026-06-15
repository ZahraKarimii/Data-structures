#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QStringList>

class User
{
public:
    QString name, lastname, age, username, password;
};

class userInformation
{
public:
    QList<User>users;
    User user;
    static QString globalUsername;
    void deleteUser(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (file.open(QFile::ReadWrite | QFile::Text))
        {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd())
            {
                QString line = in.readLine();
                if (!line.contains("username: " + username))
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
            file.close();
        }
    }
    QList<QString> recentUser()
        {
            QList<QString> recentUsers;
            QFile file("E:/QtProjects/finalProject/loginInfo.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return recentUsers;
            }
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(", ");
                QString Username = parts[0].split(": ")[1];
                recentUsers.append(Username);
            }
            file.close();
            return recentUsers;
        }
    void writeUser()
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        for (User &user : users)
        {
            out << "name: " << user.name << ", " << "lastname: " << user.lastname << ", " << "age: " << user.age
                <<  ", " << "username: " << user.username << ", " << "password: " << user.password << endl;
        }
        file.flush();
        file.close();
    }
    void writeUsername(QString username)
    {
        QFile file("E:/QtProjects/finalProject/loginInfo.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << "username: " << username << endl;
        file.flush();
        file.close();
    }
    void deleteUser2(QString username)
    {
        QFile file("E:/QtProjects/finalProject/loginInfo.txt");
        if (file.open(QFile::ReadWrite | QFile::Text))
        {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd())
            {
                QString line = in.readLine();
                if (!line.contains("username: " + username))
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
            file.close();
        }
    }
    QString readUsername()
    {
        QFile file("E:/QtProjects/finalProject/loginInfo.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return "username";
        }

        QTextStream in(&file);
        QString lastLine;
        while (!in.atEnd())
        {
            lastLine = in.readLine();
        }
        file.close();
        if (!lastLine.isEmpty())
        {
            QStringList parts = lastLine.split(", ");
            if (!parts.isEmpty() && parts[0].contains(": "))
            {
                return parts[0].split(": ")[1];
            }
        }
        return "username";
    }
    bool readLogin(QString username, QString password)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            QString Password = parts[4].split(": ")[1];
            if (Username == username && Password == password)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readUsernameForEdit(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            if (Username == username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool searchUsername(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            if (Username == username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readName(QString username, QString name)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            QString Name = parts[0].split(": ")[1];
            if (Name == name && username == Username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readlastName(QString username, QString lastname)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            QString Lastname = parts[1].split(": ")[1];
            if (Lastname == lastname && username == Username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readAge(QString username, QString age)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            QString Age = parts[2].split(": ")[1];
            if (Age == age && username == Username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readPassword(QString username, QString password)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            QString Password = parts[4].split(": ")[1];
            if (Password == password && username == Username)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool readSignup(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userData.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[3].split(": ")[1];
            if (Username == username)
            {
                file.close();
                return true;
            }

        }
        file.close();
        return false;
    }
    void changeName (QString newName, QString username)
        {
            QFile file("E:/QtProjects/finalProject/userData.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return;
            }
            QStringList lines;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(", ");
                QString Username = parts[3].split(": ")[1];
                if (username == Username)
                {
                    parts[0] = "name: " + newName;
                }
                lines.append(parts.join(", "));
            }
            file.close();
            if (!file.open(QFile::WriteOnly | QFile::Text))
            {
                return;
            }
            QTextStream out(&file);
            for (const QString line : qAsConst(lines))
            {
                out << line << endl;
            }
            file.close();
        }
        void changeLastanem (QString newLastname, QString username)
        {
            QFile file("E:/QtProjects/finalProject/userData.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return;
            }
            QStringList lines;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(", ");
                QString Username = parts[3].split(": ")[1];
                if (username == Username)
                {
                    parts[1] = "lastanem: " + newLastname;
                }
                lines.append(parts.join(", "));
            }
            file.close();
            if (!file.open(QFile::WriteOnly | QFile::Text))
            {
                return;
            }
            QTextStream out(&file);
            for (const QString line : qAsConst(lines))
            {
                out << line << endl;
            }
            file.close();
        }
        void changeAge (QString newAge, QString username)
        {
            QFile file("E:/QtProjects/finalProject/userData.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return;
            }
            QStringList lines;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(", ");
                QString Username = parts[3].split(": ")[1];
                if (username == Username)
                {
                    parts[2] = "age: " + newAge;
                }
                lines.append(parts.join(", "));
            }
            file.close();
            if (!file.open(QFile::WriteOnly | QFile::Text))
            {
                return;
            }
            QTextStream out(&file);
            for (const QString line : qAsConst(lines))
            {
                out << line << endl;
            }
            file.close();
        }
        void changeUsername2(QString newUsername)
        {
            QFile file("E:/QtProjects/finalProject/loginInfo.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return;
            }
            QStringList lines;
            QTextStream in(&file);
            QString lastLine;
            while (!in.atEnd())
            {
                lastLine = in.readLine();
            }
            file.close();
            if (!lastLine.isEmpty())
            {
                QStringList parts = lastLine.split(", ");
                if (!parts.isEmpty() && parts[0].contains(": "))
                {
                   parts[0].split(": ")[1] = "username: " + newUsername;
                }
            }
            file.close();
            if (!file.open(QFile::WriteOnly | QFile::Text))
            {
                return;
            }
            QTextStream out(&file);
            for (const QString line : qAsConst(lines))
            {
                out << line << endl;
            }
            file.close();
        }
        void changePassword (QString newPassword, QString username)
        {
            QFile file("E:/QtProjects/finalProject/userData.txt");
            if (!file.open(QFile::ReadOnly | QFile::Text))
            {
                return;
            }
            QStringList lines;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(", ");
                QString Username = parts[3].split(": ")[1];
                QString Password = parts[4].split(": ")[1];
                if (username == Username)
                {
                    parts[4] = "password: " + newPassword;
                }
                lines.append(parts.join(", "));
            }
            file.close();
            if (!file.open(QFile::WriteOnly | QFile::Text))
            {
                return;
            }
            QTextStream out(&file);
            for (const QString line : qAsConst(lines))
            {
                out << line << endl;
            }
            file.close();
        }
};
