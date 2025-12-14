/********************************************************************************
** Form generated from reading UI file 'addrecipedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECIPEDIALOG_H
#define UI_ADDRECIPEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddRecipeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topBarLayout;
    QPushButton *backButton;
    QSpacerItem *topSpacer;
    QPushButton *saveButton;
    QHBoxLayout *photoInfoLayout;
    QVBoxLayout *photoLayout;
    QLabel *photoLabel;
    QPushButton *addPhotoButton;
    QVBoxLayout *nameTimeLayout;
    QLabel *labelName;
    QLineEdit *nameLineEdit;
    QLabel *labelTime;
    QHBoxLayout *timeLayout;
    QSpinBox *timeSpinBox;
    QLabel *minutesLabel;
    QSpacerItem *timeSpacer;
    QSpacerItem *nameTimeSpacer;
    QLabel *labelCategory;
    QComboBox *categoryComboBox;
    QLabel *labelIngredients;
    QHBoxLayout *ingredientLayout;
    QLineEdit *ingredientNameEdit;
    QSpinBox *ingredientQuantitySpinBox;
    QComboBox *ingredientUnitComboBox;
    QPushButton *addIngredientButton;
    QListWidget *ingredientsListWidget;
    QLabel *labelSteps;
    QLabel *currentStepLabel;
    QHBoxLayout *stepLayout;
    QTextEdit *stepDescriptionEdit;
    QPushButton *addStepButton;
    QListWidget *stepsListWidget;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *AddRecipeDialog)
    {
        if (AddRecipeDialog->objectName().isEmpty())
            AddRecipeDialog->setObjectName(QString::fromUtf8("AddRecipeDialog"));
        AddRecipeDialog->resize(600, 900);
        AddRecipeDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog { background-color: #ffffff; }\n"
"QLabel { color: #ff3333; font-size: 16px; }\n"
"QLabel#labelName, QLabel#labelTime, QLabel#labelCategory, QLabel#labelIngredients, QLabel#labelSteps, QLabel#currentStepLabel {\n"
"    font-weight: bold;\n"
"    color: #ff3333;\n"
"    font-size: 16px;\n"
"}\n"
"QLineEdit, QTextEdit {\n"
"    border: 1px solid #ced4da;\n"
"    border-radius: 25px;\n"
"    padding: 16px 20px;\n"
"    background-color: white;\n"
"    font-size: 16px;\n"
"}\n"
"QLineEdit:focus, QTextEdit:focus {\n"
"    border-color: #ff3333;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit::placeholder, QTextEdit::placeholder {\n"
"    color: #adb5bd;\n"
"}\n"
"QSpinBox {\n"
"    border: 1px solid #ced4da;\n"
"    border-radius: 25px;\n"
"    padding: 16px 20px;\n"
"    background-color: white;\n"
"    font-size: 16px;\n"
"}\n"
"QSpinBox:focus {\n"
"    border-color: #ff3333;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    border: none;\n"
"    border-radius: 0px;\n"
"    backgrou"
                        "nd: transparent;\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid #ced4da;\n"
"    border-radius: 25px;\n"
"    padding: 16px 20px;\n"
"    background-color: white;\n"
"    font-size: 16px;\n"
"}\n"
"QComboBox:focus {\n"
"    border-color: #ff3333;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    padding-right: 20px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6c757d;\n"
"    width: 0;\n"
"    height: 0;\n"
"}\n"
"QPushButton#backButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    color: #ff3333;\n"
"    font-size: 24px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton#backButton:hover {\n"
"    background-color: #f8f9fa;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton#saveButton {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 30px;\n"
"    padding: 12px 30px;\n"
"    font-size: 16px;\n"
"}\n"
""
                        "QPushButton#saveButton:hover {\n"
"    background-color: #ff2222;\n"
"}\n"
"QPushButton#addIngredientButton, QPushButton#addStepButton, QPushButton#addPhotoButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton#addIngredientButton:hover, QPushButton#addStepButton:hover, QPushButton#addPhotoButton:hover {\n"
"    background-color: #f8f9fa;\n"
"    border-radius: 8px;\n"
"}\n"
"QListWidget {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 8px;\n"
"    margin: 4px 0;\n"
"    background: white;\n"
"    border-radius: 12px;\n"
"    border: 1px solid #e9ecef;\n"
"}\n"
"QLabel#photoLabel {\n"
"    border: 2px dashed #ced4da;\n"
"    border-radius: 20px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(AddRecipeDialog);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topBarLayout = new QHBoxLayout();
        topBarLayout->setSpacing(10);
#ifndef Q_OS_MAC
        topBarLayout->setContentsMargins(0, 0, 0, 0);
#endif
        topBarLayout->setObjectName(QString::fromUtf8("topBarLayout"));
        backButton = new QPushButton(AddRecipeDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(32, 32));

        topBarLayout->addWidget(backButton);

        topSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBarLayout->addItem(topSpacer);

        saveButton = new QPushButton(AddRecipeDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        topBarLayout->addWidget(saveButton);


        verticalLayout->addLayout(topBarLayout);

        photoInfoLayout = new QHBoxLayout();
        photoInfoLayout->setSpacing(20);
        photoInfoLayout->setContentsMargins(0, 0, 0, 0);
        photoInfoLayout->setObjectName(QString::fromUtf8("photoInfoLayout"));
        photoLayout = new QVBoxLayout();
        photoLayout->setSpacing(0);
#ifndef Q_OS_MAC
        photoLayout->setContentsMargins(0, 0, 0, 0);
#endif
        photoLayout->setObjectName(QString::fromUtf8("photoLayout"));
        photoLabel = new QLabel(AddRecipeDialog);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setMinimumSize(QSize(150, 150));
        photoLabel->setMaximumSize(QSize(150, 150));
        photoLabel->setStyleSheet(QString::fromUtf8("border: 2px dashed #ced4da; border-radius: 20px; background-color: #f8f9fa;"));
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setScaledContents(true);

        photoLayout->addWidget(photoLabel);

        addPhotoButton = new QPushButton(AddRecipeDialog);
        addPhotoButton->setObjectName(QString::fromUtf8("addPhotoButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/add_photo.png"), QSize(), QIcon::Normal, QIcon::Off);
        addPhotoButton->setIcon(icon1);
        addPhotoButton->setIconSize(QSize(40, 40));

        photoLayout->addWidget(addPhotoButton);


        photoInfoLayout->addLayout(photoLayout);

        nameTimeLayout = new QVBoxLayout();
        nameTimeLayout->setSpacing(15);
        nameTimeLayout->setContentsMargins(0, 0, 0, 0);
        nameTimeLayout->setObjectName(QString::fromUtf8("nameTimeLayout"));
        labelName = new QLabel(AddRecipeDialog);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        nameTimeLayout->addWidget(labelName);

        nameLineEdit = new QLineEdit(AddRecipeDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        nameTimeLayout->addWidget(nameLineEdit);

        labelTime = new QLabel(AddRecipeDialog);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));

        nameTimeLayout->addWidget(labelTime);

        timeLayout = new QHBoxLayout();
        timeLayout->setSpacing(10);
        timeLayout->setContentsMargins(0, 0, 0, 0);
        timeLayout->setObjectName(QString::fromUtf8("timeLayout"));
        timeSpinBox = new QSpinBox(AddRecipeDialog);
        timeSpinBox->setObjectName(QString::fromUtf8("timeSpinBox"));
        timeSpinBox->setMinimum(0);
        timeSpinBox->setMaximum(9999);
        timeSpinBox->setValue(0);

        timeLayout->addWidget(timeSpinBox);

        minutesLabel = new QLabel(AddRecipeDialog);
        minutesLabel->setObjectName(QString::fromUtf8("minutesLabel"));
        minutesLabel->setStyleSheet(QString::fromUtf8("color: #212529; font-size: 16px; font-weight: normal;"));

        timeLayout->addWidget(minutesLabel);

        timeSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        timeLayout->addItem(timeSpacer);


        nameTimeLayout->addLayout(timeLayout);

        nameTimeSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        nameTimeLayout->addItem(nameTimeSpacer);


        photoInfoLayout->addLayout(nameTimeLayout);


        verticalLayout->addLayout(photoInfoLayout);

        labelCategory = new QLabel(AddRecipeDialog);
        labelCategory->setObjectName(QString::fromUtf8("labelCategory"));

        verticalLayout->addWidget(labelCategory);

        categoryComboBox = new QComboBox(AddRecipeDialog);
        categoryComboBox->setObjectName(QString::fromUtf8("categoryComboBox"));
        categoryComboBox->setEditable(false);

        verticalLayout->addWidget(categoryComboBox);

        labelIngredients = new QLabel(AddRecipeDialog);
        labelIngredients->setObjectName(QString::fromUtf8("labelIngredients"));

        verticalLayout->addWidget(labelIngredients);

        ingredientLayout = new QHBoxLayout();
        ingredientLayout->setSpacing(10);
        ingredientLayout->setContentsMargins(0, 0, 0, 0);
        ingredientLayout->setObjectName(QString::fromUtf8("ingredientLayout"));
        ingredientNameEdit = new QLineEdit(AddRecipeDialog);
        ingredientNameEdit->setObjectName(QString::fromUtf8("ingredientNameEdit"));

        ingredientLayout->addWidget(ingredientNameEdit);

        ingredientQuantitySpinBox = new QSpinBox(AddRecipeDialog);
        ingredientQuantitySpinBox->setObjectName(QString::fromUtf8("ingredientQuantitySpinBox"));
        ingredientQuantitySpinBox->setMinimum(0);
        ingredientQuantitySpinBox->setMaximum(9999);
        ingredientQuantitySpinBox->setValue(0);

        ingredientLayout->addWidget(ingredientQuantitySpinBox);

        ingredientUnitComboBox = new QComboBox(AddRecipeDialog);
        ingredientUnitComboBox->setObjectName(QString::fromUtf8("ingredientUnitComboBox"));
        ingredientUnitComboBox->setEditable(false);

        ingredientLayout->addWidget(ingredientUnitComboBox);

        addIngredientButton = new QPushButton(AddRecipeDialog);
        addIngredientButton->setObjectName(QString::fromUtf8("addIngredientButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addIngredientButton->setIcon(icon2);
        addIngredientButton->setIconSize(QSize(32, 32));

        ingredientLayout->addWidget(addIngredientButton);


        verticalLayout->addLayout(ingredientLayout);

        ingredientsListWidget = new QListWidget(AddRecipeDialog);
        ingredientsListWidget->setObjectName(QString::fromUtf8("ingredientsListWidget"));
        ingredientsListWidget->setMaximumHeight(150);

        verticalLayout->addWidget(ingredientsListWidget);

        labelSteps = new QLabel(AddRecipeDialog);
        labelSteps->setObjectName(QString::fromUtf8("labelSteps"));

        verticalLayout->addWidget(labelSteps);

        currentStepLabel = new QLabel(AddRecipeDialog);
        currentStepLabel->setObjectName(QString::fromUtf8("currentStepLabel"));

        verticalLayout->addWidget(currentStepLabel);

        stepLayout = new QHBoxLayout();
        stepLayout->setSpacing(10);
        stepLayout->setContentsMargins(0, 0, 0, 0);
        stepLayout->setObjectName(QString::fromUtf8("stepLayout"));
        stepDescriptionEdit = new QTextEdit(AddRecipeDialog);
        stepDescriptionEdit->setObjectName(QString::fromUtf8("stepDescriptionEdit"));
        stepDescriptionEdit->setMaximumHeight(100);

        stepLayout->addWidget(stepDescriptionEdit);

        addStepButton = new QPushButton(AddRecipeDialog);
        addStepButton->setObjectName(QString::fromUtf8("addStepButton"));
        addStepButton->setIcon(icon2);
        addStepButton->setIconSize(QSize(32, 32));

        stepLayout->addWidget(addStepButton);


        verticalLayout->addLayout(stepLayout);

        stepsListWidget = new QListWidget(AddRecipeDialog);
        stepsListWidget->setObjectName(QString::fromUtf8("stepsListWidget"));
        stepsListWidget->setMaximumHeight(200);

        verticalLayout->addWidget(stepsListWidget);

        bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(AddRecipeDialog);
        QObject::connect(backButton, SIGNAL(clicked()), AddRecipeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddRecipeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRecipeDialog)
    {
        AddRecipeDialog->setWindowTitle(QCoreApplication::translate("AddRecipeDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        saveButton->setText(QCoreApplication::translate("AddRecipeDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        photoLabel->setText(QString());
        labelName->setText(QCoreApplication::translate("AddRecipeDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\273\321\216\320\264\320\260:", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("AddRecipeDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\273\321\216\320\264\320\276...", nullptr));
        labelTime->setText(QCoreApplication::translate("AddRecipeDialog", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217:", nullptr));
        minutesLabel->setText(QCoreApplication::translate("AddRecipeDialog", "\320\274\320\270\320\275\321\203\321\202", nullptr));
        labelCategory->setText(QCoreApplication::translate("AddRecipeDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\261\320\273\321\216\320\264\320\260:", nullptr));
        categoryComboBox->setPlaceholderText(QCoreApplication::translate("AddRecipeDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260...", nullptr));
        labelIngredients->setText(QCoreApplication::translate("AddRecipeDialog", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213:", nullptr));
        ingredientNameEdit->setPlaceholderText(QCoreApplication::translate("AddRecipeDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\260...", nullptr));
        labelSteps->setText(QCoreApplication::translate("AddRecipeDialog", "\320\250\320\220\320\223\320\230:", nullptr));
        currentStepLabel->setText(QCoreApplication::translate("AddRecipeDialog", "\320\250\320\220\320\223 1:", nullptr));
        stepDescriptionEdit->setPlaceholderText(QCoreApplication::translate("AddRecipeDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\321\210\320\260\320\263\320\276\320\262\320\276\320\265 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217 \320\261\320\273\321\216\320\264\320\276...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRecipeDialog: public Ui_AddRecipeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECIPEDIALOG_H
