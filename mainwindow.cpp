#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Checkers)
{
    ui->setupUi(this);

    ui->AboutFrame->setStyleSheet("QLabel {color: #e7c997;}");

    ui->NextButton->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));


    ui->AboutButton->setEnabled(true);
    ui->PlayButton->setEnabled(true);
    ui->AboutFrame->setEnabled(false);
    ui->AboutFrame->setVisible(false);


    aboutDescriptions << "Welcome to the Checkers game!"
                      << "The objective is to capture all of your opponent's pieces."
                      << "You can only move diagonally on the dark squares."
                      << "When a piece reaches the opposite end, it is crowned."
                      << "Crowns can move both diagonally and forward."
                      << "You can capture an opponent's piece by jumping over it."
                      << "Multiple captures are allowed in a single turn."
                      << "If you cannot make a move, you lose."
                      << "The player who captures all the opponent's pieces wins."
                      << "Enjoy the game and have fun!";

    updateDescription();

}



MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_PlayButton_clicked()
{

}


void MainWindow::on_AboutButton_clicked()
{
    ui->AboutButton->setVisible(false);
    ui->PlayButton->setVisible(false);
    ui->NextButton->setVisible(true);
    ui->AboutFrame->setVisible(true);
    ui->AboutFrame->setEnabled(true);


}

void MainWindow::updateDescription()
{
    if (currentIndex >= 0 && currentIndex < aboutDescriptions.size()) {
        ui->AboutTextLabel->setText(aboutDescriptions[currentIndex]);
    }
    ui->PrevButton->setEnabled(currentIndex > 0);
    ui->NextButton->setEnabled(currentIndex < aboutDescriptions.size() - 1);
}

