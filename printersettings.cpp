#include "printersettings.h"
#include "ui_printersettings.h"

#include <QDebug>
#include <QInputDialog>

#include <global.h>
using namespace Global;

PrinterSettings::PrinterSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterSettings)
{
    ui->setupUi(this);

#if(NativeCompile)
    setParent(mdi,Qt::Dialog);
#endif

#if(SDK75)
    setParent(MdiArea,Qt::Dialog);
#endif
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::NoFocus);
    setFixedSize(320,240);

    font_type = 2;
    is_HeaderOn = false;
    isFooterOn = false;

}

PrinterSettings::~PrinterSettings()
{
    delete ui;
}

void PrinterSettings::call_PrinterSettings()
{
    ui->pushButton_header_setting->setFocus();
    show_screen(true,false,false);
    assign_printer_details();
}

void PrinterSettings::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key()== Qt::Key_Escape)
    {
        if(ui->groupBox_menu->isVisible())
        {
            this->hide();
            SettingsObj->show();
            SettingsObj->call_settings();
        }
        if(ui->groupBox_Header->isVisible() || ui->groupBox_footer->isVisible())
            show_screen(true,false,false);
    }
}

void PrinterSettings::show_screen(bool printerMenu, bool header_settings, bool footer_settings)
{
    if(printerMenu)
    {
        ui->groupBox_menu->show();
        ui->groupBox_menu->raise();
        ui->groupBox_menu->move(0,0);

        ui->groupBox_Header->hide();
        ui->groupBox_footer->hide();

        ui->pushButton_header_setting->setFocus();
    }
    if(header_settings)
    {
        ui->groupBox_Header->show();
        ui->groupBox_Header->raise();
        ui->groupBox_Header->move(0,0);
        ui->comboBox_heade_line->setCurrentIndex(0);

        ui->groupBox_menu->hide();
        ui->groupBox_footer->hide();

        //        if(is_HeaderOn)
        //        {
        //            on_pushButton_H_on_clicked();
        //            ui->lineEdit_header->setFocus();

        //        }
        //        else
        //        {
        //            on_pushButton_H_off_clicked();
        //            ui->pushButton_H_on->setFocus();
        //        }


    }
    if(footer_settings)
    {
        ui->groupBox_footer->show();
        ui->groupBox_footer->raise();
        ui->groupBox_footer->move(0,0);
        ui->comboBox_F_line->setCurrentIndex(0);

        ui->groupBox_menu->hide();
        ui->groupBox_Header->hide();

        ui->lineEdit_footer->setFocus();
    }
}

