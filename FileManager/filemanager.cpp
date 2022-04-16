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
    QString name = inputFile_.fileName();
    QStringList parts = name.split("/");
    QString lastBit = parts.at(parts.size()-1);
    outputFile_.setFileName(outputFile_.fileName() + "/" + "[OUTPUT {" + QString::number(time.currentSecsSinceEpoch()) + "}] " + lastBit);
}

// Default name for the output file
void FileManager::default_Output()
{
    QString name = inputFile_.fileName();
    QStringList parts = name.split("/");
    QString lastBit = parts.at(parts.size()-1);
    outputFile_.setFileName(outputFile_.fileName() + "/" + "[OUTPUT] " + lastBit);
}

// Reading from a file.
QByteArray FileManager::read_File()
{
    QByteArray data = inputFile_.readAll();
    return data;
}

/* Writing to selected file.
 * Overload method
 * Type: QByteArray */
void FileManager::write_File(QByteArray data)
{
    outputFile_.write(data);
}

// Deleting the input file after finishing working with it.
void FileManager::remove_Input()
{
    inputFile_.remove();
}

// Checking files for the possibility of interacting with them.
bool FileManager::check_Streams()
{
    if (inputFile_.open(QFile::ReadOnly))
    {
        if (outputFile_.open(QFile::WriteOnly))
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
