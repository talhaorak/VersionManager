#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "generator.h"
#include "AboutDialog.h"
#include "tools.h"
#include "version.h"
#include <QFileDialog>

MainWidget::MainWidget(CGenerator *sGenerator, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    generator = sGenerator;
    ui->setupUi(this);
    this->setWindowTitle( QString("VersionManager Tool v%1.%2.%3").arg(Version::MAJOR).arg(Version::MINOR).arg(Version::BUILD));
    if(!generator->SettingsFileName().isEmpty())
    {
        Load();
    }    
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_label_8_linkActivated(const QString &link)
{
    Q_UNUSED(link)
    AboutDialog dlg(this);
    dlg.exec();
}


void MainWidget::Load()
{
    generator->LoadVersionSettings();
    Generator2GUI();
}

void MainWidget::Save()
{
    GUI2Generator();
    generator->SaveVersionSettings();
}

void MainWidget::Generator2GUI()
{
    if(generator)
    {
        CProductInfo pi = generator->ProductInfo();
        ui->lineEdit_BuildNo->setText(Str(pi.Version().microVersion()));
        ui->lineEdit_CompanyName->setText(pi.CompanyName());
        ui->lineEdit_Copyright->setText(pi.Copyright());
        ui->lineEdit_MajorV->setText(Str(pi.Version().majorVersion()));
        ui->lineEdit_MinorV->setText(Str(pi.Version().minorVersion()));
        ui->lineEdit_ProductName->setText(pi.ProductName());
        ui->lineEdit_SettingsFileName->setText(generator->SettingsFileName());
    }
}

void MainWidget::GUI2Generator()
{
    if(generator)
    {        
        generator->Reset();
        generator->SetSettingsFileName(ui->lineEdit_SettingsFileName->text());

        CProductInfo pi;
        pi.SetCompanyName(ui->lineEdit_CompanyName->text());
        pi.SetCopyright(ui->lineEdit_Copyright->text());
        pi.SetProductName(ui->lineEdit_ProductName->text());

        int vMajor, vMinor, vBuild;
        vMajor = ui->lineEdit_MajorV->text().toInt();
        vMinor = ui->lineEdit_MinorV->text().toInt();
        vBuild = ui->lineEdit_BuildNo->text().toInt();
        pi.SetVersionNumber({vMajor, vMinor, vBuild});

        generator->SetProductInfo(pi);
    }
}

void MainWidget::SetOperationMode(MainWidget::OperationModes sMode)
{
    operationMode = sMode;
    if(operationMode == OperationModes::Create)
    {

    }
}

void MainWidget::on_pushButton_Save_clicked()
{
    if(ui->lineEdit_SettingsFileName->text().isEmpty())
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save settings as..");
        generator->SetSettingsFileName(filename);
        ui->lineEdit_SettingsFileName->setText(filename);
    }
    Save();
}

void MainWidget::on_pushButton_Load_clicked()
{
    generator->Reset();
    generator->SetSettingsFileName(ui->lineEdit_SettingsFileName->text());
    Load();
}

void MainWidget::on_pushButton_Browse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Choose Project directory");
    if(!dir.isNull() && !dir.isEmpty())
    {
        ui->lineEdit_SettingsFileName->setText(dir);
    }
}

void MainWidget::on_pushButton_Generate_clicked()
{
    if(generator)
    {
        generator->Generate();
    }
}
