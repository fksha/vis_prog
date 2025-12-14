#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class ProfileDialog;
}

class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(int userId, QWidget *parent = nullptr);
    ~ProfileDialog();
    
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_backButton_clicked();
    void on_saveButton_clicked();
    void on_addPhotoButton_clicked();

private:
    Ui::ProfileDialog *ui;
    int currentUserId;
    QString photoPath;
    
    void loadProfileData();
    void updatePhotoDisplay();
};

#endif // PROFILEDIALOG_H

