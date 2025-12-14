/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QPushButton *backButton;
    QPushButton *searchIconButton;
    QLineEdit *searchLineEdit;
    QPushButton *clearSearchButton;
    QHBoxLayout *filtersLayout;
    QComboBox *categoriesComboBox;
    QComboBox *ingredientsComboBox;
    QPushButton *timeFilterButton;
    QSpacerItem *filtersSpacer;
    QPushButton *resetFiltersButton;
    QWidget *selectedFiltersWidget;
    QHBoxLayout *selectedFiltersLayout;
    QWidget *timePanel;
    QVBoxLayout *timePanelLayout;
    QHBoxLayout *timeRangeLayout;
    QLabel *timeMinLabel;
    QSlider *timeMinSlider;
    QSpinBox *timeMinSpinBox;
    QHBoxLayout *timeMaxLayout;
    QLabel *timeMaxLabel;
    QSlider *timeMaxSlider;
    QSpinBox *timeMaxSpinBox;
    QListWidget *resultsListWidget;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(927, 850);
        SearchDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #ffffff;\n"
"}\n"
"QLineEdit {\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 25px;\n"
"    padding: 14px 20px;\n"
"    font-size: 16px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #ff3333;\n"
"    background-color: white;\n"
"}\n"
"QPushButton {\n"
"    border-radius: 25px;\n"
"    padding: 12px 24px;\n"
"    font-size: 14px;\n"
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
"QPushButton#resetFiltersButton {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton#resetFiltersButton:hover {\n"
"    background-color: #ff5252;\n"
"}\n"
"QPushButton#findButton {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    font-weight: bold;\n"
""
                        "    border: none;\n"
