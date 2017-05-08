/*
   ProductInfo.h

Copyright (c) 2016 Talha ORAK<talhaorak at gmail.com>
                   talhaorak.net


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CPRODUCTINFO_H
#define CPRODUCTINFO_H

#include <QString>
#include <QVersionNumber>

class CProductInfo
{
    QString productName, companyName, copyright;
    QVersionNumber version;
public:
    CProductInfo();
    CProductInfo(const QString & sProductName, const QString & sCompanyName, const QString & sCopyright=QString());

    QString ProductName() const;
    void SetProductName(const QString &value);

    QString CompanyName() const;
    void SetCompanyName(const QString &value);

    QString Copyright() const;
    void SetCopyright(const QString &value);

    QVersionNumber Version()const;
    void SetVersionNumber(const QVersionNumber & sVersion);

    inline CProductInfo& operator=(const CProductInfo & other)
    {
        productName = other.ProductName();
        companyName = other.CompanyName();
        copyright = other.Copyright();
        version = other.Version();
        return *this;
    }

    inline bool operator==(const CProductInfo & other)
    {
        return productName == other.ProductName() &&
                companyName == other.CompanyName() &&
                copyright == other.Copyright() &&
                version == other.Version();
    }
};

#endif // CPRODUCTINFO_H

