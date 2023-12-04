#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SettingsLineEdit = ui->SettingsLineEdit;
    SettingsLineEdit->setPlaceholderText("Параметр настройки (N)");
    SettingsLineEdit->setStyleSheet("QLineEdit { padding-left: 40px; }");

    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::StartButtonClicked);
    connect(ui->StopButton, &QPushButton::clicked, this, &MainWindow::StopButtonClicked);
    connect(ui->RecodingButton, &QPushButton::clicked, this, &MainWindow::RecodingButtonClicked);
    isRecording = true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartButtonClicked()
{
    isRecording = false;
    qDebug() << "Запись в стек запущена.";
}

void MainWindow::RecodingButtonClicked()
{
    if (isRecording){
        qDebug() << "Запись в стек невозможна. Разрешите запись нажав кнопку старт.";
        return;
    }
    bool ok;
        int parameterValue = SettingsLineEdit->text().toInt(&ok);
        if (ok)
        {

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
    qDebug() << "Запись в стек остановлена.";
}

