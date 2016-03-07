#ifndef PACKETUTIL_H
#define PACKETUTIL_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QPushButton>

#include <pcap.h>


namespace Ui {
class PacketUtil;
}

class PacketUtil : public QDialog
{
    Q_OBJECT

public:
    explicit PacketUtil(QWidget *parent = 0);
    void PrintDevList();

    void PacketOpen();
    void PacketSniff();
    void PacketSend();

    pcap_t *GetHandle() { return DeviceHandle ;}

    ~PacketUtil();

protected:
    pcap_t *DeviceHandle;


private slots:
    void on_OkDeviceSelect_clicked(QAbstractButton *button);

private:
    Ui::PacketUtil *ui;
};

#endif // PACKETUTIL_H
