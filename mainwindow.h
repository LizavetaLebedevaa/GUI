#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QUdpSocket>
#include <QMainWindow>
#include <QLineEdit>
#include <stack>
#include <vector>
#include <QStandardItemModel>

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
    void StartButtonClicked();
    void StopButtonClicked();
    void RecodingButtonClicked();
    void updateListView(const QString &message);

private:
    Ui::MainWindow *ui;
    QLineEdit *SettingsLineEdit;
    std::stack<std::vector<int>> arrayStack;
    bool isRecording;
    QUdpSocket* udpSocket;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
