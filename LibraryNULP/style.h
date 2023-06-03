#ifndef STYLE_H
#define STYLE_H

#include <QString>

class style
{
public:
    style();
    QString ButtonStyle(QString border = "2px solid #8f8f91",
                        QString borderradius = "45px",
                        QString backgroundcolor = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde)",
                        QString minwidth = "80px");
};

#endif // STYLE_H
