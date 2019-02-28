#ifndef CUSTOMER_DETAILS_H
#define CUSTOMER_DETAILS_H

#include <QWidget>

namespace Ui {
class Customer_Details;
}

class Customer_Details : public QWidget
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


    QString payable_amt,paid_amt,balance,balance_type;

    bool pending_print;

    QString StringRightAlign(QString Data,int len);

    QString StringAlign(QString Data,int len);


    void call_Customer_Details();

    void save_transaction();

    //    bool eventFilter(QObject *target, QEvent *event);

    void keyPressEvent(QKeyEvent *ke);

    explicit Customer_Details(QWidget *parent = 0);
    ~Customer_Details();

private slots:
    void on_lineEdit_Excess_returnPressed();

    void on_lineEdit_paid_returnPressed();

    void on_pushButton_print_clicked();

    void on_lineEdit_Excess_textEdited(const QString &arg1);

    void on_pushButton_print_4_clicked();

private:
    Ui::Customer_Details *ui;
};

#endif // CUSTOMER_DETAILS_H
