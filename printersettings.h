#ifndef PRINTERSETTINGS_H
#define PRINTERSETTINGS_H

#include <QWidget>

namespace Ui {
class PrinterSettings;
}

class PrinterSettings : public QWidget
{
    Q_OBJECT

public:

    void call_PrinterSettings();

    void assign_printer_details();

    void Print_header_footer(bool header,bool footer);

    void show_screen(bool printerMenu,bool header_settings,bool footer_settings);

    QStringList lst_header,lst_footer,lst_header_isBold,lst_header_size,lst_footer_isBold,lst_footer_size;

    QString header_image,footer_image;

    int font_type;

    bool is_HeaderOn,isFooterOn,is_HeaderImg,isFooterImg;

    void keyPressEvent(QKeyEvent *ke);

    explicit PrinterSettings(QWidget *parent = 0);
    ~PrinterSettings();

private slots:
    void on_pushButton_font_type_clicked();

    void on_pushButton_H_on_clicked();

    void on_pushButton_H_off_clicked();

    void on_pushButton_F_on_clicked();

    void on_pushButton_F_off_clicked();

    void on_comboBox_heade_line_currentIndexChanged(int index);

    void on_comboBox_F_line_currentIndexChanged(int index);

    void on_pushButton_header_setting_clicked();

    void on_pushButton_H_save_clicked();

    void on_radioButton_H_small_clicked(bool checked);

    void on_radioButton_H_medium_clicked(bool checked);

    void on_radioButton_H_big_clicked(bool checked);

    void on_radioButton_F_small_clicked(bool checked);

    void on_radioButton_F_medium_clicked(bool checked);

    void on_radioButton_F_big_clicked(bool checked);

    void on_pushButton_footer_setting_clicked();

    void on_pushButton_F_save_clicked();

private:
    Ui::PrinterSettings *ui;
};

#endif // PRINTERSETTINGS_H
