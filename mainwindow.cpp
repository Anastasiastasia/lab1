#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
class Converter : public QWidget
{
    Q_OBJECT

public:
    Converter(QWidget *parent = nullptr) : QWidget(parent)
    {
        QLabel *inputLabel = new QLabel("Input number:", this);
        QLineEdit *inputLineEdit = new QLineEdit(this);

        QLabel *outputLabel = new QLabel("Converted number:", this);
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setReadOnly(true);

        QPushButton *convertButton = new QPushButton("Convert", this);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(inputLabel);
        layout->addWidget(inputLineEdit);
        layout->addWidget(outputLabel);
        layout->addWidget(outputLineEdit);
        layout->addWidget(convertButton);

        setLayout(layout);

        connect(convertButton, &QPushButton::clicked, [inputLineEdit, outputLineEdit]() {
            bool ok;
            qlonglong number = inputLineEdit->text().toLongLong(&ok);
            if (ok)
            {
                outputLineEdit->setText(QString::number(number, 2));
            }
            else
            {
                outputLineEdit->setText("Invalid input");
            }
        });
    }
};
MainWindow::~MainWindow()
{
    delete ui;
}
