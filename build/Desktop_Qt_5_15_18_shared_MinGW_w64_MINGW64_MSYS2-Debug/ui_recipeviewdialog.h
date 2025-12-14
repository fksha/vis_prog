/********************************************************************************
** Form generated from reading UI file 'recipeviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEVIEWDIALOG_H
#define UI_RECIPEVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecipeViewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topBarLayout;
    QPushButton *backButton;
    QSpacerItem *topSpacer;
    QLabel *recipeTitleLabel;
    QSpacerItem *topSpacer2;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QHBoxLayout *mainContentLayout;
    QVBoxLayout *leftLayout;
    QLabel *photoLabel;
    QLabel *nameLabel;
    QLabel *timeLabel;
    QLabel *ingredientsTitleLabel;
    QListWidget *ingredientsListWidget;
    QLabel *categoryLabel;
    QSpacerItem *leftSpacer;
    QVBoxLayout *rightLayout;
    QListWidget *stepsListWidget;

    void setupUi(QDialog *RecipeViewDialog)
    {
        if (RecipeViewDialog->objectName().isEmpty())
            RecipeViewDialog->setObjectName(QString::fromUtf8("RecipeViewDialog"));
        RecipeViewDialog->resize(1000, 800);
        RecipeViewDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog { background-color: #ffffff; }\n"
"QLabel { color: #212529; }\n"
"QLabel#nameLabel {\n"
"    font-weight: bold;\n"
"    font-size: 24px;\n"
"    color: #212529;\n"
"}\n"
"QLabel#timeLabel, QLabel#categoryLabel {\n"
"    font-size: 16px;\n"
"    color: #666;\n"
"}\n"
"QLabel#ingredientsTitleLabel, QLabel#stepsTitleLabel {\n"
"    font-weight: bold;\n"
"    font-size: 18px;\n"
"    color: #212529;\n"
"}\n"
"QPushButton#backButton, QPushButton#deleteButton, QPushButton#editButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton#backButton:hover, QPushButton#deleteButton:hover, QPushButton#editButton:hover {\n"
"    background-color: #f8f9fa;\n"
"    border-radius: 8px;\n"
"}\n"
"QListWidget#ingredientsListWidget, QListWidget#stepsListWidget {\n"
"    border: 1px solid #e9ecef;\n"
"    border-radius: 12px;\n"
"    background-color: #f8f9fa;\n"
"    padding: 10px;\n"
"}\n"
"QListWidget#ingredientsListWidget::item {\n"
"    padding: 4px 8px;\n"
"    ma"
                        "rgin: 2px 0;\n"
"    background: white;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"    min-height: 24px;\n"
"}\n"
"QListWidget#stepsListWidget::item {\n"
"    padding: 12px;\n"
"    margin: 4px 0;\n"
"    background: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #e9ecef;\n"
"}\n"
"QListWidget#stepsListWidget::item {\n"
"    margin-bottom: 12px;\n"
"    min-height: 80px;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(RecipeViewDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topBarLayout = new QHBoxLayout();
        topBarLayout->setSpacing(10);
        topBarLayout->setContentsMargins(20, 20, 20, 20);
        topBarLayout->setObjectName(QString::fromUtf8("topBarLayout"));
        backButton = new QPushButton(RecipeViewDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(32, 32));

        topBarLayout->addWidget(backButton);

        topSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBarLayout->addItem(topSpacer);

        recipeTitleLabel = new QLabel(RecipeViewDialog);
        recipeTitleLabel->setObjectName(QString::fromUtf8("recipeTitleLabel"));
        recipeTitleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #212529;"));

        topBarLayout->addWidget(recipeTitleLabel);

        topSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBarLayout->addItem(topSpacer2);

        deleteButton = new QPushButton(RecipeViewDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/free.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(28, 28));

        topBarLayout->addWidget(deleteButton);

        editButton = new QPushButton(RecipeViewDialog);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(28, 28));

        topBarLayout->addWidget(editButton);


        verticalLayout->addLayout(topBarLayout);

        mainContentLayout = new QHBoxLayout();
        mainContentLayout->setSpacing(30);
        mainContentLayout->setContentsMargins(20, 20, 20, 20);
        mainContentLayout->setObjectName(QString::fromUtf8("mainContentLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(20);
#ifndef Q_OS_MAC
        leftLayout->setContentsMargins(0, 0, 0, 0);
#endif
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        photoLabel = new QLabel(RecipeViewDialog);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(300, 300));
        photoLabel->setMaximumSize(QSize(300, 300));
        photoLabel->setStyleSheet(QString::fromUtf8("border-radius: 20px; background-color: #f8f9fa;"));
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setScaledContents(true);

        leftLayout->addWidget(photoLabel);

        nameLabel = new QLabel(RecipeViewDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        leftLayout->addWidget(nameLabel);

        timeLabel = new QLabel(RecipeViewDialog);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        leftLayout->addWidget(timeLabel);

        ingredientsTitleLabel = new QLabel(RecipeViewDialog);
        ingredientsTitleLabel->setObjectName(QString::fromUtf8("ingredientsTitleLabel"));

        leftLayout->addWidget(ingredientsTitleLabel);

        ingredientsListWidget = new QListWidget(RecipeViewDialog);
        ingredientsListWidget->setObjectName(QString::fromUtf8("ingredientsListWidget"));
        ingredientsListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ingredientsListWidget->setSpacing(2);

        leftLayout->addWidget(ingredientsListWidget);

        categoryLabel = new QLabel(RecipeViewDialog);
        categoryLabel->setObjectName(QString::fromUtf8("categoryLabel"));

        leftLayout->addWidget(categoryLabel);

        leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        leftLayout->addItem(leftSpacer);


        mainContentLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(20);
        rightLayout->setContentsMargins(0, 0, 0, 0);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        stepsListWidget = new QListWidget(RecipeViewDialog);
        stepsListWidget->setObjectName(QString::fromUtf8("stepsListWidget"));
        stepsListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        rightLayout->addWidget(stepsListWidget);


        mainContentLayout->addLayout(rightLayout);


        verticalLayout->addLayout(mainContentLayout);


        retranslateUi(RecipeViewDialog);
        QObject::connect(backButton, SIGNAL(clicked()), RecipeViewDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RecipeViewDialog);
    } // setupUi

    void retranslateUi(QDialog *RecipeViewDialog)
    {
        RecipeViewDialog->setWindowTitle(QCoreApplication::translate("RecipeViewDialog", "\320\240\320\265\321\206\320\265\320\277\321\202", nullptr));
        recipeTitleLabel->setText(QCoreApplication::translate("RecipeViewDialog", "\320\240\320\265\321\206\320\265\320\277\321\202", nullptr));
        nameLabel->setText(QCoreApplication::translate("RecipeViewDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        timeLabel->setText(QCoreApplication::translate("RecipeViewDialog", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217: 0 \320\274\320\270\320\275\321\203\321\202", nullptr));
        ingredientsTitleLabel->setText(QCoreApplication::translate("RecipeViewDialog", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213:", nullptr));
        categoryLabel->setText(QCoreApplication::translate("RecipeViewDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecipeViewDialog: public Ui_RecipeViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEVIEWDIALOG_H
