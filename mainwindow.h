#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>

#include "crypt.h"
#include "filemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_time();

    bool check_input();

    void on_startPushButton_clicked();

    void on_maskCheckBox_stateChanged();

    void on_outputToolButton_clicked();

    void on_selectToolButton_clicked();

    void on_onceCheckBox_stateChanged();
private:
    Ui::MainWindow *ui;
    QTimer *timer;

};
#endif // MAINWINDOW_H

