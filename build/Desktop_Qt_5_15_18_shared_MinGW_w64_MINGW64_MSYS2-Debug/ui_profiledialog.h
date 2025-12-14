/********************************************************************************
** Form generated from reading UI file 'profiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEDIALOG_H
#define UI_PROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileDialog
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QPushButton *backButton;
    QSpacerItem *leftSpacer;
    QPushButton *saveButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *contentLayout;
    QHBoxLayout *photoLayout;
    QSpacerItem *photoLeftSpacer;
    QLabel *photoLabel;
    QSpacerItem *photoRightSpacer;
    QVBoxLayout *fieldsLayout;
    QLabel *nameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *positionLabel;
    QLineEdit *positionLineEdit;

    void setupUi(QDialog *ProfileDialog)
    {
        if (ProfileDialog->objectName().isEmpty())
            ProfileDialog->setObjectName(QString::fromUtf8("ProfileDialog"));
        ProfileDialog->resize(927, 850);
        ProfileDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #ffffff;\n"
"}\n"
"QLineEdit {\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 20px;\n"
"    padding: 12px 20px;\n"
"    font-size: 16px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #ff3333;\n"
"    background-color: white;\n"
"}\n"
"QPushButton#backButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    min-width: 45px;\n"
"    min-height: 45px;\n"
"}\n"
"QPushButton#backButton:hover {\n"
"    background-color: #f0f0f0;\n"
"    border-radius: 22px;\n"
"}\n"
"QPushButton#saveButton {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 24px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton#saveButton:hover {\n"
"    background-color: #ff5252;\n"
"}\n"
"QLabel {\n"
"    color: #212529;\n"
"}\n"
"QLabel.fieldLabel {\n"
"    color: #ff3333;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    margin"
                        "-bottom: 8px;\n"
"}"));
        mainLayout = new QVBoxLayout(ProfileDialog);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        topBarLayout = new QHBoxLayout();
        topBarLayout->setSpacing(12);
        topBarLayout->setContentsMargins(20, 20, 20, 20);
        topBarLayout->setObjectName(QString::fromUtf8("topBarLayout"));
        backButton = new QPushButton(ProfileDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(32, 32));

        topBarLayout->addWidget(backButton);

        leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBarLayout->addItem(leftSpacer);

        saveButton = new QPushButton(ProfileDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        topBarLayout->addWidget(saveButton);


        mainLayout->addLayout(topBarLayout);

        scrollArea = new QScrollArea(ProfileDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 927, 600));
        contentLayout = new QVBoxLayout(scrollAreaWidgetContents);
        contentLayout->setSpacing(30);
        contentLayout->setContentsMargins(40, 40, 40, 40);
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        photoLayout = new QHBoxLayout();
        photoLayout->setSpacing(0);
        photoLayout->setObjectName(QString::fromUtf8("photoLayout"));
        photoLeftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        photoLayout->addItem(photoLeftSpacer);

        photoLabel = new QLabel(scrollAreaWidgetContents);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(200, 200));
        photoLabel->setMaximumSize(QSize(200, 200));
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setScaledContents(true);

        photoLayout->addWidget(photoLabel);

        photoRightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        photoLayout->addItem(photoRightSpacer);


        contentLayout->addLayout(photoLayout);

        fieldsLayout = new QVBoxLayout();
        fieldsLayout->setSpacing(20);
        fieldsLayout->setObjectName(QString::fromUtf8("fieldsLayout"));
        nameLabel = new QLabel(scrollAreaWidgetContents);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        fieldsLayout->addWidget(nameLabel);

        firstNameLineEdit = new QLineEdit(scrollAreaWidgetContents);
        firstNameLineEdit->setObjectName(QString::fromUtf8("firstNameLineEdit"));

        fieldsLayout->addWidget(firstNameLineEdit);

        lastNameLabel = new QLabel(scrollAreaWidgetContents);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        fieldsLayout->addWidget(lastNameLabel);

        lastNameLineEdit = new QLineEdit(scrollAreaWidgetContents);
        lastNameLineEdit->setObjectName(QString::fromUtf8("lastNameLineEdit"));

        fieldsLayout->addWidget(lastNameLineEdit);

        positionLabel = new QLabel(scrollAreaWidgetContents);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));

        fieldsLayout->addWidget(positionLabel);

        positionLineEdit = new QLineEdit(scrollAreaWidgetContents);
        positionLineEdit->setObjectName(QString::fromUtf8("positionLineEdit"));

        fieldsLayout->addWidget(positionLineEdit);


        contentLayout->addLayout(fieldsLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);


        retranslateUi(ProfileDialog);

        QMetaObject::connectSlotsByName(ProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *ProfileDialog)
    {
        ProfileDialog->setWindowTitle(QCoreApplication::translate("ProfileDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\321\204\320\270\320\273\321\217", nullptr));
        saveButton->setText(QCoreApplication::translate("ProfileDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        photoLabel->setStyleSheet(QCoreApplication::translate("ProfileDialog", "border: 2px dashed #ced4da; border-radius: 100px; background-color: #f8f9fa;", nullptr));
        photoLabel->setText(QCoreApplication::translate("ProfileDialog", "\360\237\221\244", nullptr));
        nameLabel->setText(QCoreApplication::translate("ProfileDialog", "\320\230\320\274\321\217:", nullptr));
        nameLabel->setStyleSheet(QCoreApplication::translate("ProfileDialog", "color: #ff3333; font-weight: bold; font-size: 14px; margin-bottom: 8px;", nullptr));
        firstNameLineEdit->setPlaceholderText(QCoreApplication::translate("ProfileDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210\320\265 \320\270\320\274\321\217...", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("ProfileDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        lastNameLabel->setStyleSheet(QCoreApplication::translate("ProfileDialog", "color: #ff3333; font-weight: bold; font-size: 14px; margin-bottom: 8px;", nullptr));
        lastNameLineEdit->setPlaceholderText(QCoreApplication::translate("ProfileDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210\321\203 \321\204\320\260\320\274\320\270\320\273\320\270\321\216...", nullptr));
        positionLabel->setText(QCoreApplication::translate("ProfileDialog", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        positionLabel->setStyleSheet(QCoreApplication::translate("ProfileDialog", "color: #ff3333; font-weight: bold; font-size: 14px; margin-bottom: 8px;", nullptr));
        positionLineEdit->setPlaceholderText(QCoreApplication::translate("ProfileDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210\321\203 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileDialog: public Ui_ProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEDIALOG_H
