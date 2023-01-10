#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "gccqemu.h"

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QProcess>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

signals:
    void test(QString q);
    void Compile(QStringList cPath);
    void Emulate();
    void Terminate();
    void changeMachine(QString M);
    void changeRam(int size);

private slots:
    void outputLog(QString data);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_listOpenedFile_itemDoubleClicked(QListWidgetItem *item);

    void on_rmOpenedFileButton_clicked();

    void on_listOpenedFile_itemClicked(QListWidgetItem *item);

    void on_actionAdd_source_triggered();

    void on_actionCompile_triggered();

    void on_actionRun_triggered();

    void on_pushButton_clicked();

    void on_actionStop_triggered();

    void on_actionvirt_toggled(bool arg1);

    void on_actionversatilepb_toggled(bool arg1);

    void on_actionMemory_triggered();

private:
    Ui::Notepad *ui;
    QString currentFile = "";    
    gccQEMU m_gccQEMU;
    int ram_size = 128;
//    QProcess process
};
#endif // NOTEPAD_H
