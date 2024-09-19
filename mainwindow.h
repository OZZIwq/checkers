#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Checkers;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PlayButton_clicked();

    void on_AboutButton_clicked();

private:
    Ui::Checkers *ui;
    QStringList aboutDescriptions;
    int currentIndex;
    void updateDescription();
};
#endif // MAINWINDOW_H
