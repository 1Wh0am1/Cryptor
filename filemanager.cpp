#include "filemanager.h"

// Initial initialization of the file manager
FileManager::FileManager(QString input, QString output)
{
    inputFile_.setFileName(input);
    outputFile_.setFileName(output);
}

FileManager::~FileManager()
{
    inputFile_.close();
    outputFile_.close();
}

// Changing the path to the input file
void FileManager::select_Input_File(QString input)
{
    inputFile_.setFileName(input);
}

//Changing the path to the output file
void FileManager::select_Output_File(QString output)
{
    outputFile_.setFileName(output);
}

// Unique name for the output file
void FileManager::unique_Output()
{
    QDateTime time;
    QString fileName = "";
    fileName = outputFile_.fileName() + "/output";
    fileName += " {" + QString::number(time.currentSecsSinceEpoch()) + "}";
    fileName += ".txt";
    outputFile_.setFileName(fileName);
}

// Default name for the output file
void FileManager::default_Output()
{
    QString fileName = "";
    fileName = outputFile_.fileName() + "/output";
    fileName += ".txt";
    outputFile_.setFileName(fileName);
}

// Reading from a file.
QByteArray FileManager::read_File()
{
    QByteArray data = inputFile_.readAll();
    return data;
}

/* Writing to selected file.
 * Overload method
 * Type: QString */
void FileManager::write_File(QString data)
{
    QTextStream out(&outputFile_);
    out << data;
}

/* Writing to selected file.
 * Overload method
 * Type: QByteArray */
void FileManager::write_File(QByteArray data)
{
    QTextStream out(&outputFile_);
    out << data;
}

// Deleting the input file after finishing working with it.
void FileManager::remove_Input()
{
    inputFile_.remove();
}

// Checking files for the possibility of interacting with them.
bool FileManager::check_Streams()
{
    if (inputFile_.open(QFile::ReadOnly | QFile::Text))
    {
        if (outputFile_.open(QFile::WriteOnly | QFile::Text))
        {
            return true;
        }
    }
    return false;
}

void FileManager::close_Files()
{
    inputFile_.close();
    outputFile_.close();
}
