#include "style.h"

style::style()
{

}

QString style::ButtonStyle(QString border, QString borderradius, QString backgroundcolor, QString minwidth)
{
    return "QPushButton {"
           "border: " + border + ";"
           "border-radius: " + borderradius + ";"
           "background-color: " + backgroundcolor + ";"
           "min-width: " + minwidth + ";"
           "}";
}