void PrinterSettings::assign_printer_details()
{
    font_type = 2;
    is_HeaderOn = false;
    isFooterOn = false;

    isHeaderON = is_HeaderOn;
    isFooterON = isFooterOn;

    is_HeaderImg = false;
    isFooterImg = false;

    isHeaderIMG_ON = is_HeaderImg;
    isFooterIMG_ON = isFooterImg;

    lst_header.clear();
    lst_header_isBold.clear();
    lst_header_size.clear();

    lst_footer.clear();
    lst_footer_isBold.clear();
    lst_footer_size.clear();


    QSqlQuery query;
    if(databaseObj->selectQuery("select is_header_on,is_footer_on,font_type,h_img,footer_img from printer_master",query))
    {
        if(query.next())
        {
            if(query.value(0).toInt() == 1)
            {
                is_HeaderOn = true;
            }
            if(query.value(1).toInt() == 1)
            {
                isFooterOn = true;
            }
            font_type = query.value(2).toInt();


            if(query.value(3).toInt() == 1)
            {
                is_HeaderImg = true;
            }

            if(query.value(4).toInt() == 1)
            {
                isFooterImg = true;
            }


            isHeaderON = is_HeaderOn;
            isFooterON = isFooterOn;

            isHeaderIMG_ON = is_HeaderImg;
            isFooterIMG_ON = isFooterImg;


            qDebug()<<"is_HeaderOn ===>>>"<<is_HeaderOn;
            qDebug()<<"isFooterOn ===>>>"<<isFooterOn;
            qDebug()<<"font_type ===>>>"<<font_type;
            qDebug()<<"isHeaderIMG_ON ===>>>"<<isHeaderIMG_ON;
            qDebug()<<"isFooterIMG_ON ===>>>"<<isFooterIMG_ON;
        }
        else
        {
            is_HeaderOn = false;
            isFooterOn = false;

            isHeaderON = is_HeaderOn;
            isFooterON = isFooterOn;
        }
    }
    else
    {
        is_HeaderOn = false;
        isFooterOn = false;

        isHeaderON = is_HeaderOn;
        isFooterON = isFooterOn;
    }



    if(is_HeaderOn)
    {
        query.clear();

        if(databaseObj->selectQuery("select h1, h1_size, h1_bold, h2, h2_size , h2_bold , h3 , h3_size , h3_bold, h4 , h4_size, h4_bold, h5, h5_size, h5_bold, h_img, h6, h6_size, h6_bold from printer_master",query))
        {
            if(query.next())
            {
                lst_header << query.value(0).toString();
                lst_header_size << query.value(1).toString();
                lst_header_isBold << query.value(2).toString();

                lst_header << query.value(3).toString();
                lst_header_size << query.value(4).toString();
                lst_header_isBold << query.value(5).toString();

                lst_header << query.value(6).toString();
                lst_header_size << query.value(7).toString();
                lst_header_isBold << query.value(8).toString();

                lst_header << query.value(9).toString();
                lst_header_size << query.value(10).toString();
                lst_header_isBold << query.value(11).toString();

                lst_header << query.value(12).toString();
                lst_header_size << query.value(13).toString();
                lst_header_isBold << query.value(14).toString();

                header_image = query.value(15).toString();

                lst_header << query.value(16).toString();
                lst_header_size << query.value(17).toString();
                lst_header_isBold << query.value(18).toString();


                glst_header.clear();
                gHerader_Size.clear();
                gHerader_Bold.clear();

                glst_header << lst_header;
                gHerader_Size << lst_header_size;
                gHerader_Bold << lst_header_isBold;

                qDebug()<<"lst_header ===>>>"<<lst_header;
                qDebug()<<"lst_header_size ===>>>"<<lst_header_size;
                qDebug()<<"lst_header_isBold ===>>>"<<lst_header_isBold;
                qDebug()<<"header_image ===>>>"<<header_image;
            }
        }
    }

    if(isFooterOn)
    {
        query.clear();

        if(databaseObj->selectQuery("select f1, f1_size, f1_bold, f2, f2_size, f2_bold, footer_img, f3, f3_size, f3_bold from printer_master",query))
        {
            if(query.next())
            {
                lst_footer << query.value(0).toString();
                lst_footer_size << query.value(1).toString();
                lst_footer_isBold << query.value(2).toString();

                lst_footer << query.value(3).toString();
                lst_footer_size << query.value(4).toString();
                lst_footer_isBold << query.value(5).toString();

                footer_image = query.value(6).toString();

                lst_footer << query.value(7).toString();
                lst_footer_size << query.value(8).toString();
                lst_footer_isBold << query.value(5).toString();


                glst_footer.clear();
                gFooter_Size.clear();
                gFooter_Bold.clear();

                glst_footer << lst_footer;
                gFooter_Size << lst_footer_size;
                gFooter_Bold << lst_footer_isBold;

                qDebug()<<"lst_footer ===>>>"<<lst_footer;
                qDebug()<<"lst_footer_size ===>>>"<<lst_footer_size;
                qDebug()<<"lst_footer_isBold ===>>>"<<lst_footer_isBold;
                qDebug()<<"footer_image ===>>>"<<footer_image;
            }
        }
    }
}

