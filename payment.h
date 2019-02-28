#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>
#include <QCompleter>

namespace Ui {
class Payment;
}

class Payment : public QWidget
{
    Q_OBJECT

public:


    enum PreView_FontSize
    {
        PreViewFontSize_SMALL = 10 ,     /**< Small Font - 38 char */
        PreViewFontSize_MEDIUM = 12,     /**< Medium Font - 32 char */
        PreViewFontSize_BIG = 14         /**< Big Font - 27 char*/
    };

    /**
    * This enum type is used to specify the printing font style.
    */
    enum PreView_FontStyle
    {
        PreViewFontStyle_REGULAR ,   /**< unstyled text. */
        PreViewFontStyle_BOLD ,      /**< boldness the text. */
        PreViewFontStyle_ITALIC     /**< representing italicized text. */
        //            PreViewFontStyle_BOLDITALIC  /**< combine with bold and italic text. */
    };

    /**
    * This enum type is used to specify the alignment of printing data.
    */
    enum PreView_Alignment
    {
        PreViewAlignment_LEFT ,      /**< Aligns with the left. */
        PreViewAlignment_CENTER ,    /**< Align with center. */
        PreViewAlignment_RIGHT       /**< Aligns with the right. */
    };


    void addPreViewData(const QString &r_const_strDATA,
                        PreView_FontSize preview_FontSize = PreViewFontSize_MEDIUM,
                        PreView_FontStyle preview_FontStyle = PreViewFontStyle_REGULAR,
                        PreView_Alignment preview_Align = PreViewAlignment_LEFT,
                        bool bUnderLine = false);




    QCompleter *cmpter,*cmpter1,*cmpter2,*cmpter3,*cmpter4,*cmpter5;
    QStringList lst_customer_name,lst_customer_mobile,lst_vehicle_number,lst_broker_name;
    QString selected_cus_name,selected_cus_mobile,selected_cus_balance,selected_cus_balance_type,selected_cus_id,final_total;
    QString selected_vehicle_number_id,selected_vehicle_number,selected_vehicle_name,selected_vehicle_type,selected_vehicle_type_name,selected_vehicle_length,selected_vehicle_length_inch,selected_vehicle_width,selected_vehicle_width_inch,selected_vehicle_height,selected_vehicle_height_inche;
    QString final_bal_type;

    QString selected_bunk_id,selected_bunk_name,selected_bunk_balance,selected_bunk_balance_type,final_deisel_amt;
    QString selected_labour_name,selected_labour_type,selected_labour_balance,selected_labour_balance_type,final_labour_amt;

    QStringList lst_bunk_name,lst_emp_name;

    bool is_payment;
    void call_Payment();

    void show_screen(int scr);

    void keyPressEvent(QKeyEvent *ke);

    void called_for_payment();

    void called_for_receipt();

    QString StringRightAlign(QString Data,int len);

    QString StringAlign(QString Data,int len);

    explicit Payment(QWidget *parent = 0);
    ~Payment();

public slots:
    void on_pushButton_Husk_clicked();

    void on_lineEdit_vehicle_number_returnPressed();

    void on_lineEdit_paid_amt_returnPressed();

    void on_pushButton_husk_payment_save_clicked();

    void on_pushButton_other_clicked();

    void on_lineEdit_diesel_bunk_name_returnPressed();

    void on_lineEdit_diesel_amount_returnPressed();

    void on_pushButton_payment_diesel_save_clicked();

    void on_pushButton_Diesel_clicked();

    void on_lineEdit_labour_bunk_name_returnPressed();

    void on_lineEdit_labour_amount_returnPressed();

    void on_pushButton_payment_labour_save_clicked();

    void on_pushButton_labour_clicked();

    void on_lineEdit_labour_name_returnPressed();

    void on_lineEdit_customer_returnPressed();

    void on_pushButton_staff_clicked();

private slots:
    void on_pushButton_print_4_clicked();

    void on_lineEdit_vehicle_number_textEdited(const QString &arg1);

    void on_lineEdit_paid_amt_textEdited(const QString &arg1);

private:
    Ui::Payment *ui;
};

#endif // PAYMENT_H
