#ifndef GCCQEMU_H
#define GCCQEMU_H

#include <QObject>
#include <QDebug>
#include <QSysInfo>
#include <QProcess>
#include <QProcessEnvironment>

class gccQEMU : public QObject
{
    Q_OBJECT
public:
    gccQEMU();
    ~gccQEMU();
    QString getOS();

signals:
    void outputLog(QString data);

public slots:
    void Compile(QStringList cPath);
    void Emulate();
    void test(QString q);
    void Terminate();
    void changeMachine(QString M);
    void changeRam(int size);

private slots:
    void errorOccurred(QProcess::ProcessError error);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
    void stateChanged(QProcess::ProcessState newState);

private:
    QProcess m_process;
    QString getProcess();
    bool startProcess();
    bool closeProcess();
    QString Path;
    int ram_size = 128;
    QString machine_name = "virt";
};

#endif // GCCQEMU_H