void PrinterSettings::Print_header_footer(bool header, bool footer)
{

#if(SDK75)
    assign_printer_details();
    CPrinter print;
    print.setFontType(CPrinter::eFontType_font2);

    if(header && is_HeaderImg)
    {
        qDebug()<<"Print_header_footer ===>>>1";
        for(int i=0;i<glst_header.size();i++)
        {
            qDebug()<<"Print_header_footer ===>>>2"<<glst_header.at(i);
            if(!glst_header.at(i).isEmpty())
            {
                qDebug()<<"Print_header_footer ===>>>2.0";
                int size,bold;
                if( gHerader_Size.at(i).toInt() == 0)
                    size = 10;
                if( gHerader_Size.at(i).toInt() == 1)
                    size = 12;
                if( gHerader_Size.at(i).toInt() == 2)
                    size = 14;

                if( gHerader_Bold.at(i).toInt() == 1)
                    bold = 75;

                qDebug()<<"Print_header_footer ===>>>2.1";
                print.addData(glst_header.at(i),size,bold,CPrinter::eAlignment_CENTER);
                qDebug()<<"Print_header_footer ===>>>2.2";
            }
        }
        if(print.print(true,true))
        {

        }
    }

    if(footer && isFooterImg)
    {
        for(int i=0;i<glst_footer.size();i++)
        {
            if(!glst_footer.at(i).isEmpty())
            {
                int size,bold;
                if( gFooter_Size.at(i).toInt() == 0)
                    size = 10;





                if( gFooter_Size.at(i).toInt() == 1)
                    size = 12;
                if( gFooter_Size.at(i).toInt() == 2)
                    size = 14;

                if( gFooter_Bold.at(i).toInt() == 1)
                    bold = 75;

                print.addData(glst_footer.at(i),size,bold,CPrinter::eAlignment_CENTER);
            }
        }
        print.addData(" ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
        print.addData(" ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
        print.addData(" ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);
        print.addData(" ",CPrinter::eFontSize_SMALL,CPrinter::eFontStyle_REGULAR,CPrinter::eAlignment_CENTER);

        if(print.print(false,true))
        {
            qDebug()<<"print returned";
        }
        qDebug()<<"print returned ===>>>1";
    }
    qDebug()<<"print returned ===>>>2";

#endif

}

void PrinterSettings::on_pushButton_font_type_clicked()
{

    QInputDialog inputDialog;
    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(11);
    font.setBold(true);
    inputDialog.setFont(font);

    QStringList items;
    items << QString("1");//Uni Space
    items << QString("2");//Bit Stream Sans Mono
    items << QString("3");//Consola

    inputDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    inputDialog.setComboBoxItems(items);
    //    inputDialog.setParent(this);
    inputDialog.setWindowTitle("Choose action");
    inputDialog.setGeometry(50,50,220,110);
    inputDialog.setWindowFlags(Qt::FramelessWindowHint);
    inputDialog.setFocus();
    bool ok;
    ok = inputDialog.exec();

    qDebug()<<"font type ===>>>"<<inputDialog.textValue()<<ok;

    if(databaseObj->executeCommand("update printer_master set font_type='"+inputDialog.textValue()+"'"))
    {
        databaseObj->con.commit();
    }



    //    if(ok && !inputDialog.textValue().isEmpty())
    //    {
    //        for(int i=0;i<items.size();i++)
    //        {
    //            if(items.at(i).contains(inputDialog.textValue().trimmed(),Qt::CaseSensitive))
    //            {

    //            }
    //        }
    //    }
}


void PrinterSettings::on_pushButton_H_on_clicked()
{
    ui->pushButton_H_on->setDisabled(true);
    ui->pushButton_H_off->setDisabled(false);
    ui->radioButton_H_small->setDisabled(true);
    ui->radioButton_H_medium->setDisabled(true);
    ui->radioButton_H_big->setDisabled(true);

    ui->checkBox_H_bold->setDisabled(true);
    ui->comboBox_heade_line->setDisabled(true);

    ui->lineEdit_header->setDisabled(true);

    //    ui->comboBox_heade_line->setCurrentIndex(0);

    if(databaseObj->executeCommand("update printer_master set is_header_on='0'"))
    {
        databaseObj->con.commit();

    }
    ui->pushButton_H_off->setFocus();

}

void PrinterSettings::on_pushButton_H_off_clicked()
{
    ui->pushButton_H_on->setDisabled(false);
    ui->pushButton_H_off->setDisabled(true);

    ui->radioButton_H_small->setDisabled(false);
    ui->radioButton_H_medium->setDisabled(false);
    ui->radioButton_H_big->setDisabled(false);

    ui->checkBox_H_bold->setDisabled(false);
    ui->comboBox_heade_line->setDisabled(false);

    ui->lineEdit_header->setDisabled(false);

    ui->comboBox_heade_line->setCurrentIndex(0);

    if(databaseObj->executeCommand("update printer_master set is_header_on='1'"))
    {
        databaseObj->con.commit();
    }
    ui->pushButton_H_off->setFocus();

}

void PrinterSettings::on_pushButton_F_on_clicked()
{
    ui->pushButton_F_on->setDisabled(true);
    ui->pushButton_F_off->setDisabled(false);

    ui->radioButton_F_small->setDisabled(true);
    ui->radioButton_F_medium->setDisabled(true);
    ui->radioButton_F_big->setDisabled(true);

    ui->checkBox_F_bold->setDisabled(true);
    ui->comboBox_F_line->setDisabled(true);

    ui->lineEdit_footer->setDisabled(true);

    ui->comboBox_F_line->setCurrentIndex(0);

    if(databaseObj->executeCommand("update printer_master set is_footer_on='0'"))
    {
        databaseObj->con.commit();
    }
}

void PrinterSettings::on_pushButton_F_off_clicked()
{
    ui->pushButton_F_on->setDisabled(false);
    ui->pushButton_F_off->setDisabled(true);

    ui->radioButton_F_small->setDisabled(false);
    ui->radioButton_F_medium->setDisabled(false);
    ui->radioButton_F_big->setDisabled(false);

    ui->checkBox_F_bold->setDisabled(false);
    ui->comboBox_F_line->setDisabled(false);

    ui->lineEdit_footer->setDisabled(false);

    ui->comboBox_F_line->setCurrentIndex(0);

    if(databaseObj->executeCommand("update printer_master set is_footer_on='1'"))
    {
        databaseObj->con.commit();
        is_HeaderOn = true;
    }
}

void PrinterSettings::on_comboBox_heade_line_currentIndexChanged(int index)
{
    qDebug()<<"on_comboBox_heade_line_currentIndexChanged ===>>>"<<QString::number(index);
    if(is_HeaderOn)
    {
        if(lst_header.size() > 0)
        {
            ui->lineEdit_header->setText(lst_header.at(index));

            if(!lst_header_isBold.at(index).isEmpty())
            {
                if(lst_header_isBold.at(index).toInt() == 0)
                    ui->checkBox_H_bold->setChecked(false);
                else
                    ui->checkBox_H_bold->setChecked(true);
            }
            else
            {
                ui->checkBox_H_bold->setChecked(false);
            }



            if(!lst_header_size.at(index).isEmpty())
            {
                if(lst_header_size.at(index).toInt() == 0)
                {
                    ui->radioButton_H_small->setChecked(true);
                    ui->label_header_char_info->setText("(38 char)");
                    ui->lineEdit_header->setMaxLength(38);
                }
                if(lst_header_size.at(index).toInt() == 1)
                {
                    ui->radioButton_H_medium->setChecked(true);
                    ui->label_header_char_info->setText("(32 char)");
                    ui->lineEdit_header->setMaxLength(32);
                }
                if(lst_header_size.at(index).toInt() == 2)
                {
                    ui->radioButton_H_big->setChecked(true);
                    ui->label_header_char_info->setText("(26 char)");
                    ui->lineEdit_header->setMaxLength(26);
                }
            }
            else
            {
                ui->radioButton_H_small->setChecked(true);
                ui->label_header_char_info->setText("(38 char)");
                ui->lineEdit_header->setMaxLength(38);
            }
        }
    }
}

void PrinterSettings::on_comboBox_F_line_currentIndexChanged(int index)
{
    qDebug()<<"on_comboBox_F_line_currentIndexChanged ===>>>";
    if(isFooterOn)
    {
        if(lst_footer.size() > 0)
        {
            ui->lineEdit_footer->setText(lst_footer.at(index));

            if(!lst_footer_isBold.at(index).isEmpty())
            {
                if(lst_footer_isBold.at(index).toInt() == 0)
                    ui->checkBox_F_bold->setChecked(false);
                else
                    ui->checkBox_F_bold->setChecked(true);
            }
            else
            {
                ui->checkBox_F_bold->setChecked(false);
            }



            if(!lst_footer_size.at(index).isEmpty())
            {
                if(lst_footer_size.at(index).toInt() == 0)
                {
                    ui->radioButton_F_small->setChecked(true);
                    ui->label_footer_char_info->setText("(38 char)");
                    ui->lineEdit_footer->setMaxLength(38);
                }
                if(lst_footer_size.at(index).toInt() == 1)
                {
                    ui->radioButton_F_medium->setChecked(true);
                    ui->label_footer_char_info->setText("(32 char)");
                    ui->lineEdit_footer->setMaxLength(32);
                }
                if(lst_header_size.at(index).toInt() == 2)
                {
                    ui->radioButton_F_big->setChecked(true);
                    ui->label_footer_char_info->setText("(26 char)");
                    ui->lineEdit_footer->setMaxLength(26);
                }
            }
            else
            {
                ui->radioButton_H_small->setChecked(true);
                ui->label_footer_char_info->setText("(38 char)");
                ui->lineEdit_footer->setMaxLength(38);
            }
        }
    }
}

void PrinterSettings::on_pushButton_header_setting_clicked()
{
    show_screen(false,true,false);
    qDebug()<<"test 1 ===>>>";
    if(is_HeaderOn)
    {
        qDebug()<<"test 2 ===>>>";
        ui->pushButton_H_on->setDisabled(false);
        ui->pushButton_H_off->setDisabled(true);

        ui->radioButton_H_small->setDisabled(false);
        ui->radioButton_H_medium->setDisabled(false);
        ui->radioButton_H_big->setDisabled(false);

        ui->checkBox_H_bold->setDisabled(false);
        ui->comboBox_heade_line->setDisabled(false);

        ui->lineEdit_header->setDisabled(false);

        ui->comboBox_heade_line->setCurrentIndex(0);
        on_comboBox_heade_line_currentIndexChanged(0);
    }
    else
    {
        qDebug()<<"test 3 ===>>>";
        ui->pushButton_H_on->setDisabled(true);
        ui->pushButton_H_off->setDisabled(false);
        ui->radioButton_H_small->setDisabled(true);
        ui->radioButton_H_medium->setDisabled(true);
        ui->radioButton_H_big->setDisabled(true);

        ui->checkBox_H_bold->setDisabled(true);
        ui->comboBox_heade_line->setDisabled(true);

        ui->lineEdit_header->setDisabled(true);
    }
}

void PrinterSettings::on_pushButton_H_save_clicked()
{
    QString font_size,bold,header_content,header_line;

    if(!ui->lineEdit_header->text().isEmpty())
    {

        if(ui->radioButton_H_small->isChecked())
            font_size = "0";
        if(ui->radioButton_H_medium->isChecked())
            font_size = "1";
        if(ui->radioButton_H_big->isChecked())
            font_size = "2";

        if(ui->checkBox_H_bold->isChecked())
            bold = "1";
        else
            bold = "0";

        header_content = ui->lineEdit_header->text().trimmed();

        header_line = ui->comboBox_heade_line->currentText().split(" ").at(1);

        if(databaseObj->executeCommand("update printer_master set h"+header_line+"='"+header_content+"',h"+header_line+"_size='"+font_size+"',h"+header_line+"_bold='"+bold+"'"))
        {
            databaseObj->con.commit();
        }
        assign_printer_details();
    }

}

void PrinterSettings::on_radioButton_H_small_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_header->setMaxLength(38);
        ui->label_header_char_info->setText("(38 char)");
        ui->lineEdit_header->setMaxLength(38);
    }
}

void PrinterSettings::on_radioButton_H_medium_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_header->setMaxLength(32);
        ui->label_header_char_info->setText("(32 char)");
        ui->lineEdit_header->setMaxLength(32);
    }
}

