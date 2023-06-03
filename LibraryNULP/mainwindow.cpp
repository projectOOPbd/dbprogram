#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int windowWidth = width();
    int windowHeight = height();
    int x = screenGeometry.x() + (screenGeometry.width() - windowWidth) / 2;
    int y = screenGeometry.y() + (screenGeometry.height() - windowHeight) / 2;
    move(x, y);

    QTimer::singleShot(0, this, SLOT(updateProgress()));

    QPixmap NULP(":/picture/picture/1.png");
    ui->NULPLIB->setPixmap(NULP);
}

void MainWindow::updateProgress()
{
    static int value = 1;
    ui->progressBar->setValue(value++);

    QColor fillColor = QColor(72,162,137);
    QString fillStyle = QString("QProgressBar::chunk { background-color: %1; }").arg(fillColor.name());
    ui->progressBar->setStyleSheet(ui->progressBar->styleSheet() + fillStyle);

    if (value <= 100)
    {
        QTimer::singleShot(50, this, SLOT(updateProgress()));
    }else
    {
        hide();
        incoming in;
        in.show();
        in.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
