#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include "music.h"
#include <QWidget>

namespace Ui {
class ListItemBox;
}

class ListItemBox : public QWidget
{
    Q_OBJECT

public:
    explicit ListItemBox(QWidget *parent = nullptr);
    ~ListItemBox();

    void setMusicName(const QString &);
    void setMusicSinger(const QString &);
    void setMusicAlbum(const QString &);
    void setLikeMusic(bool islike);
    void setMusic(const Music*);


signals:
    void likeStatusChanged(bool);

private slots:
    void on_likeBtn_clicked();

private:
    Ui::ListItemBox *ui;
    bool isLike;
};

#endif // LISTITEMBOX_H
