#include "profiledialog.h"
#include "ui_profiledialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QEvent>
#include <QMouseEvent>

ProfileDialog::ProfileDialog(int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfileDialog)
    , currentUserId(userId)
    , photoPath("")
{
    ui->setupUi(this);
    loadProfileData();
    updatePhotoDisplay();
    
    // Делаем photoLabel кликабельным
    ui->photoLabel->setCursor(Qt::PointingHandCursor);
    ui->photoLabel->installEventFilter(this);
}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

bool ProfileDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (obj == ui->photoLabel) {
            on_addPhotoButton_clicked();
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

void ProfileDialog::loadProfileData()
{
    QSqlQuery query;
    query.prepare("SELECT first_name, last_name, position, photo_path FROM users WHERE id = ?");
    query.addBindValue(currentUserId);
    
    if (query.exec() && query.next()) {
        ui->firstNameLineEdit->setText(query.value(0).toString());
        ui->lastNameLineEdit->setText(query.value(1).toString());
        ui->positionLineEdit->setText(query.value(2).toString());
        
        QString savedPhotoPath = query.value(3).toString();
        if (!savedPhotoPath.isEmpty()) {
            photoPath = savedPhotoPath;
        }
    }
}

void ProfileDialog::updatePhotoDisplay()
{
    if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
        QPixmap pix(photoPath);
        ui->photoLabel->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        ui->photoLabel->setStyleSheet("border: 2px solid #ced4da; border-radius: 100px;");
    } else {
        ui->photoLabel->setText("👤");
        ui->photoLabel->setStyleSheet("border: 2px dashed #ced4da; border-radius: 100px; background-color: #f8f9fa; font-size: 80px;");
    }
}

void ProfileDialog::on_backButton_clicked()
{
    reject();
}

void ProfileDialog::on_addPhotoButton_clicked()
{
    static bool dialogOpen = false;
    if (dialogOpen) {
        return;
    }
    
    dialogOpen = true;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Выберите фото"), "",
        tr("Изображения (*.png *.jpg *.jpeg *.bmp);;Все файлы (*)"));
    dialogOpen = false;
    
    if (!fileName.isEmpty()) {
        photoPath = fileName;
        updatePhotoDisplay();
    }
}

void ProfileDialog::on_saveButton_clicked()
{
    QString firstName = ui->firstNameLineEdit->text().trimmed();
    QString lastName = ui->lastNameLineEdit->text().trimmed();
    QString position = ui->positionLineEdit->text().trimmed();
    
    // Обрабатываем фото
    QString savedPhotoPath = "";
    if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
        // Проверяем, не является ли это уже сохраненным путем
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT photo_path FROM users WHERE id = ?");
        checkQuery.addBindValue(currentUserId);
        if (checkQuery.exec() && checkQuery.next()) {
            QString oldPhotoPath = checkQuery.value(0).toString();
            if (photoPath != oldPhotoPath) {
                // Фото изменилось - копируем новое
                QDir dir;
                if (!dir.exists("photos")) {
                    dir.mkpath("photos");
                }
                QFileInfo fileInfo(photoPath);
                QString newFileName = QString("photos/profile_%1_%2.%3")
                    .arg(currentUserId)
                    .arg(QDateTime::currentDateTime().toSecsSinceEpoch())
                    .arg(fileInfo.suffix());
                
                if (QFile::copy(photoPath, newFileName)) {
                    savedPhotoPath = newFileName;
                } else {
                    savedPhotoPath = photoPath;
                }
            } else {
                // Фото не изменилось - используем старое
                savedPhotoPath = oldPhotoPath;
            }
        }
    }
    
    // Сохраняем данные профиля
    QSqlQuery query;
    query.prepare("UPDATE users SET first_name = ?, last_name = ?, position = ?, photo_path = ? WHERE id = ?");
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(position);
    query.addBindValue(savedPhotoPath);
    query.addBindValue(currentUserId);
    
    if (query.exec()) {
        accept();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить профиль: " + query.lastError().text());
    }
}

