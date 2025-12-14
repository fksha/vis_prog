/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedLayout *stackedLayout;
    QWidget *loginPage;
    QVBoxLayout *loginLayout;
    QSpacerItem *loginTopSpacer;
    QLabel *titleLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *statusLabel;
    QSpacerItem *loginBottomSpacer;
    QWidget *mainPage;
    QVBoxLayout *mainScreenLayout;
    QHBoxLayout *topBar;
    QToolButton *searchButton;
    QSpacerItem *leftSpacer;
    QLabel *welcomeLabel;
    QSpacerItem *rightSpacer;
    QToolButton *addRecipeButton;
    QListWidget *recipesListWidget;
    QHBoxLayout *bottomNav;
    QToolButton *navFavoritesButton;
    QToolButton *navRecipesButton;
    QToolButton *navProfileButton;
    QWidget *favoritesPage;
    QVBoxLayout *favoritesScreenLayout;
    QHBoxLayout *favoritesTopBar;
    QToolButton *favoritesSearchButton;
    QSpacerItem *favoritesLeftSpacer;
    QLabel *favoritesTitleLabel;
    QSpacerItem *favoritesRightSpacer;
    QSpacerItem *favoritesAddSpacer;
    QListWidget *favoritesListWidget;
    QHBoxLayout *favoritesBottomNav;
    QToolButton *favoritesNavFavoritesButton;
    QToolButton *favoritesNavRecipesButton;
    QToolButton *favoritesNavProfileButton;
    QWidget *profilePage;
    QVBoxLayout *profileScreenLayout;
    QHBoxLayout *profileTopBar;
    QSpacerItem *profileLeftSpacer;
    QLabel *profileTitleLabel;
    QSpacerItem *profileRightSpacer;
    QPushButton *logoutButton;
    QScrollArea *profileScrollArea;
    QWidget *profileScrollAreaWidgetContents;
    QVBoxLayout *profileContentLayout;
    QWidget *profileCardWidget;
    QVBoxLayout *profileCardLayout;
    QHBoxLayout *profileHeaderLayout;
    QLabel *profilePhotoLabel;
    QVBoxLayout *profileInfoLayout;
    QLabel *profileNameLabel;
    QLabel *profileLastNameLabel;
    QLabel *profilePositionLabel;
    QSpacerItem *profileInfoSpacer;
    QPushButton *profileEditButton;
    QHBoxLayout *profileStatsLayout;
    QToolButton *totalRecipesButton;
    QToolButton *favoritesCountButton;
    QWidget *dataManagementWidget;
    QVBoxLayout *dataManagementLayout;
    QComboBox *dataManagementComboBox;
    QHBoxLayout *profileBottomNav;
    QToolButton *profileNavFavoritesButton;
    QToolButton *profileNavRecipesButton;
    QToolButton *profileNavProfileButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(927, 850);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: #ffffff;\n"
"}\n"
"/* \320\255\320\272\321\200\320\260\320\275 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270 */\n"
"QLabel#titleLabel {\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    color: #212529;\n"
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
"QPushButton#loginButton {\n"
"    background-color: #ff3333;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"    border-radius: 25px;\n"
"    padding: 14px;\n"
"}\n"
"QPushButton#loginButton:hover {\n"
"    background-color: #ff5252;\n"
"}\n"
"QPushButton#registerButton {\n"
"    background: transparent;\n"
"    color: #6c757d;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 25px;\n"
"    padding: 12px;\n"
""
                        "    font-size: 14px;\n"
"}\n"
"QPushButton#registerButton:hover {\n"
"    background-color: #f8f9fa;\n"
"}\n"
"/* \320\223\320\273\320\260\320\262\320\275\321\213\320\271 \321\215\320\272\321\200\320\260\320\275 */\n"
"QToolButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QToolButton:hover {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QListWidget#recipesListWidget {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QListWidget#recipesListWidget::item {\n"
"    padding: 0px;\n"
"    margin: 12px 20px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    min-height: 120px;\n"
"}\n"
"QListWidget#recipesListWidget::item:selected {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"QListWidget#favoritesListWidget {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QListWidget#favoritesListWidget::item {\n"
"    padding: 0px;\n"
"    margin: 12px 20px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    min-height: 120px;\n"
""
                        "}\n"
