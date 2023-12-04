#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <stack>
#include <vector>

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
private:
    Ui::MainWindow *ui;
    QLineEdit *SettingsLineEdit;
    std::stack<std::vector<int>> arrayStack;
    bool isRecording;
};
#endif // MAINWINDOW_H
