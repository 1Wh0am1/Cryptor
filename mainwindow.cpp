#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(60000);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

// Checks for filling in the input data.
bool MainWindow::check_input()
{
    if (ui->selectLineEdit->displayText().isEmpty())
    {
        QMessageBox::information(this, "[Input]", "Input path is empty!");
    }
    else
    {
        if (ui->outputLineEdit->displayText().isEmpty())
        {
            QMessageBox::information(this, "[Output]", "Outputh path is empty!");
        }
        else
        {
            if (ui->inputLineEdit->displayText().isEmpty())
            {
                QMessageBox::information(this, "[Output]", "Key value is empty!");
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}


// The method responsible for setting up timer-based methods
void MainWindow::update_time()
{
    if (ui->onceCheckBox->checkState() == Qt::CheckState::Unchecked)
    {
        if (ui->onceSpinBox->value() > 0)
        {
            timer->singleShot(NULL, this, SLOT(check_input()));
            timer->singleShot(NULL, this, SLOT(on_savePushButton_clicked()));
            timer->setInterval(ui->onceSpinBox->value()*1000*60);
        }
    }
}

// the method responsible for starting file encryption.
void MainWindow::on_startPushButton_clicked()
{
    if (check_input())
    {
        FileManager fm(ui->selectLineEdit->displayText(), ui->outputLineEdit->displayText());
        Crypt crypt;

        if (ui->writeMode->currentIndex() == 0)
         {
             fm.default_Output();
         }
         else if (ui->writeMode->currentIndex() == 1)
         {
             fm.unique_Output();
         }

         if (!fm.check_Streams())
         {
            QMessageBox::critical(this, "[ Input | Output ]", "[Input] file is open in another program or file isn't opened!");
         }

        crypt.load_Data(fm.read_File());
        crypt.load_Key(ui->inputLineEdit->displayText().toLocal8Bit());

        fm.write_File(crypt.encryption());

         if (ui->inputCheckBox->checkState())
         {
            fm.remove_Input();
         }

         fm.close_Files();
    }
}

// The method responsible for the value of the mask checkbox
void MainWindow::on_maskCheckBox_stateChanged()
{
    if (ui->maskCheckBox->checkState())
    {
        ui->maskComboBox->setEnabled(true);
    }
    else
    {
        ui->maskComboBox->setEnabled(false);
    }
}

// The method responsible for the values of the path selection of the output directory
void MainWindow::on_outputToolButton_clicked()
{
    QString file_name = QFileDialog::getExistingDirectory(this, "Select a directory", "C:\\");
    ui->outputLineEdit->setText(file_name);
}

// The method responsible for the values of the input file path selection
void MainWindow::on_selectToolButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Select a file", "C:\\");
    ui->selectLineEdit->setText(file_name);
}

// The method responsible for the value of the reusable operation of the program
void MainWindow::on_onceCheckBox_stateChanged()
{
    if (ui->onceCheckBox->checkState())
    {
        ui->onceSpinBox->setEnabled(false);
        ui->inputTimerCheckBox->setEnabled(false);
    }
    else
    {
        ui->onceSpinBox->setEnabled(true);
        ui->inputTimerCheckBox->setEnabled(true);
    }
}

