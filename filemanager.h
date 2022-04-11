#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QDateTime>
#include <QMessageBox>

/* File manager
 * The class responsible for working with files. */
class FileManager
{
public:
    FileManager(QString, QString);
    ~FileManager();

    void select_Input_File(QString);
    void select_Output_File(QString);
    void unique_Output();
    void default_Output();
    QByteArray read_File();
    void write_File(QString);
    void write_File(QByteArray);
    void remove_Input();
    bool check_Streams();
    void close_Files();


private:
    QFile inputFile_;
    QFile outputFile_;
};

#endif // FILEMANAGER_H
