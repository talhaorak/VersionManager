#include "ProductInfo.h"


CProductInfo::CProductInfo()
{

}

CProductInfo::CProductInfo(const QString &sProductName, const QString &sCompanyName, const QString &sCopyright)
    :productName(sProductName),
      companyName(sCompanyName),
      copyright(sCopyright)
{

}

QString CProductInfo::ProductName() const
{
    return productName;
}

void CProductInfo::SetProductName(const QString &value)
{
    productName = value;
}

QString CProductInfo::CompanyName() const
{
    return companyName;
}

void CProductInfo::SetCompanyName(const QString &value)
{
    companyName = value;
}

QString CProductInfo::Copyright() const
{
    return copyright;
}

void CProductInfo::SetCopyright(const QString &value)
{
    copyright = value;
}

QVersionNumber CProductInfo::Version() const
{
    return version;
}

void CProductInfo::SetVersionNumber(const QVersionNumber &sVersion)
{
    version = sVersion;
}
