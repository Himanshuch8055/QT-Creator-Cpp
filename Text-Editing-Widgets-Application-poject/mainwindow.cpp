#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path_ = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog :: getOpenFileName(this, "Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile :: ReadOnly | QFile :: Text)){
    QMessageBox :: warning(this, " ..", "file not open") ;
    return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path_);
    if(!file.open(QFile :: WriteOnly | QFile :: Text) ) {
    QMessageBox :: warning(this,"..", "file not open") ;
    return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText() ;
    out << text;
    file. flush();
    file.close();
}



void MainWindow::on_actionSave_As_triggered()
{
//    QString file_name = QFileDialog :: getOpenFileName(this, "Open the file");
//    QFile file(file_name);
//    file_path_ = file_name;
//    if(!file.open(QFile :: ReadOnly | QFile :: Text)){
//    QMessageBox :: warning(this, " ..", "file not open") ;
//    return;
//    }
//    QTextStream in(&file);
//    QString text = in.readAll();
//    ui->textEdit->setText(text);
//    file.close();

    QString file_name = QFileDialog :: getSaveFileName(this, "Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile :: WriteOnly | QFile :: Text)) {
    QMessageBox :: warning(this, "..", "file not open");
    return;
    }
    QTextStream out(& file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    ui->textEdit->close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}


void MainWindow::on_actionBold_triggered()
{
    ui->textEdit->fontWeight();
}


void MainWindow::on_actionItalic_triggered()
{
    ui->textEdit->fontItalic();
}


void MainWindow::on_actionUnderline_triggered()
{
    ui->textEdit->fontUnderline();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text = "Auther : somebody\n";
    about_text += "Date : 12/05/2016\n";
    about_text += " (C) Notepad (R)\n";
    QMessageBox :: about(this,"About Notepad",about_text);
}