"}\n"
"QPushButton#findButton:hover {\n"
"    background-color: #ff5252;\n"
"}\n"
"QPushButton#findButton:disabled {\n"
"    background-color: #ced4da;\n"
"    color: #6c757d;\n"
"}\n"
"QPushButton.filterChip {\n"
"    background-color: #e9ecef;\n"
"    color: #212529;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 20px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton.filterChip:hover {\n"
"    background-color: #dee2e6;\n"
"}\n"
"QPushButton.filterChip.selected {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    border-color: #ff3333;\n"
"}\n"
"QListWidget {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 0px;\n"
"    margin: 12px 20px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    min-height: 120px;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"QScrollArea {\n"
"    border: none;\n"
""
                        "    background: transparent;\n"
"}\n"
"QLabel.ingredientChip {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    padding: 6px 12px;\n"
"    font-size: 13px;\n"
"}\n"
"QLabel.ingredientChip QLabel {\n"
"    color: white;\n"
"}\n"
"QComboBox {\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 20px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"    background-color: #f8f9fa;\n"
"    min-height: 20px;\n"
"}\n"
"QComboBox:focus {\n"
"    border-color: #ff3333;\n"
"    background-color: white;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    selection-background-color: #ff3333;\n"
"    selection-color: white;\n"
"}\n"
"QSpinBox {\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    font-size: 14px;\n"
"    background-color: #f8f9fa;\n"
"    m"
                        "in-width: 70px;\n"
"}\n"
"QSpinBox:focus {\n"
"    border-color: #ff3333;\n"
"    background-color: white;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #ced4da;\n"
"    height: 8px;\n"
"    background: #e9ecef;\n"
"    border-radius: 4px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #ff3333;\n"
"    border: 2px solid white;\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    margin: -6px 0;\n"
"    border-radius: 10px;\n"
"}\n"
"QSlider::handle:horizontal:hover {\n"
"    background: #ff5252;\n"
"}"));
        mainLayout = new QVBoxLayout(SearchDialog);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        topBarLayout = new QHBoxLayout();
        topBarLayout->setSpacing(12);
        topBarLayout->setContentsMargins(20, 20, 20, 20);
        topBarLayout->setObjectName(QString::fromUtf8("topBarLayout"));
        backButton = new QPushButton(SearchDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(32, 32));

        topBarLayout->addWidget(backButton);

        searchIconButton = new QPushButton(SearchDialog);
        searchIconButton->setObjectName(QString::fromUtf8("searchIconButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchIconButton->setIcon(icon1);
        searchIconButton->setIconSize(QSize(32, 32));

        topBarLayout->addWidget(searchIconButton);

        searchLineEdit = new QLineEdit(SearchDialog);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        topBarLayout->addWidget(searchLineEdit);

        clearSearchButton = new QPushButton(SearchDialog);
        clearSearchButton->setObjectName(QString::fromUtf8("clearSearchButton"));

        topBarLayout->addWidget(clearSearchButton);


        mainLayout->addLayout(topBarLayout);

        filtersLayout = new QHBoxLayout();
        filtersLayout->setSpacing(12);
        filtersLayout->setContentsMargins(20, 20, 20, 20);
        filtersLayout->setObjectName(QString::fromUtf8("filtersLayout"));
        categoriesComboBox = new QComboBox(SearchDialog);
        categoriesComboBox->setObjectName(QString::fromUtf8("categoriesComboBox"));

        filtersLayout->addWidget(categoriesComboBox);

        ingredientsComboBox = new QComboBox(SearchDialog);
        ingredientsComboBox->setObjectName(QString::fromUtf8("ingredientsComboBox"));
        ingredientsComboBox->setEditable(true);

        filtersLayout->addWidget(ingredientsComboBox);

        timeFilterButton = new QPushButton(SearchDialog);
        timeFilterButton->setObjectName(QString::fromUtf8("timeFilterButton"));

        filtersLayout->addWidget(timeFilterButton);

        filtersSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        filtersLayout->addItem(filtersSpacer);

        resetFiltersButton = new QPushButton(SearchDialog);
        resetFiltersButton->setObjectName(QString::fromUtf8("resetFiltersButton"));

        filtersLayout->addWidget(resetFiltersButton);


        mainLayout->addLayout(filtersLayout);

        selectedFiltersWidget = new QWidget(SearchDialog);
        selectedFiltersWidget->setObjectName(QString::fromUtf8("selectedFiltersWidget"));
        selectedFiltersWidget->setMaximumHeight(80);
        selectedFiltersLayout = new QHBoxLayout(selectedFiltersWidget);
        selectedFiltersLayout->setSpacing(8);
        selectedFiltersLayout->setContentsMargins(20, 20, 20, 20);
        selectedFiltersLayout->setObjectName(QString::fromUtf8("selectedFiltersLayout"));
        selectedFiltersLayout->setContentsMargins(0, 0, 0, 0);

        mainLayout->addWidget(selectedFiltersWidget);

        timePanel = new QWidget(SearchDialog);
        timePanel->setObjectName(QString::fromUtf8("timePanel"));
        timePanel->setVisible(false);
        timePanelLayout = new QVBoxLayout(timePanel);
        timePanelLayout->setSpacing(16);
        timePanelLayout->setContentsMargins(20, 20, 20, 20);
        timePanelLayout->setObjectName(QString::fromUtf8("timePanelLayout"));
        timePanelLayout->setContentsMargins(0, 0, 0, 0);
        timeRangeLayout = new QHBoxLayout();
        timeRangeLayout->setSpacing(16);
        timeRangeLayout->setObjectName(QString::fromUtf8("timeRangeLayout"));
        timeMinLabel = new QLabel(timePanel);
        timeMinLabel->setObjectName(QString::fromUtf8("timeMinLabel"));
        timeMinLabel->setMinimumWidth(80);

        timeRangeLayout->addWidget(timeMinLabel);

        timeMinSlider = new QSlider(timePanel);
        timeMinSlider->setObjectName(QString::fromUtf8("timeMinSlider"));
        timeMinSlider->setOrientation(Qt::Horizontal);
        timeMinSlider->setMinimum(5);
        timeMinSlider->setMaximum(300);
        timeMinSlider->setValue(5);
        timeMinSlider->setTickPosition(QSlider::TicksBelow);
        timeMinSlider->setTickInterval(30);

        timeRangeLayout->addWidget(timeMinSlider);

        timeMinSpinBox = new QSpinBox(timePanel);
        timeMinSpinBox->setObjectName(QString::fromUtf8("timeMinSpinBox"));
        timeMinSpinBox->setMinimum(5);
        timeMinSpinBox->setMaximum(300);
        timeMinSpinBox->setValue(5);

        timeRangeLayout->addWidget(timeMinSpinBox);


        timePanelLayout->addLayout(timeRangeLayout);

        timeMaxLayout = new QHBoxLayout();
        timeMaxLayout->setSpacing(16);
        timeMaxLayout->setObjectName(QString::fromUtf8("timeMaxLayout"));
        timeMaxLabel = new QLabel(timePanel);
        timeMaxLabel->setObjectName(QString::fromUtf8("timeMaxLabel"));
        timeMaxLabel->setMinimumWidth(80);

        timeMaxLayout->addWidget(timeMaxLabel);

        timeMaxSlider = new QSlider(timePanel);
        timeMaxSlider->setObjectName(QString::fromUtf8("timeMaxSlider"));
        timeMaxSlider->setOrientation(Qt::Horizontal);
        timeMaxSlider->setMinimum(5);
        timeMaxSlider->setMaximum(300);
        timeMaxSlider->setValue(300);
        timeMaxSlider->setTickPosition(QSlider::TicksBelow);
        timeMaxSlider->setTickInterval(30);

        timeMaxLayout->addWidget(timeMaxSlider);

        timeMaxSpinBox = new QSpinBox(timePanel);
        timeMaxSpinBox->setObjectName(QString::fromUtf8("timeMaxSpinBox"));
        timeMaxSpinBox->setMinimum(5);
        timeMaxSpinBox->setMaximum(300);
        timeMaxSpinBox->setValue(300);

        timeMaxLayout->addWidget(timeMaxSpinBox);


        timePanelLayout->addLayout(timeMaxLayout);


        mainLayout->addWidget(timePanel);

        resultsListWidget = new QListWidget(SearchDialog);
        resultsListWidget->setObjectName(QString::fromUtf8("resultsListWidget"));

        mainLayout->addWidget(resultsListWidget);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "\320\237\320\276\320\270\321\201\320\272 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262", nullptr));
        backButton->setStyleSheet(QCoreApplication::translate("SearchDialog", "background-color: transparent; border: none;", nullptr));
        searchIconButton->setStyleSheet(QCoreApplication::translate("SearchDialog", "background-color: transparent; border: none;", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchDialog", "\320\237\320\276\320\270\321\201\320\272 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262...", nullptr));
        clearSearchButton->setText(QCoreApplication::translate("SearchDialog", "\342\234\225", nullptr));
        clearSearchButton->setStyleSheet(QCoreApplication::translate("SearchDialog", "background-color: transparent; color: #ff3333; font-size: 18px; font-weight: bold; border: none; min-width: 30px; min-height: 30px;", nullptr));
        categoriesComboBox->setPlaceholderText(QCoreApplication::translate("SearchDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        ingredientsComboBox->setPlaceholderText(QCoreApplication::translate("SearchDialog", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        timeFilterButton->setText(QCoreApplication::translate("SearchDialog", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217 \342\226\276", nullptr));
        resetFiltersButton->setText(QCoreApplication::translate("SearchDialog", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\262\321\201\320\265 \321\204\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        timeMinLabel->setText(QCoreApplication::translate("SearchDialog", "\320\236\321\202: 5 \320\274\320\270\320\275", nullptr));
        timeMinSpinBox->setSuffix(QCoreApplication::translate("SearchDialog", " \320\274\320\270\320\275", nullptr));
        timeMaxLabel->setText(QCoreApplication::translate("SearchDialog", "\320\224\320\276: 300 \320\274\320\270\320\275", nullptr));
        timeMaxSpinBox->setSuffix(QCoreApplication::translate("SearchDialog", " \320\274\320\270\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
