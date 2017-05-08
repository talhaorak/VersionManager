/*
   MainWidget.h

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
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class CGenerator;

class MainWidget : public QWidget
{
    Q_OBJECT
    
    CGenerator *generator;
    void Load();
    void Save();    
    void Generator2GUI();
    void GUI2Generator();
    enum OperationModes
    {
        Create,
        Open
    };
    OperationModes operationMode = OperationModes::Create;
    void SetOperationMode(OperationModes sMode);
public:
    explicit MainWidget(CGenerator *sGenerator, QWidget *parent = 0);
    ~MainWidget();
    
private slots:
    void on_label_8_linkActivated(const QString &link);

    void on_pushButton_Save_clicked();

    void on_pushButton_Load_clicked();

    void on_pushButton_Browse_clicked();

    void on_pushButton_Generate_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
