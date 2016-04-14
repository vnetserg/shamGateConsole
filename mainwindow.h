#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_codeButton_clicked();
    void timer_tick();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int secs_left;
};

#endif // MAINWINDOW_H
