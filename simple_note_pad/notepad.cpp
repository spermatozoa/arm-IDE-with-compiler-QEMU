#include "notepad.h"
#include "./ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
//    this->setCentralWidget(ui->textEdit);
    ui->debugText->setText(QString("OS detected: ") + m_gccQEMU.getOS());

    //default use virt machine
    ui->actionvirt->setChecked(true);

    QProcess::connect(&m_gccQEMU, &gccQEMU::outputLog, this, &Notepad::outputLog);
    QProcess::connect(this, &Notepad::Compile, &m_gccQEMU, &gccQEMU::Compile);
    QProcess::connect(this, &Notepad::Emulate, &m_gccQEMU, &gccQEMU::Emulate);
    QProcess::connect(this, &Notepad::Terminate, &m_gccQEMU, &gccQEMU::Terminate);
    QProcess::connect(this, &Notepad::test, &m_gccQEMU, &gccQEMU::test);
    QProcess::connect(this, &Notepad::changeMachine, &m_gccQEMU, &gccQEMU::changeMachine);
    QProcess::connect(this, &Notepad::changeRam, &m_gccQEMU, &gccQEMU::changeRam);

}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::outputLog(QString data)
{
    qInfo() << Q_FUNC_INFO;
    ui->debugText->append(data);
}

void Notepad::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setPlainText(QString());
}


void Notepad::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Can not open file: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);

    file.close();

    // add file name to list
    ui->listOpenedFile->addItem(filename);
}


void Notepad::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Can not save file: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.close();
}


void Notepad::on_actionExit_triggered()
{
    QApplication::quit();
}


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void Notepad::on_listOpenedFile_itemDoubleClicked(QListWidgetItem *item)
{
    QString filename = item->text();
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Can not open file: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);

    file.close();
}


void Notepad::on_listOpenedFile_itemClicked(QListWidgetItem *item)
{
//    currentItem = item;
}


void Notepad::on_rmOpenedFileButton_clicked()
{
    QListWidgetItem * item = ui->listOpenedFile->currentItem();
    if(item == nullptr)
        return;

    //clear textEdit if rm current file
    if(item->text() == currentFile){
        ui->textEdit->setPlainText("");
        currentFile = "";
        setWindowTitle("");
    }

    delete item;
}


void Notepad::on_actionAdd_source_triggered()
{
    // equals to open file
    Notepad::on_actionOpen_triggered();
}


void Notepad::on_actionCompile_triggered()
{
    if(ui->listOpenedFile->count() == 0){
        QMessageBox::warning(this, "Warning", "No source file to compile");
        // let qccQEMU handle 0 file exception
    }

    QStringList cPath;
    for(int i = 0; i < ui->listOpenedFile->count(); i++){
        QString filePath =  ui->listOpenedFile->item(i)->text();
        if(filePath.contains(".ld", Qt::CaseSensitive)){
            QMessageBox::warning(this, "Warning", "Can not have custom linker script (no *.ld file) ");
            return;
        }
        else if(filePath.contains(".s", Qt::CaseSensitive)){
            QMessageBox::warning(this, "Warning", "Can not have custom startup assembly (no *.s file) ");
            return;
        }
        cPath.append(filePath);
    }

    emit Compile(cPath);
}


void Notepad::on_actionRun_triggered()
{
    //compile and run
    Notepad::on_actionCompile_triggered();

    emit Emulate();
}


void Notepad::on_pushButton_clicked()
{
    qInfo() << Q_FUNC_INFO;
    QString q = ui->testText->toPlainText();
    emit test(q);
}


void Notepad::on_actionStop_triggered()
{
    emit Terminate();
}


void Notepad::on_actionvirt_toggled(bool arg1)
{
    if(arg1){   //checked
        ui->actionversatilepb->setChecked(false);
        emit changeMachine(QString("virt"));
    }
    else{       //unchecked
        ui->actionversatilepb->setChecked(true);
        emit changeMachine(QString("versatilepb"));
    }
}


void Notepad::on_actionversatilepb_toggled(bool arg1)
{
    if(arg1){   //checked
        ui->actionvirt->setChecked(false);
        emit changeMachine(QString("versatilepb"));
    }
    else{       //unchecked
        ui->actionvirt->setChecked(true);
        emit changeMachine(QString("virt"));
    }
}


void Notepad::on_actionMemory_triggered()
{
    bool ok;
    // 131072 MB = 128 GB
    int ram = QInputDialog::getInt(this, QString("Enter RAM size"),
                                         QString("RAM size (MB):"), ram_size, 1, 131072, 1, &ok);
    if (ok){
        ram_size = ram;
        emit changeRam(ram);
    }

}

