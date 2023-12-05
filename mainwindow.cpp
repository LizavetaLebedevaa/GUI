#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QThread>
#include <QHostAddress>
#include <QDateTime>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    SettingsLineEdit = ui->SettingsLineEdit;
    SettingsLineEdit->setPlaceholderText("Параметр настройки (N)");
    SettingsLineEdit->setStyleSheet("QLineEdit { padding-left: 40px; }");

    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::StartButtonClicked);
    connect(ui->StopButton, &QPushButton::clicked, this, &MainWindow::StopButtonClicked);
    connect(ui->RecodingButton, &QPushButton::clicked, this, &MainWindow::RecodingButtonClicked);
    isRecording = true;
    udpSocket = new QUdpSocket(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartButtonClicked()
{
    isRecording = false;
    updateListView("Start button clicked");
    qDebug() << "Запись в стек запущена.";
}

void MainWindow::RecodingButtonClicked()
{
    if (isRecording){
        updateListView("Recording button clicked - Recording not allowed");
        qDebug() << "Запись в стек невозможна. Разрешите запись нажав кнопку старт.";
        return;
    }
    bool ok;
        int parameterValue = SettingsLineEdit->text().toInt(&ok);
        if (ok)
        {

            updateListView("Recording button clicked - Array recorded");
            qDebug() << "В стек был записан массив из : " << parameterValue <<" элементов";
            std::vector<int> randomArray(parameterValue);
                for (int i = 0; i < parameterValue; i++) {
                    randomArray[i] = rand() % 100;
                    qDebug()  << randomArray[i] << " ";
                }
            arrayStack.push(randomArray);
        }
        else
        {

            qDebug() << "Неверный ввод. Пожалуйста, введите допустимое целое число.";
        }
}

void MainWindow::StopButtonClicked()
{
    isRecording = true;
    updateListView("Stop button clicked");
    qDebug() << "Запись в стек остановлена.";
}

void MainWindow::updateListView(const QString &message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QStandardItem *item = new QStandardItem(currentDateTime + " - " + message);
    model->appendRow(item);
}
