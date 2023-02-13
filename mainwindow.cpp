#include "mainwindow.h"

std::vector<Hopdong*> m_Hopdong;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int STT = 0;

void MainWindow::on_btnFind_released()
{
    QString hoten = ui->lineEdit->text();
    QString loaixe = ui->lineEdit->text();
    QString bienso = ui->lineEdit->text();

    STT = stt(m_Hopdong, hoten.toStdString());

    //Son code ham tim so thu tu (bat dau tu 0 -> n-1) cua hop dong theo ho ten nhe
    //Ham tra ve so thu tu cua don DAU TIEN co ket qua trung khop
    //int sothutu(std::vector<Hopdong*> &m_Hopdong, std::string hoten);

    for(int i = 0; i < m_Hopdong.size();i++) {
        if(
           ((m_Hopdong[i]->hoten).find(hoten.toStdString()) != std::string::npos) ||
            ((m_Hopdong[i]->loaixe).find(loaixe.toStdString()) != std::string::npos) ||
            ((m_Hopdong[i]->bienso).find(bienso.toStdString()) != std::string::npos)
                )
        {

            ui->linehoten->setText(QString::fromStdString(m_Hopdong[i]->hoten));
            ui->linecmt->setText(QString::fromStdString(m_Hopdong[i]->cmt));
            ui->lineloaixe->setText(QString::fromStdString(m_Hopdong[i]->loaixe));
            ui->linebienso->setText(QString::fromStdString(m_Hopdong[i]->bienso));
            ui->linengaythue->setText(QString::number(m_Hopdong[i]->start_time.tm_mday));
            ui->linethangthue->setText(QString::number(m_Hopdong[i]->start_time.tm_mon));
            ui->linenamthue->setText(QString::number(m_Hopdong[i]->start_time.tm_year));
            ui->linengaytra->setText(QString::number(m_Hopdong[i]->end_time.tm_mday));
            ui->linethangtra->setText(QString::number(m_Hopdong[i]->end_time.tm_mon));
            ui->linenamtra->setText(QString::number(m_Hopdong[i]->end_time.tm_year));
            break;
        }

    }
}




void MainWindow::on_btnHdngay_released()
{
    Hopdong* temp = new Hd_ngay;
    temp->hoten = ui->linehoten->text().toStdString();
    temp->cmt = ui->linecmt->text().toStdString();
    temp->loaixe = ui->lineloaixe->text().toStdString();
    temp->bienso = ui->linebienso->text().toStdString();
    temp->start_time.tm_mday = ui->linengaythue->text().toInt();
    temp->start_time.tm_mon = ui->linethangthue->text().toInt();
    temp->start_time.tm_year = ui->linenamthue->text().toInt();
    temp->end_time.tm_mday = ui->linengaytra->text().toInt();
    temp->end_time.tm_mon = ui->linethangtra->text().toInt();
    temp->end_time.tm_year = ui->linenamtra->text().toInt();
    m_Hopdong.push_back(temp);

    ui->linehoten->setText("");
    ui->linecmt->setText("");
    ui->lineloaixe->setText("");
    ui->linebienso->setText("");
    ui->linengaythue->setText("");
    ui->linethangthue->setText("");
    ui->linenamthue->setText("");
    ui->linengaytra->setText("");
    ui->linethangtra->setText("");
    ui->linenamtra->setText("");
}


void MainWindow::on_btnHdthang_released()
{
    Hopdong* temp = new Hd_thang;
    temp->hoten = ui->linehoten->text().toStdString();
    temp->cmt = ui->linecmt->text().toStdString();
    temp->loaixe = ui->lineloaixe->text().toStdString();
    temp->bienso = ui->linebienso->text().toStdString();
    temp->start_time.tm_mon = ui->linengaythue->text().toInt();
    temp->start_time.tm_mon = ui->linethangthue->text().toInt();
    temp->start_time.tm_year = ui->linenamthue->text().toInt();
    temp->end_time.tm_mday = ui->linengaytra->text().toInt();
    temp->end_time.tm_mon = ui->linethangtra->text().toInt();
    temp->end_time.tm_year = ui->linenamtra->text().toInt();
    m_Hopdong.push_back(temp);

    ui->linehoten->setText("");
    ui->linecmt->setText("");
    ui->lineloaixe->setText("");
    ui->linebienso->setText("");
    ui->linengaythue->setText("");
    ui->linethangthue->setText("");
    ui->linenamthue->setText("");
    ui->linengaytra->setText("");
    ui->linethangtra->setText("");
    ui->linenamtra->setText("");
}


void MainWindow::on_btncapnhat_released()
{

}


void MainWindow::on_btntinhtong_released()
{
    struct tm start_time, end_time;
    start_time.tm_mday = ui->dateEdit->date().day();
    start_time.tm_mon = ui->dateEdit->date().month();
    start_time.tm_year = ui->dateEdit->date().year();
    end_time.tm_mday = ui->dateEdit_2->date().day();
    end_time.tm_mon = ui->dateEdit_2->date().month();
    end_time.tm_year = ui->dateEdit_2->date().year();
    ui->linetinhtong->setText(QString::number(cost_sum(m_Hopdong, start_time, end_time)));

    // Son code ham tinh tong doanh thu theo thoi gian di:
    //unsigned int tinhtong(std::vector<Hopdong*> &m_Hopdong, struct tm start_time, struct tm end_time)
}




void MainWindow::on_btnsua_released()
{
    m_Hopdong[STT]->hoten = ui->linehoten->text().toStdString();
    m_Hopdong[STT]->cmt = ui->linecmt->text().toStdString();
    m_Hopdong[STT]->loaixe = ui->lineloaixe->text().toStdString();
    m_Hopdong[STT]->bienso = ui->linebienso->text().toStdString();
    m_Hopdong[STT]->start_time.tm_mday = ui->linengaythue->text().toInt();
    m_Hopdong[STT]->start_time.tm_mon = ui->linethangthue->text().toInt();
    m_Hopdong[STT]->start_time.tm_year = ui->linenamthue->text().toInt();
    m_Hopdong[STT]->end_time.tm_mday = ui->linengaytra->text().toInt();
    m_Hopdong[STT]->end_time.tm_mon = ui->linethangtra->text().toInt();
    m_Hopdong[STT]->end_time.tm_year = ui->linenamtra->text().toInt();

    ui->linehoten->setText("");
    ui->linecmt->setText("");
    ui->lineloaixe->setText("");
    ui->linebienso->setText("");
    ui->linengaythue->setText("");
    ui->linethangthue->setText("");
    ui->linenamthue->setText("");
    ui->linengaytra->setText("");
    ui->linethangtra->setText("");
    ui->linenamtra->setText("");
}


void MainWindow::on_btnxoa_released()
{
//    deleteHd(m_Hopdong, STT);
    //Son code lai ham deleteHd de xoa hop dong co so thu tu la STT nhe (STT chay tu 0 -> n-1)
    //void deleteHd(std::vector<Hopdong*> m_Hopdong, int STT)

    ui->linehoten->setText("");
    ui->linecmt->setText("");
    ui->lineloaixe->setText("");
    ui->linebienso->setText("");
    ui->linengaythue->setText("");
    ui->linethangthue->setText("");
    ui->linenamthue->setText("");
    ui->linengaytra->setText("");
    ui->linethangtra->setText("");
    ui->linenamtra->setText("");
}


void MainWindow::on_btnfindgiatri_released()
{

}

