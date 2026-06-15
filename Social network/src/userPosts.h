#include <QString>
#include <QMap>
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QStringList>

class userPost
{
public:
    QString username, post;
};

class post
{
public:
    QList<userPost>posts;
    void writePost()
    {
        QFile file("E:/QtProjects/finalProject/userPosts.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        for (userPost &userPosts : posts)
        {
            out << "username: " << userPosts.username << ", " << "post: " << userPosts.post << endl;
        }
        file.flush();
        file.close();
    }
    void writeForEdit(QStringList newPost, QString username)
    {
        QFile file("E:/QtProjects/finalProject/userPosts.txt");
        if (!file.open(QFile::Append | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        for (const QString &post : newPost)
        {
            out << "username: " << username << ", " << "post: " << post << endl;
        }
        file.flush();
        file.close();
    }
    void deletePost(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userPosts.txt");
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
    void deleteUser(QString username)
    {
        QFile file("E:/QtProjects/finalProject/userPosts.txt");
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
    QMap<QString, QList<QString>> readPost(QString username)
    {
        QMap<QString, QList<QString>> usersPosts;
        QFile file("E:/QtProjects/finalProject/userPosts.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            return usersPosts;
        }
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(", ");
            QString Username = parts[0].split(": ")[1];
            if (Username == username)
            {
                QString post = parts[1].split(": ")[1];
                usersPosts[username].append(post);
            }
        }
        file.close();
        return usersPosts;
    }
};