"QListWidget#favoritesListWidget::item:selected {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"QLabel#statusLabel {\n"
"    color: #dc3545;\n"
"    font-size: 14px;\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedLayout = new QStackedLayout(centralwidget);
        stackedLayout->setObjectName(QString::fromUtf8("stackedLayout"));
        stackedLayout->setCurrentIndex(0);
        loginPage = new QWidget(centralwidget);
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        loginLayout = new QVBoxLayout(loginPage);
        loginLayout->setSpacing(20);
        loginLayout->setContentsMargins(40, 40, 40, 40);
        loginLayout->setObjectName(QString::fromUtf8("loginLayout"));
        loginLayout->setContentsMargins(0, 0, 0, 0);
        loginTopSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        loginLayout->addItem(loginTopSpacer);

        titleLabel = new QLabel(loginPage);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        loginLayout->addWidget(titleLabel);

        usernameLineEdit = new QLineEdit(loginPage);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        loginLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(loginPage);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        loginLayout->addWidget(passwordLineEdit);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        loginLayout->addWidget(loginButton);

        registerButton = new QPushButton(loginPage);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        loginLayout->addWidget(registerButton);

        statusLabel = new QLabel(loginPage);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setAlignment(Qt::AlignCenter);

        loginLayout->addWidget(statusLabel);

        loginBottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        loginLayout->addItem(loginBottomSpacer);


        stackedLayout->addWidget(loginPage);

        mainPage = new QWidget(centralwidget);
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        mainScreenLayout = new QVBoxLayout(mainPage);
        mainScreenLayout->setSpacing(0);
        mainScreenLayout->setContentsMargins(0, 0, 0, 0);
        mainScreenLayout->setObjectName(QString::fromUtf8("mainScreenLayout"));
        mainScreenLayout->setContentsMargins(0, 0, 0, 0);
        topBar = new QHBoxLayout();
        topBar->setSpacing(20);
        topBar->setContentsMargins(20, 20, 20, 20);
        topBar->setObjectName(QString::fromUtf8("topBar"));
        searchButton = new QToolButton(mainPage);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon);
        searchButton->setIconSize(QSize(45, 45));

        topBar->addWidget(searchButton);

        leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBar->addItem(leftSpacer);

        welcomeLabel = new QLabel(mainPage);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setAlignment(Qt::AlignCenter);

        topBar->addWidget(welcomeLabel);

        rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topBar->addItem(rightSpacer);

        addRecipeButton = new QToolButton(mainPage);
        addRecipeButton->setObjectName(QString::fromUtf8("addRecipeButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addRecipeButton->setIcon(icon1);
        addRecipeButton->setIconSize(QSize(56, 56));

        topBar->addWidget(addRecipeButton);


        mainScreenLayout->addLayout(topBar);

        recipesListWidget = new QListWidget(mainPage);
        recipesListWidget->setObjectName(QString::fromUtf8("recipesListWidget"));

        mainScreenLayout->addWidget(recipesListWidget);

        bottomNav = new QHBoxLayout();
        bottomNav->setSpacing(30);
        bottomNav->setObjectName(QString::fromUtf8("bottomNav"));
        navFavoritesButton = new QToolButton(mainPage);
        navFavoritesButton->setObjectName(QString::fromUtf8("navFavoritesButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/favorites.png"), QSize(), QIcon::Normal, QIcon::Off);
        navFavoritesButton->setIcon(icon2);
        navFavoritesButton->setIconSize(QSize(28, 28));
        navFavoritesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        bottomNav->addWidget(navFavoritesButton);

        navRecipesButton = new QToolButton(mainPage);
        navRecipesButton->setObjectName(QString::fromUtf8("navRecipesButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/recipes.png"), QSize(), QIcon::Normal, QIcon::Off);
        navRecipesButton->setIcon(icon3);
        navRecipesButton->setIconSize(QSize(28, 28));
        navRecipesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        bottomNav->addWidget(navRecipesButton);

        navProfileButton = new QToolButton(mainPage);
        navProfileButton->setObjectName(QString::fromUtf8("navProfileButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/profile.png"), QSize(), QIcon::Normal, QIcon::Off);
        navProfileButton->setIcon(icon4);
        navProfileButton->setIconSize(QSize(28, 28));
        navProfileButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        bottomNav->addWidget(navProfileButton);


        mainScreenLayout->addLayout(bottomNav);


        stackedLayout->addWidget(mainPage);

        favoritesPage = new QWidget(centralwidget);
        favoritesPage->setObjectName(QString::fromUtf8("favoritesPage"));
        favoritesScreenLayout = new QVBoxLayout(favoritesPage);
        favoritesScreenLayout->setSpacing(0);
        favoritesScreenLayout->setContentsMargins(0, 0, 0, 0);
        favoritesScreenLayout->setObjectName(QString::fromUtf8("favoritesScreenLayout"));
        favoritesScreenLayout->setContentsMargins(0, 0, 0, 0);
        favoritesTopBar = new QHBoxLayout();
        favoritesTopBar->setSpacing(20);
        favoritesTopBar->setContentsMargins(20, 20, 20, 20);
        favoritesTopBar->setObjectName(QString::fromUtf8("favoritesTopBar"));
        favoritesSearchButton = new QToolButton(favoritesPage);
        favoritesSearchButton->setObjectName(QString::fromUtf8("favoritesSearchButton"));
        favoritesSearchButton->setIcon(icon);
        favoritesSearchButton->setIconSize(QSize(45, 45));

        favoritesTopBar->addWidget(favoritesSearchButton);

        favoritesLeftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        favoritesTopBar->addItem(favoritesLeftSpacer);

        favoritesTitleLabel = new QLabel(favoritesPage);
        favoritesTitleLabel->setObjectName(QString::fromUtf8("favoritesTitleLabel"));
        favoritesTitleLabel->setAlignment(Qt::AlignCenter);

        favoritesTopBar->addWidget(favoritesTitleLabel);

        favoritesRightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        favoritesTopBar->addItem(favoritesRightSpacer);

        favoritesAddSpacer = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        favoritesTopBar->addItem(favoritesAddSpacer);


        favoritesScreenLayout->addLayout(favoritesTopBar);

        favoritesListWidget = new QListWidget(favoritesPage);
        favoritesListWidget->setObjectName(QString::fromUtf8("favoritesListWidget"));

        favoritesScreenLayout->addWidget(favoritesListWidget);

        favoritesBottomNav = new QHBoxLayout();
        favoritesBottomNav->setSpacing(30);
        favoritesBottomNav->setObjectName(QString::fromUtf8("favoritesBottomNav"));
        favoritesNavFavoritesButton = new QToolButton(favoritesPage);
        favoritesNavFavoritesButton->setObjectName(QString::fromUtf8("favoritesNavFavoritesButton"));
        favoritesNavFavoritesButton->setIcon(icon2);
        favoritesNavFavoritesButton->setIconSize(QSize(28, 28));
        favoritesNavFavoritesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        favoritesBottomNav->addWidget(favoritesNavFavoritesButton);

        favoritesNavRecipesButton = new QToolButton(favoritesPage);
        favoritesNavRecipesButton->setObjectName(QString::fromUtf8("favoritesNavRecipesButton"));
        favoritesNavRecipesButton->setIcon(icon3);
        favoritesNavRecipesButton->setIconSize(QSize(28, 28));
        favoritesNavRecipesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        favoritesBottomNav->addWidget(favoritesNavRecipesButton);

        favoritesNavProfileButton = new QToolButton(favoritesPage);
        favoritesNavProfileButton->setObjectName(QString::fromUtf8("favoritesNavProfileButton"));
        favoritesNavProfileButton->setIcon(icon4);
        favoritesNavProfileButton->setIconSize(QSize(28, 28));
        favoritesNavProfileButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        favoritesBottomNav->addWidget(favoritesNavProfileButton);


        favoritesScreenLayout->addLayout(favoritesBottomNav);


        stackedLayout->addWidget(favoritesPage);

        profilePage = new QWidget(centralwidget);
        profilePage->setObjectName(QString::fromUtf8("profilePage"));
        profileScreenLayout = new QVBoxLayout(profilePage);
        profileScreenLayout->setSpacing(0);
        profileScreenLayout->setContentsMargins(0, 0, 0, 0);
        profileScreenLayout->setObjectName(QString::fromUtf8("profileScreenLayout"));
        profileScreenLayout->setContentsMargins(0, 0, 0, 0);
        profileTopBar = new QHBoxLayout();
        profileTopBar->setSpacing(20);
        profileTopBar->setContentsMargins(20, 20, 20, 20);
        profileTopBar->setObjectName(QString::fromUtf8("profileTopBar"));
        profileLeftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        profileTopBar->addItem(profileLeftSpacer);

        profileTitleLabel = new QLabel(profilePage);
        profileTitleLabel->setObjectName(QString::fromUtf8("profileTitleLabel"));
        profileTitleLabel->setAlignment(Qt::AlignCenter);

        profileTopBar->addWidget(profileTitleLabel);

        profileRightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        profileTopBar->addItem(profileRightSpacer);

        logoutButton = new QPushButton(profilePage);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        profileTopBar->addWidget(logoutButton);


        profileScreenLayout->addLayout(profileTopBar);

        profileScrollArea = new QScrollArea(profilePage);
        profileScrollArea->setObjectName(QString::fromUtf8("profileScrollArea"));
        profileScrollArea->setWidgetResizable(true);
        profileScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        profileScrollAreaWidgetContents = new QWidget();
        profileScrollAreaWidgetContents->setObjectName(QString::fromUtf8("profileScrollAreaWidgetContents"));
        profileScrollAreaWidgetContents->setGeometry(QRect(0, 0, 927, 600));
        profileContentLayout = new QVBoxLayout(profileScrollAreaWidgetContents);
        profileContentLayout->setSpacing(20);
        profileContentLayout->setContentsMargins(20, 20, 20, 20);
        profileContentLayout->setObjectName(QString::fromUtf8("profileContentLayout"));
        profileCardWidget = new QWidget(profileScrollAreaWidgetContents);
        profileCardWidget->setObjectName(QString::fromUtf8("profileCardWidget"));
        profileCardLayout = new QVBoxLayout(profileCardWidget);
        profileCardLayout->setSpacing(5);
        profileCardLayout->setContentsMargins(0, 0, 0, 0);
        profileCardLayout->setObjectName(QString::fromUtf8("profileCardLayout"));
        profileCardLayout->setContentsMargins(0, 0, 0, 0);
        profileHeaderLayout = new QHBoxLayout();
        profileHeaderLayout->setSpacing(10);
        profileHeaderLayout->setObjectName(QString::fromUtf8("profileHeaderLayout"));
        profilePhotoLabel = new QLabel(profileCardWidget);
        profilePhotoLabel->setObjectName(QString::fromUtf8("profilePhotoLabel"));
        profilePhotoLabel->setMinimumSize(QSize(120, 120));
        profilePhotoLabel->setMaximumSize(QSize(120, 120));
        profilePhotoLabel->setAlignment(Qt::AlignCenter);

        profileHeaderLayout->addWidget(profilePhotoLabel);

        profileInfoLayout = new QVBoxLayout();
        profileInfoLayout->setSpacing(5);
        profileInfoLayout->setObjectName(QString::fromUtf8("profileInfoLayout"));
        profileNameLabel = new QLabel(profileCardWidget);
        profileNameLabel->setObjectName(QString::fromUtf8("profileNameLabel"));

        profileInfoLayout->addWidget(profileNameLabel);

        profileLastNameLabel = new QLabel(profileCardWidget);
        profileLastNameLabel->setObjectName(QString::fromUtf8("profileLastNameLabel"));

        profileInfoLayout->addWidget(profileLastNameLabel);

        profilePositionLabel = new QLabel(profileCardWidget);
        profilePositionLabel->setObjectName(QString::fromUtf8("profilePositionLabel"));

        profileInfoLayout->addWidget(profilePositionLabel);


        profileHeaderLayout->addLayout(profileInfoLayout);

        profileInfoSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        profileHeaderLayout->addItem(profileInfoSpacer);

        profileEditButton = new QPushButton(profileCardWidget);
        profileEditButton->setObjectName(QString::fromUtf8("profileEditButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        profileEditButton->setIcon(icon5);
        profileEditButton->setIconSize(QSize(24, 24));

        profileHeaderLayout->addWidget(profileEditButton);


        profileCardLayout->addLayout(profileHeaderLayout);

        profileStatsLayout = new QHBoxLayout();
        profileStatsLayout->setSpacing(20);
        profileStatsLayout->setObjectName(QString::fromUtf8("profileStatsLayout"));
        totalRecipesButton = new QToolButton(profileCardWidget);
        totalRecipesButton->setObjectName(QString::fromUtf8("totalRecipesButton"));
        totalRecipesButton->setIcon(icon3);
        totalRecipesButton->setIconSize(QSize(24, 24));
        totalRecipesButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        profileStatsLayout->addWidget(totalRecipesButton);

        favoritesCountButton = new QToolButton(profileCardWidget);
        favoritesCountButton->setObjectName(QString::fromUtf8("favoritesCountButton"));
        favoritesCountButton->setIcon(icon2);
        favoritesCountButton->setIconSize(QSize(24, 24));
        favoritesCountButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        profileStatsLayout->addWidget(favoritesCountButton);


        profileCardLayout->addLayout(profileStatsLayout);


        profileContentLayout->addWidget(profileCardWidget);

        dataManagementWidget = new QWidget(profileScrollAreaWidgetContents);
        dataManagementWidget->setObjectName(QString::fromUtf8("dataManagementWidget"));
        dataManagementWidget->setMinimumHeight(100);
        dataManagementWidget->setMaximumHeight(140);
        dataManagementLayout = new QVBoxLayout(dataManagementWidget);
        dataManagementLayout->setSpacing(0);
        dataManagementLayout->setObjectName(QString::fromUtf8("dataManagementLayout"));
        dataManagementLayout->setContentsMargins(0, 0, 0, 0);
        dataManagementComboBox = new QComboBox(dataManagementWidget);
        dataManagementComboBox->setObjectName(QString::fromUtf8("dataManagementComboBox"));
        dataManagementComboBox->setEditable(false);

        dataManagementLayout->addWidget(dataManagementComboBox);


        profileContentLayout->addWidget(dataManagementWidget);

        profileScrollArea->setWidget(profileScrollAreaWidgetContents);

        profileScreenLayout->addWidget(profileScrollArea);

        profileBottomNav = new QHBoxLayout();
        profileBottomNav->setSpacing(30);
        profileBottomNav->setObjectName(QString::fromUtf8("profileBottomNav"));
        profileNavFavoritesButton = new QToolButton(profilePage);
        profileNavFavoritesButton->setObjectName(QString::fromUtf8("profileNavFavoritesButton"));
        profileNavFavoritesButton->setIcon(icon2);
        profileNavFavoritesButton->setIconSize(QSize(28, 28));
        profileNavFavoritesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        profileBottomNav->addWidget(profileNavFavoritesButton);

        profileNavRecipesButton = new QToolButton(profilePage);
        profileNavRecipesButton->setObjectName(QString::fromUtf8("profileNavRecipesButton"));
        profileNavRecipesButton->setIcon(icon3);
        profileNavRecipesButton->setIconSize(QSize(28, 28));
        profileNavRecipesButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        profileBottomNav->addWidget(profileNavRecipesButton);

        profileNavProfileButton = new QToolButton(profilePage);
        profileNavProfileButton->setObjectName(QString::fromUtf8("profileNavProfileButton"));
        profileNavProfileButton->setIcon(icon4);
        profileNavProfileButton->setIconSize(QSize(28, 28));
        profileNavProfileButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        profileBottomNav->addWidget(profileNavProfileButton);


        profileScreenLayout->addLayout(profileBottomNav);


        stackedLayout->addWidget(profilePage);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\203\321\207\320\265\321\202\320\260 \320\264\320\276\320\274\320\260\321\210\320\275\320\270\321\205 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275...", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214...", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        statusLabel->setText(QString());
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
        welcomeLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 22px; font-weight: bold; color: #212529;", nullptr));
        navFavoritesButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        navRecipesButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
        navProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        favoritesTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        favoritesTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 22px; font-weight: bold; color: #212529;", nullptr));
        favoritesNavFavoritesButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        favoritesNavRecipesButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
        favoritesNavProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        profileTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        profileTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 22px; font-weight: bold; color: #212529;", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        logoutButton->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #ff3333; color: white; font-weight: bold; border-radius: 20px; padding: 10px 20px; font-size: 14px;", nullptr));
        profileCardWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: white; border-radius: 16px; padding: 10px 20px 20px 20px;", nullptr));
        profilePhotoLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #ced4da; border-radius: 80px; background-color: #f8f9fa;", nullptr));
        profilePhotoLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244", nullptr));
        profileNameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217: ", nullptr));
        profileNameLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; color: #212529; padding:0;", nullptr));
        profileLastNameLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217: ", nullptr));
        profileLastNameLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; color: #212529;padding:0;", nullptr));
        profilePositionLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214: ", nullptr));
        profilePositionLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; color: #212529;padding:0;", nullptr));
        profileEditButton->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: transparent; border: none;", nullptr));
        totalRecipesButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262: 0", nullptr));
        totalRecipesButton->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: transparent; color: #212529; font-size: 14px; text-align: left; border: none; padding: 8px;", nullptr));
        favoritesCountButton->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\274: 0", nullptr));
        favoritesCountButton->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: transparent; color: #212529; font-size: 14px; text-align: left; border: none; padding: 8px;", nullptr));
        dataManagementWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: white; border-radius: 16px; padding: 10px 20px;", nullptr));
        dataManagementComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", nullptr));
        dataManagementComboBox->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; padding: 8px;", nullptr));
        profileNavFavoritesButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        profileNavRecipesButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
        profileNavProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
