/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGN_H
#define UI_DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Design
{
public:
    QComboBox *comboBox;
    QLabel *penWidthLabel;
    QSpinBox *spinBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *radiusLabel;
    QLineEdit *radiusInput;
    QLabel *widthLabel;
    QLineEdit *lenInput;
    QLabel *heightLabel;
    QLineEdit *widthInput;
    QHBoxLayout *horizontalLayout_2;
    QWidget *colorWidget;
    QPushButton *colorButton;
    QPushButton *applyBtn;

    void setupUi(QWidget *Design)
    {
        if (Design->objectName().isEmpty())
            Design->setObjectName(QString::fromUtf8("Design"));
        Design->resize(703, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Design->sizePolicy().hasHeightForWidth());
        Design->setSizePolicy(sizePolicy);
        Design->setAutoFillBackground(false);
        Design->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 202, 255);"));
        comboBox = new QComboBox(Design);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(400, 240, 155, 28));
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        penWidthLabel = new QLabel(Design);
        penWidthLabel->setObjectName(QString::fromUtf8("penWidthLabel"));
        penWidthLabel->setGeometry(QRect(390, 180, 261, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        penWidthLabel->setFont(font);
        spinBox = new QSpinBox(Design);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(590, 240, 44, 28));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(Design);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 28, 291, 451));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radiusLabel = new QLabel(layoutWidget);
        radiusLabel->setObjectName(QString::fromUtf8("radiusLabel"));
        radiusLabel->setFont(font);
        radiusLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(radiusLabel);

        radiusInput = new QLineEdit(layoutWidget);
        radiusInput->setObjectName(QString::fromUtf8("radiusInput"));
        radiusInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(radiusInput);

        widthLabel = new QLabel(layoutWidget);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));
        widthLabel->setFont(font);

        verticalLayout->addWidget(widthLabel);

        lenInput = new QLineEdit(layoutWidget);
        lenInput->setObjectName(QString::fromUtf8("lenInput"));
        lenInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lenInput);

        heightLabel = new QLabel(layoutWidget);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));
        heightLabel->setFont(font);

        verticalLayout->addWidget(heightLabel);

        widthInput = new QLineEdit(layoutWidget);
        widthInput->setObjectName(QString::fromUtf8("widthInput"));
        widthInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(widthInput);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        colorWidget = new QWidget(layoutWidget);
        colorWidget->setObjectName(QString::fromUtf8("colorWidget"));

        horizontalLayout_2->addWidget(colorWidget);

        colorButton = new QPushButton(layoutWidget);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(colorButton);


        verticalLayout->addLayout(horizontalLayout_2);

        applyBtn = new QPushButton(Design);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        applyBtn->setGeometry(QRect(460, 420, 111, 31));
        applyBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(Design);

        QMetaObject::connectSlotsByName(Design);
    } // setupUi

    void retranslateUi(QWidget *Design)
    {
        Design->setWindowTitle(QCoreApplication::translate("Design", "Design", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Design", "Solid line", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Design", "Dash line", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Design", "Dot line", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Design", "Dash-Dot line", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Design", "Dash-Dot-Dot line", nullptr));

        penWidthLabel->setText(QCoreApplication::translate("Design", "Choose pen style", nullptr));
        radiusLabel->setText(QCoreApplication::translate("Design", "Enter circle radius", nullptr));
        widthLabel->setText(QCoreApplication::translate("Design", "Enter rectangle length", nullptr));
        heightLabel->setText(QCoreApplication::translate("Design", "Enter rectangle width", nullptr));
        colorButton->setText(QCoreApplication::translate("Design", "Choose color", nullptr));
        applyBtn->setText(QCoreApplication::translate("Design", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Design: public Ui_Design {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGN_H
