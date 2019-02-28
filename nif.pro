#-------------------------------------------------
#
# Project created by QtCreator 2018-07-19T13:54:22
#
#-------------------------------------------------
#Project git
QT       += core gui sql network xml svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nif
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    downloadmanager.cpp \
    downloadmanagerFTP.cpp \
    downloadmanagerHTTP.cpp \
    global.cpp \
    login.cpp \
    menu.cpp \
    printersettings.cpp \
    server_get_post.cpp \
    settings.cpp \
    threadclass.cpp \
    home_screen.cpp \
    customer_details.cpp \
    rate_config.cpp \
    batch_close.cpp \
    add_user.cpp \
    process_selection.cpp \
    batch_configuration.cpp \
    customer_master.cpp \
    payment.cpp \
    master_config_menu.cpp \
    employeemaster.cpp \
    input_config.cpp \
    diesel_maintanance.cpp \
    expense_master.cpp \
    production_batch_close.cpp \
    day_close.cpp \
    salary_calculation.cpp \
    staff_cash.cpp \
    report.cpp \
    datatransfer.cpp \
    void_last_bill.cpp

HEADERS  += mainwindow.h \
    database.h \
    downloadmanager.h \
    downloadmanagerFTP.h \
    downloadmanagerHTTP.h \
    global.h \
    login.h \
    menu.h \
    printersettings.h \
    server_get_post.h \
    settings.h \
    threadclass.h \
    home_screen.h \
    customer_details.h \
    rate_config.h \
    batch_close.h \
    add_user.h \
    process_selection.h \
    batch_configuration.h \
    customer_master.h \
    payment.h \
    master_config_menu.h \
    employeemaster.h \
    input_config.h \
    diesel_maintanance.h \
    expense_master.h \
    production_batch_close.h \
    day_close.h \
    salary_calculation.h \
    staff_cash.h \
    report.h \
    datatransfer.h \
    void_last_bill.h

FORMS    += mainwindow.ui \
    login.ui \
    menu.ui \
    printersettings.ui \
    server_get_post.ui \
    settings.ui \
    home_screen.ui \
    customer_details.ui \
    rate_config.ui \
    batch_close.ui \
    add_user.ui \
    process_selection.ui \
    batch_configuration.ui \
    customer_master.ui \
    payment.ui \
    master_config_menu.ui \
    employeemaster.ui \
    input_config.ui \
    diesel_maintanance.ui \
    expense_master.ui \
    production_batch_close.ui \
    day_close.ui \
    salary_calculation.ui \
    staff_cash.ui \
    report.ui \
    datatransfer.ui \
    void_last_bill.ui

#################################################################################
####Change this DEFINES as SDK75/NativeCompile to compile for respective Toolchains ########

#VERSION =
#Compile=\\\"$$VERSION\\\"
#compile =
DEFINES += SDK75
#################################################################################

contains(DEFINES,SDK75) {

    message("75xx Compile")

INCLUDEPATH += /opt/poky/1.4.2/sysroots/armv5te-poky-linux-gnueabi/usr/include \
                /opt/poky/1.4.2/sysroots/armv5te-poky-linux-gnueabi/usr/include/HHC75xx \
                /opt/poky/1.4.2/sysroots/armv5te-poky-linux-gnueabi/usr/include/HHC75xx_Framework \

LIBS            += -L /opt/poky/1.4.2/sysroots/armv5te-poky-linux-gnueabi/usr/lib/ \
                    -lHHC75xx \
                    -lpcsclite \
                    -lsqlite3 \
                    -lHHC7510_Framework \
                    -lnfc_nci_linux-1
}

RESOURCES += \
    new.qrc
