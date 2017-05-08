#include "mainwidget.h"
#include <QApplication>
#include "generator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    QString versionFile;
    enum LaunchModes
    {
        JustGUI,
        OpenFile,
        CreateFile,
        Increment
    };
    LaunchModes launchMode = LaunchModes::JustGUI;

    /*
      Input args:
      VersionManager (noparams) : Launch the gui
      VersionManager *.version|dir (-o): Launch the gui with the details of the version file(dir/default.version or given filename)
      VersionManager *.version|dir -e : Increment the build number in the version file(dir/default.version or given filename)
      VersionManager *.version|dir -c : Create the version file with defaults (0.1.0)(dir/default.version or given filename)
*/
    if(argc > 1)
    {
        for(int i=1; i<argc; i++)
        {
            QString param(argv[i]);
            if(param.at(0) == '-' && param.length() == 2)
            {
                char p = param.at(1).toLatin1();
                switch(p)
                {
                case 'o':
                    launchMode = LaunchModes::OpenFile;
                    break;
                case 'c':
                    launchMode = LaunchModes::CreateFile;
                    break;
                case 'e':
                    launchMode = LaunchModes::Increment;
                    break;                    
                }
            }
            else versionFile = param;
        }
    }

    CGenerator generator(versionFile);
    if (launchMode == LaunchModes::JustGUI || launchMode == LaunchModes::OpenFile)
    {
//        a.setStyle("Fusion");
        MainWidget w(&generator);
        w.show();
        return a.exec();
    }
    else
    {
        if(launchMode == LaunchModes::Increment)generator.IncreaseBuildNumber();
        generator.Generate();
    }

    return 0;
}
