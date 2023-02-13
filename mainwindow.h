#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "include/classHd.h"
#include "include/vectorHd.h"
#include <QString>
#include <string>
#include <QDebug>
#include <vector>
#include <QListWidgetItem>

extern std::vector<Hopdong*> m_Hopdong;

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
    void on_btnFind_released();

    void on_btnHdngay_released();

    void on_btnHdthang_released();

    void on_btncapnhat_released();

    void on_btntinhtong_released();

    void on_btnsua_released();

    void on_btnxoa_released();

    void on_btnfindgiatri_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
