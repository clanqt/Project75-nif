#ifndef DATATRANSFER_H
#define DATATRANSFER_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class DataTransfer;
}

class DataTransfer : public QDialog
{
    Q_OBJECT

public:

    QStringList allFiles,lstTables,lstExportAs,lstTables_import,lstTables_export;

    QString dbName,dbPath;

    bool fExport,fImport;

    bool importError;

    void writeScriptFile();

    void disableButtons();

    void enableButtons();

    void call_DataTransfer();

    void showExport();

    void showImport();

    void hideUI();

    void execProcess(QString ProcessName , QString Message);

    void keyPressEvent(QKeyEvent *ke);


    explicit DataTransfer(QWidget *parent = 0);
    ~DataTransfer();

private slots:
    void on_pushButton_upload_clicked();

    void on_pushButton_download_clicked();

    void on_pushButton_backup_clicked();

    void on_pushButton_cancel_clicked();

//    void on_pushButton_Refresh_clicked();

    void on_comboBox_db_csv_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::DataTransfer *ui;
};

#endif // DATATRANSFER_H
