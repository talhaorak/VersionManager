/*
   Generator.h

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
#ifndef GENERATOR_H
#define GENERATOR_H

#include <QString>
#include <QList>
#include <QVersionNumber>
#include "ProductInfo.h"



class CGenerator
{    
public:
    static const QVersionNumber GeneratorVersion;


    CGenerator(const QString & sSettingsFile);

    QString SettingsFileName()const;
    QString SettingsFilePath()const;
    void SetSettingsFileName(const QString & sSettingsFile);    
    const CProductInfo & ProductInfo()const;


    // void SetProjectPath(const QString & sProjectPath);
//    void SetProductName(const QString & sProductName);
//    void SetCompanyName(const QString & sCompanyName);
//    void SetCopyright  (const QString & sCopyright);
    void SetProductInfo(const CProductInfo & other);

    void IncreaseBuildNumber();

    void CreateVersionSettings();
    void LoadVersionSettings();
    void SaveVersionSettings();
    void Generate();
    void Reset();
private:
    QString settingsFileName;
    QString settingsFilePath;
    CProductInfo productInfo;    
};

#endif // GENERATOR_H
