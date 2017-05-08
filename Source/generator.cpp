#include "generator.h"
#include "version.h"
#include "ibuildaction.h"
#include "buildactions.h"
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDateTime>
#include <QResource>
#include <QDir>

const QVersionNumber CGenerator::GeneratorVersion = {Version::MAJOR, Version::MINOR, Version::BUILD};

CGenerator::CGenerator(const QString &sSettingsFile)
{
    if(!sSettingsFile.isEmpty())
        SetSettingsFileName(sSettingsFile);
}

QString CGenerator::SettingsFileName() const
{
    return settingsFileName;
}

QString CGenerator::SettingsFilePath() const
{
    return settingsFilePath;
}

void CGenerator::SetSettingsFileName(const QString &sSettingsFile)
{
    QFileInfo fi(sSettingsFile);
    if(fi.isDir())
    {
        settingsFileName = QString("%1/Default.version").arg(sSettingsFile);
        settingsFilePath = sSettingsFile;
    }
    else
    {
        settingsFilePath = fi.absolutePath();
        if(fi.completeSuffix()!="version")settingsFileName = QString("%1.version").arg(sSettingsFile);
        else settingsFileName = sSettingsFile;
    }
}

const CProductInfo &CGenerator::ProductInfo() const
{
    return productInfo;
}

void CGenerator::SetProductInfo(const CProductInfo &other)
{
    productInfo = other;
}

void CGenerator::IncreaseBuildNumber()
{
    QVersionNumber currentVersion = productInfo.Version();
    productInfo.SetVersionNumber({currentVersion.majorVersion(), currentVersion.minorVersion(), currentVersion.microVersion() + 1});
}

void CGenerator::CreateVersionSettings()
{
    QFile settingsFile(settingsFileName);
    if(!settingsFile.open(QIODevice::WriteOnly))return;
    settingsFile.write(QString("FileVersion = %1\n").arg(GeneratorVersion.toString()).toLatin1());
    settingsFile.close();
}

void CGenerator::LoadVersionSettings()
{
    QFile settingsFile(settingsFileName);
    if(!settingsFile.open(QIODevice::ReadOnly))return;
    settingsFile.setTextModeEnabled(true);
    QString line;
    QVersionNumber generatorVersion;
    //QVersionNumber productVersion; // we can't use this expression because stupid QVersionNumber class won't allow us to access segments.
    int major=0, minor=1, build=0;

    while(!settingsFile.atEnd())
    {
        line = settingsFile.readLine();
        if(line.at(0) == '#')continue;
        QStringList parts = line.split('=');
        if(parts.count() == 2)
        {
            QString key = parts.at(0).trimmed();
            QString val = parts.at(1).trimmed();
            if(key == "FileVersion")generatorVersion = QVersionNumber::fromString(val);
            else if(key == "ProductName")productInfo.SetProductName(val);
            else if(key == "CompanyName")productInfo.SetCompanyName(val);
            else if(key == "Copyright")productInfo.SetCopyright(val);
            else if(key == "Major")major = val.toInt();
            else if(key == "Minor")minor = val.toInt();
            else if(key == "Build")build = val.toInt();
        }
    }
    productInfo.SetVersionNumber({major,minor, build});
    settingsFile.close();
}

void CGenerator::SaveVersionSettings()
{
    QFile settingsFile(settingsFileName);
    if(!settingsFile.open(QIODevice::WriteOnly))return;
    settingsFile.setTextModeEnabled(true);
    QTextStream stream(&settingsFile);
    stream << QString("# %1\n").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") );
    stream << QString("FileVersion = %1\n").arg(GeneratorVersion.toString()).toLatin1();
    stream << QString("ProductName = %1\n").arg(productInfo.ProductName());
    stream << QString("CompanyName = %1\n").arg(productInfo.CompanyName());
    stream << QString("Copyright   = %1\n").arg(productInfo.Copyright());
    stream << QString("Major       = %1\n").arg(productInfo.Version().majorVersion());
    stream << QString("Minor       = %1\n").arg(productInfo.Version().minorVersion());
    stream << QString("Build       = %1\n").arg(productInfo.Version().microVersion());
    settingsFile.close();
}



void CGenerator::Generate()
{
    // LoadVersionSettings();
    // SaveVersionSettings();

    QFile headerResource(":/template/templates/proto.h");
    headerResource.open(QIODevice::ReadOnly);
    QByteArray headerContent = headerResource.readAll();
    headerResource.close();

    QString header = QString(headerContent).arg(productInfo.Version().majorVersion())
            .arg(productInfo.Version().minorVersion())
            .arg(productInfo.Version().microVersion());

    headerResource.close();
    QFile headerFile(QString("%1/version.h").arg(settingsFilePath));
    headerFile.open(QIODevice::WriteOnly);
    headerFile.write(header.toLatin1());
    headerFile.close();


    QFile rcResource(":/template/templates/resource.rc");
    rcResource.open(QIODevice::ReadOnly);
    QByteArray rcContent = rcResource.readAll();
    rcResource.close();
    QString rc = QString(rcContent)
            .arg(productInfo.Version().majorVersion())
            .arg(productInfo.Version().minorVersion())
            .arg(productInfo.Version().microVersion())
            .arg(productInfo.ProductName())
            .arg(productInfo.CompanyName())
            .arg(productInfo.Copyright());


    QFile rcFile(QString("%1/resource.rc").arg(settingsFilePath));
    rcFile.open(QIODevice::WriteOnly);
    rcFile.write(rc.toLatin1());
    rcFile.close();
}

void CGenerator::Reset()
{
    settingsFileName = settingsFilePath = QString();
    productInfo = CProductInfo();
}