void PrinterSettings::on_radioButton_H_big_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_header->setMaxLength(26);
        ui->label_header_char_info->setText("(26 char)");
        ui->lineEdit_header->setMaxLength(26);
    }
}

void PrinterSettings::on_radioButton_F_small_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_footer->setMaxLength(38);
        ui->label_footer_char_info->setText("(38 char)");
        ui->lineEdit_footer->setMaxLength(38);
    }
}

void PrinterSettings::on_radioButton_F_medium_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_footer->setMaxLength(32);
        ui->label_footer_char_info->setText("(32 char)");
        ui->lineEdit_footer->setMaxLength(32);
    }
}

void PrinterSettings::on_radioButton_F_big_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_footer->setMaxLength(26);
        ui->label_footer_char_info->setText("(26 char)");
        ui->lineEdit_footer->setMaxLength(26);
    }
}

void PrinterSettings::on_pushButton_footer_setting_clicked()
{
    show_screen(false,false,true);
    if(isFooterOn){
        ui->pushButton_F_on->setDisabled(false);
        ui->pushButton_F_off->setDisabled(true);

        ui->radioButton_F_small->setDisabled(false);
        ui->radioButton_F_medium->setDisabled(false);
        ui->radioButton_F_big->setDisabled(false);

        ui->checkBox_F_bold->setDisabled(false);
        ui->comboBox_F_line->setDisabled(false);

        ui->lineEdit_footer->setDisabled(false);

        ui->comboBox_F_line->setCurrentIndex(0);
        on_comboBox_F_line_currentIndexChanged(0);
    }
    else
    {
        ui->pushButton_F_on->setDisabled(true);
        ui->pushButton_F_off->setDisabled(false);

        ui->radioButton_F_small->setDisabled(true);
        ui->radioButton_F_medium->setDisabled(true);
        ui->radioButton_F_big->setDisabled(true);

        ui->checkBox_F_bold->setDisabled(true);
        ui->comboBox_F_line->setDisabled(true);

        ui->lineEdit_footer->setDisabled(true);

        ui->comboBox_F_line->setCurrentIndex(0);
    }
}

void PrinterSettings::on_pushButton_F_save_clicked()
{
    QString font_size,bold,footer_content,footer_line;

    if(!ui->lineEdit_footer->text().isEmpty())
    {

        if(ui->radioButton_F_small->isChecked())
            font_size = "0";
        if(ui->radioButton_F_medium->isChecked())
            font_size = "1";
        if(ui->radioButton_F_big->isChecked())
            font_size = "2";

        if(ui->checkBox_F_bold->isChecked())
            bold = "1";
        else
            bold = "0";

        footer_content = ui->lineEdit_footer->text().trimmed();

        footer_line = ui->comboBox_F_line->currentText().split(" ").at(1);

        if(databaseObj->executeCommand("update printer_master set f"+footer_line+"='"+footer_content+"',f"+footer_line+"_size='"+font_size+"',f"+footer_line+"_bold='"+bold+"'"))
        {
            databaseObj->con.commit();
        }
        assign_printer_details();
    }
}
