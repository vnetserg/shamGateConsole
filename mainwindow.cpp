#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_tick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer_tick()
{
    QString pattern = "%1:%2";
    ui->timerLabel->setText(pattern.arg(secs_left/60, 2, 10, QChar('0')).arg(secs_left%60, 2, 10, QChar('0')));
    if (secs_left > 0)
        secs_left -= 1;
}

void MainWindow::on_codeButton_clicked()
{
    QString text = ui->codeEdit->text().toLower();
    if (text == QString("активация")) {
        secs_left = 1200;
        timer_tick();
        ui->mainStack->setCurrentWidget(ui->timerPage);
        timer->start(1000);
    }
    else {
        QSound::play(":/sound/alarm.wav");
        QMessageBox::critical(this, "Ошибка", "НЕВЕРНЫЙ КОД АКТИВАЦИИ. Активирована система защиты, немедлено вернитесь в главное здание лаборатории!");
    }
}
