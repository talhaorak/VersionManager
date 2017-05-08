#include "AboutDialog.h"
#include "ui_AboutDialog.h"
#include "version.h"
#include <QSysInfo>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{    
    ui->setupUi(this);        
    ui->label_Title->setText(ui->label_Title->text().arg(Version::MAJOR).arg(Version::MINOR).arg(Version::BUILD));
    ui->label_QtVersion->setText(ui->label_QtVersion->text().arg(QT_VERSION_STR).arg(QSysInfo::buildCpuArchitecture()));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
