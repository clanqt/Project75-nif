#ifndef SERVER_GET_POST_H
#define SERVER_GET_POST_H

#include <QWidget>
#include <QCompleter>
#include <QNetworkAccessManager>
#include<QNetworkReply>
#include <QEventLoop>
#include <QTimerEvent>

namespace Ui {
class Server_Get_Post;
}

class Server_Get_Post : public QWidget
{
    Q_OBJECT

    public:
    explicit Server_Get_Post(QWidget *parent = 0);
    ~Server_Get_Post();

    QString content_type;


    QString str;
    QCompleter *completer;
    QStringList allFiles;
    QStringList temp_list;

    QNetworkAccessManager *networkManager_mac_reg;
    QNetworkReply *reply_server;
    QUrl url_mac_reg;

    int timerTimeout,timerId;
    QTimer *timer;

    int server_timeout(int time_out);


    void timerEvent(QTimerEvent *event);
    void startRequesttimer(QEventLoop &);
    void stopRequesttimer(QEventLoop &);

    QWidget *w;

    void http_get_requester(QString api_url);
    bool http_get_requester_success,isTimeout;

    enum ContentHeaderType
    {
        application_x_www_form_urlencoded = 1,
        application_xml = 2,
        application_json = 3
    };

    void http_post_xml_requester_from_ui(QString api_url, QString post_data, QString post_data_separator, ContentHeaderType HeaderType = application_x_www_form_urlencoded);
    void http_post_xml_requester_api(QString api_url, QStringList post_data, QString post_data_separator, ContentHeaderType HeaderType = application_x_www_form_urlencoded);

    void http_post_xml_requester_api(QString api_url, QString post_data, int HeaderType);
    bool http_post_requester_success;

    QStringList xml_child_sub_child_reader(QString server_reply,QString child_name,QString sub_child);
    QStringList xml_child_child_attributes_reader(QString server_reply, QString child_name, QStringList child_attrributes);
    QString xml_child_value_reader(QString server_reply, QString child_name);

signals:
    void read_server_reply(QString);

public slots:

    void replyFinished(QNetworkReply *);
    void ThreadSlot();




private:
    Ui::Server_Get_Post *ui;
};

#endif // SERVER_GET_POST_H
