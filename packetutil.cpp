#include "packetutil.h"
#include "ui_packetutil.h"

PacketUtil::PacketUtil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PacketUtil)
{
    ui->setupUi(this);
    PrintDevList();
}

PacketUtil::~PacketUtil()
{
    delete ui;
}

void PacketUtil::PrintDevList() {

    pcap_if_t *alldevs; // device list
    pcap_if_t *d; // for_loop_variable
    char errbuf[PCAP_ERRBUF_SIZE];

    if(pcap_findalldevs(&alldevs,errbuf) == PCAP_ERROR) {
        //QDebug() << "PCAP findalldevs Error : " << errbuf;
        QMessageBox::information(NULL,"ERROR", "pcap_findalldevs error");
        close();
    }

    else {
        for (d = alldevs; d; d = d->next)
        {
            ui->listWidget->addItem(d->name);
        }
    }

}

void PacketUtil::on_OkDeviceSelect_clicked(QAbstractButton *button)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    QPushButton* OkButton = (QPushButton*)button;
    if(OkButton == ui->OkDeviceSelect->button(QDialogButtonBox::Ok)) {
        QListWidgetItem *Devitem = ui->listWidget->currentItem();
        const char *Dev = Devitem->text().toStdString().c_str();
        DeviceHandle = pcap_open_live(Dev,65536,1,-1,errbuf);
        close();
    }

    else
        return ;
}

