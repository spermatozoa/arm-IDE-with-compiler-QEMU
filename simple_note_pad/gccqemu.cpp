#include "gccqemu.h"

gccQEMU::gccQEMU()
{
    QProcess::connect(&m_process, &QProcess::errorOccurred, this, &gccQEMU::errorOccurred);
    QProcess::connect(&m_process, &QProcess::finished, this, &gccQEMU::finished);
    QProcess::connect(&m_process, &QProcess::readyReadStandardError, this, &gccQEMU::readyReadStandardError);
    QProcess::connect(&m_process, &QProcess::readyReadStandardOutput, this, &gccQEMU::readyReadStandardOutput);
    QProcess::connect(&m_process, &QProcess::started, this, &gccQEMU::started);
    QProcess::connect(&m_process, &QProcess::stateChanged, this, &gccQEMU::stateChanged);

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    m_process.setProcessEnvironment(env);
//    m_process.start("bash");
}

gccQEMU::~gccQEMU()
{
    closeProcess();
}

QString gccQEMU::getOS()
{
    return QSysInfo::prettyProductName();
}

bool gccQEMU::startProcess()
{
    qInfo() << Q_FUNC_INFO;

//    m_process.start(getProcess());

//    if(m_process.waitForStarted(15000)){
//        if(getProcess() == "bash")
//            m_process.write("source ~/.bashrc\n");
//        return true;
//    }

    //false if exceed time limit 15 secs
    return true;
}

bool gccQEMU::closeProcess()
{
    qInfo() << Q_FUNC_INFO;
//    m_process.write("exit\n");
    //false if can't finish in 15 secs
    if(!m_process.waitForFinished(15000)){
        return false;
    }

    m_process.close();
    qInfo() << "close process and return true";
    return true;
}

void gccQEMU::Compile(QStringList cPath)
{
    qInfo() << Q_FUNC_INFO;
    QString compiler = "arm-none-eabi";

    //get absolutely path
    if(cPath.isEmpty()){
        Path = "";
        return;
    }
    else{
        qsizetype i;
        Path = cPath[0];
        for(i = Path.size() - 1; i >= 0 ; i--){
            if(Path.at(i) == '/'){
                Path.truncate(i + 1);
                qInfo() << "Path is: " << Path;
                break;
            }
        }
    }

    //%.c to %.o
    QStringList oPath;
    for(int i = 0; i < cPath.size(); i++){
        QString p  = cPath[i];
        oPath.append(p.replace(cPath[i].size()-1, 1, "o"));
        QString cmd = compiler + "-gcc -c -g " + cPath[i] + " -o " + oPath[i] + " -Wno-int-conversion";
        m_process.startCommand(cmd);
        m_process.waitForFinished();
    }

    //test.elf
    QString makeELF = compiler + "-ld -T " + machine_name + ".ld " + machine_name + "_startup.o ";
    for(int i = 0; i < oPath.size(); i++){
        makeELF.append(oPath[i] + " ");
    }
    makeELF.append("-o test.elf");
    m_process.startCommand(makeELF);
    m_process.waitForFinished();

    //test.bin
//    qInfo() << "start makeBIN";
//    QString makeBIN = compiler + "-objcopy -O binary test.elf test.bin";
//    m_process.startCommand(makeBIN);
//    m_process.waitForFinished();

}

void gccQEMU::Emulate()
{
    qInfo() << Q_FUNC_INFO;

    emit outputLog("QEMU emulatiing....................");

    //QEMU emulation
    QString text = "/opt/qemu-system-arm/bin/qemu-system-arm -M "+ machine_name +" -m " + QString::number(ram_size) +"M -nographic -kernel test.elf";
    m_process.startCommand(text);

}

void gccQEMU::test(QString q)
{
    qInfo() << Q_FUNC_INFO << q;
//    emit outputLog(QProcessEnvironment::systemEnvironment().value("PATH", "path not found!"));
//    q += "\n";
//    if(m_process.waitForFinished(15000)){
        m_process.startCommand(q);
//    }
        //    m_process.write("ping 127.0.0.1 -c 3\n");
}

void gccQEMU::Terminate()
{
    m_process.terminate();
    if(m_process.waitForFinished(15000)){
        emit outputLog("process sucessfully terminated");
    }
    else{
        emit outputLog("process error");
    }
}

void gccQEMU::changeMachine(QString M)
{
    machine_name = M;
}

void gccQEMU::changeRam(int size)
{
    ram_size = size;
}

void gccQEMU::errorOccurred(QProcess::ProcessError error)
{
    qInfo() << Q_FUNC_INFO << error;
    emit outputLog("Error");
}

void gccQEMU::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
//    emit outputLog("Complete");
}

void gccQEMU::readyReadStandardError()
{
    qInfo() << Q_FUNC_INFO;
    QByteArray data = m_process.readAllStandardError();
    QString msg = "Standard Error: ";
    msg.append(data);
    emit outputLog(msg);
}

void gccQEMU::readyReadStandardOutput()
{
    qInfo() << Q_FUNC_INFO;
    QByteArray data = m_process.readAllStandardOutput();
//    emit outputLog(QString(data.trimmed()));
    emit outputLog(QString(data));
}

void gccQEMU::started()
{
    //Do nothing here
}

void gccQEMU::stateChanged(QProcess::ProcessState newState)
{
    qInfo() << Q_FUNC_INFO;
    switch(newState){
        case(QProcess::NotRunning):
//            readAllStandardOutput
            qInfo() << "not running";
//            emit outputLog("Not running");
            break;
        case(QProcess::Starting):
            qInfo() << "Starting...";
//            emit outputLog("Starting...");
            break;
        case(QProcess::Running):
            qInfo() << "Running";
//            emit outputLog("Running...");
            //StartPing();
            break;
    }
}

QString gccQEMU::getProcess()
{
    if(QSysInfo::productType() == "windows") return "cmd";
    if(QSysInfo::productType() == "osx") return "/bin/zsh";

    return "bash";
}

